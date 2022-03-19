#include "mainview.h"
#include "model.h"
#include "vertex.h"

#include <QDateTime>


/**
 * @brief MainView::MainView
 *
 * Constructor of MainView
 *
 * @param parent
 */
MainView::MainView(QWidget *parent) : QOpenGLWidget(parent) {
    qDebug() << "MainView constructor";

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
}

/**
 * @brief MainView::~MainView
 *
 * Destructor of MainView
 * This is the last function called, before exit of the program
 * Use this to clean up your variables, buffers etc.
 *
 */
MainView::~MainView() {
    qDebug() << "MainView destructor";

    makeCurrent();

    destroyModelBuffers();
}

// --- OpenGL initialization

/**
 * @brief MainView::initializeGL
 *
 * Called upon OpenGL initialization
 * Attaches a debugger and calls other init functions
 */
void MainView::initializeGL() {
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    connect(&debugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)),
            this, SLOT(onMessageLogged(QOpenGLDebugMessage)), Qt::DirectConnection);

    if (debugLogger.initialize()) {
        qDebug() << ":: Logging initialized";
        debugLogger.startLogging(QOpenGLDebugLogger::SynchronousLogging);
    }

    QString glVersion{reinterpret_cast<const char*>(glGetString(GL_VERSION))};
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable backface culling
    glEnable(GL_CULL_FACE);

    // Default is GL_LESS
    glDepthFunc(GL_LEQUAL);

    // Set the color to be used by glClear. This is, effectively, the background color.
    glClearColor(0.2F, 0.5F, 0.7F, 1.0F);

    setLight();
    createShaderPrograms();
    setShadingMode(PHONG);
    loadMesh();

    // Initialize transformations
    updateProjectionTransform();
    updateModelTransforms();
    updateNormalTransform();
}

void MainView::setLight() {
    // Setting for light position, intensity, color and material
    lightPosition.setX(0);
    lightPosition.setY(10);
    lightPosition.setZ(10);

    lightIntensity.setX(1.2);
    lightIntensity.setY(1.2);
    lightIntensity.setZ(1.2);

    lightColor.setX(1);
    lightColor.setY(1);
    lightColor.setZ(1);

    material.setX(0.3);
    material.setY(0.9);
    material.setZ(0.1);
}

void MainView::createShaderPrograms() {
    // Create shader programs for each tehnique
    normalShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_normal.glsl");
    normalShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_normal.glsl");
    normalShaderProgram.link();

    phongShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_phong.glsl");
    phongShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_phong.glsl");
    phongShaderProgram.link();

    gouraudShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_gouraud.glsl");
    gouraudShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_gouraud.glsl");
    gouraudShaderProgram.link();
}

void MainView::uniformSet() {
    // Get the uniforms
    uniformModelViewTransform = shaderProgram->uniformLocation("modelViewTransform");
    uniformProjectionTransform = shaderProgram->uniformLocation("projectionTransform");
    uniformNormalTransform = shaderProgram->uniformLocation("normalTransform");
}

void MainView::loadMesh() {
    Model model(":/models/cat.obj");

    QVector<QVector3D> vertexCoords = model.getVertices();
    QVector<QVector3D> normalCoords = model.getNormals();
    QVector<QVector2D> textureCoords = model.getTextureCoords();

    QVector3D initialTrans(0, -3, 1);

    QVector<float> meshData;
    meshData.reserve(3 * 2 * vertexCoords.size());

    int index = 0;

    for (auto coord : vertexCoords)
    {
        meshData.append((coord.x() * 10) + initialTrans.x());
        meshData.append((coord.y() * 10) + initialTrans.y());
        meshData.append((coord.z() * 10) + initialTrans.z());

        meshData.append(static_cast<float>(rand()) / RAND_MAX);
        meshData.append(static_cast<float>(rand()) / RAND_MAX);
        meshData.append(static_cast<float>(rand()) / RAND_MAX);

        meshData.append(normalCoords[index].x());
        meshData.append(normalCoords[index].y());
        meshData.append(normalCoords[index].z());

        meshData.append(textureCoords[index].x());
        meshData.append(textureCoords[index].y());

        index++;
    }
    meshSize = vertexCoords.size();

    // Generate VAO
    glGenVertexArrays(1, &meshVAO);
    glBindVertexArray(meshVAO);

    // Generate VBO
    glGenBuffers(1, &meshVBO);
    glBindBuffer(GL_ARRAY_BUFFER, meshVBO);

    // Write the data to the buffer
    glBufferData(GL_ARRAY_BUFFER, meshData.size() * sizeof(float), meshData.data(), GL_STATIC_DRAW);

    // Set vertex coordinates to location 0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // Set colour coordinates to location 1
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Set normal coordinates to location 2
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Set texture coordinates to location 3
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), reinterpret_cast<void*>(9 * sizeof(float)));
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    loadTexture(":/textures/cat_diff.png");
}

void MainView::loadTexture(QString file) {
    QImage image(file);
    QVector<quint8> imageVector = imageToBytes(image);

    GLsizei height = image.height();
    GLsizei width = image.width();

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageVector.data());
    glGenerateMipmap(GL_TEXTURE_2D);
}

// --- OpenGL drawing

/**
 * @brief MainView::paintGL
 *
 * Actual function used for drawing to the screen
 *
 */
void MainView::paintGL() {
    // Clear the screen before rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram->bind();

    glBindTexture(GL_TEXTURE_2D, texture);

    // Set the projection matrix
    glUniformMatrix4fv(uniformProjectionTransform, 1, GL_FALSE, projectionTransform.data());
    glUniformMatrix4fv(uniformModelViewTransform, 1, GL_FALSE, meshTransform.data());
    glUniformMatrix3fv(uniformNormalTransform, 1, GL_FALSE, normalTransform.data());

    if (mode == GOURAUD || mode == PHONG) {
        glUniform3f(uniformLightPosition, lightPosition.x(), lightPosition.y(), lightPosition.z());
        glUniform3f(uniformLightIntensity, lightIntensity.x(), lightIntensity.y(), lightIntensity.z());
        glUniform3f(uniformLightColor, lightColor.x(), lightColor.y(), lightColor.z());
        glUniform3f(uniformMaterial, material.x(), material.y(), material.z());
        glUniform1i(uniformSampler, 0);
    }

    glBindVertexArray(meshVAO);
    glDrawArrays(GL_TRIANGLES, 0, meshSize);

    shaderProgram->release();
}

/**
 * @brief MainView::resizeGL
 *
 * Called upon resizing of the screen
 *
 * @param newWidth
 * @param newHeight
 */
void MainView::resizeGL(int newWidth, int newHeight) {
    Q_UNUSED(newWidth)
    Q_UNUSED(newHeight)
    updateProjectionTransform();
}

void MainView::updateNormalTransform() {
    normalTransform = meshTransform.normalMatrix();
}

void MainView::updateProjectionTransform() {
    float aspect_ratio = static_cast<float>(width()) / static_cast<float>(height());
    projectionTransform.setToIdentity();
    projectionTransform.perspective(60.0F, aspect_ratio, 0.2F, 20.0F);
}

void MainView::updateModelTransforms() {
    meshTransform.setToIdentity();
    meshTransform.translate(0.0F, 0.0F, -10.0F);
    meshTransform.rotate(QQuaternion::fromEulerAngles(rotation));
    meshTransform.scale(scale);

    // Update the normal matrix
    normalTransform = meshTransform.normalMatrix();

    update();
}

// --- OpenGL cleanup helpers

void MainView::destroyModelBuffers() {
    glDeleteBuffers(1, &meshVBO);
    glDeleteVertexArrays(1, &meshVAO);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    rotation = { static_cast<float>(rotateX), static_cast<float>(rotateY), static_cast<float>(rotateZ) };
    updateModelTransforms();
}

void MainView::setScale(int newScale) {
    scale = static_cast<float>(newScale) / 100.f;
    updateModelTransforms();
}

void MainView::setShadingMode(ShadingMode shading) {
    qDebug() << "Changed shading to" << shading;

    // Set the shaderProgram pointer to the selected shaderProgram
    if(shading == NORMAL)
        shaderProgram = &normalShaderProgram;

    if(shading == PHONG) {
        shaderProgram = &phongShaderProgram;
        uniformLightPosition = shaderProgram->uniformLocation("light");
        uniformLightIntensity = shaderProgram->uniformLocation("lightIntensity");
        uniformLightColor = shaderProgram->uniformLocation("lightColor");
        uniformMaterial = shaderProgram->uniformLocation("material");
        uniformSampler = shaderProgram->uniformLocation("texture");
    }
    if(shading == GOURAUD) {
        shaderProgram = &gouraudShaderProgram;
        uniformLightPosition = shaderProgram->uniformLocation("light");
        uniformLightIntensity = shaderProgram->uniformLocation("lightIntensity");
        uniformLightColor = shaderProgram->uniformLocation("lightColor");
        uniformMaterial = shaderProgram->uniformLocation("material");
        uniformSampler = shaderProgram->uniformLocation("texture");
    }

    mode = shading;
    uniformSet();
}

// --- Private helpers

/**
 * @brief MainView::onMessageLogged
 *
 * OpenGL logging function, do not change
 *
 * @param Message
 */
void MainView::onMessageLogged( QOpenGLDebugMessage Message ) {
    qDebug() << " → Log:" << Message;
}

