#include "mainview.h"
#include "vertex.h"
#include <QDateTime>

// s4377354 s4036999

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

    cubeModel = new QMatrix4x4();
    cubeModel->translate(2, 0, -6);
    cubeScale = new QMatrix4x4();
    cubeRotate = new QMatrix4x4();

    pyramidModel = new QMatrix4x4();
    pyramidModel->translate(-2, 0, -6);
    pyramidScale = new QMatrix4x4();
    pyramidRotate = new QMatrix4x4();

    sphereModel = new QMatrix4x4();
    sphereModel->translate(0, 0, -10);
    sphereScale = new QMatrix4x4();
    sphereRotate = new QMatrix4x4();

    proj = new QMatrix4x4();
    proj->perspective(60.0f, 4.0 / 3.0, 0.1f, 100.0f);

    Model sModel(":/models/sphere.obj");
    sModel.unitize();
    sphere = sModel.getVertices();

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

    glDeleteVertexArrays(1, &vaoC);
    glDeleteBuffers(1, &vboC);

    glDeleteVertexArrays(1, &vaoP);
    glDeleteBuffers(1, &vboP);

    glDeleteVertexArrays(1, &vaoS);
    glDeleteBuffers(1, &vboS);

    delete proj;

    delete cubeModel;
    delete cubeScale;
    delete cubeRotate;

    delete pyramidModel;
    delete pyramidScale;
    delete pyramidRotate;

    delete sphereModel;
    delete sphereScale;
    delete sphereRotate;

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

    connect(&debugLogger, SIGNAL( messageLogged( QOpenGLDebugMessage)),
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

    Vertex v1 = newVertex(-1.0, -1.0, -1.0, 1.0, 0.0, 0.0); //back left bottom
    Vertex v2 = newVertex(1.0, -1.0, -1.0, 1.0, 0.0, 0.0); //back right bottom
    Vertex v3 = newVertex(1.0, 1.0, -1.0, 1.0, 0.0, 0.0); //back right top
    Vertex v4 = newVertex(-1.0, 1.0, -1.0, 0.0, 1.0, 0.0); //back left top
    Vertex v5 = newVertex(-1.0, 1.0, 1.0, 0.0, 1.0, 0.0); //front left top
    Vertex v6 = newVertex(1.0, 1.0, 1.0, 0.0, 1.0, 0.0); //front right top
    Vertex v7 = newVertex(1.0, -1.0, 1.0, 0.0, 0.0, 1.0); //front right bottom
    Vertex v8 = newVertex(-1.0, -1.0, 1.0, 0.0, 0.0, 1.0); //front left bottom

    Vertex cube[36] = {v8, v1, v2, // bottom plane north west  - cul
                       v2, v7, v8, // bottom plane south east - cul
                       v7, v2, v3, // right plane south east  - no
                       v3, v6, v7, // right plane north west - no
                       v6, v3, v4, // top plane north east - no
                       v4, v5, v6, // top plane south west - no
                       v5, v4, v1, // left plane north west - no
                       v1, v8, v5, // left plane south east - no
                       v5, v8, v7, // front plane south west - no
                       v7, v6, v5, // front plane north east - no
                       v1, v4, v3, // back plane north west - cul
                       v3, v2, v1}; // back plane south east - cul


    glGenBuffers(1, &vboC);
    glGenVertexArrays(1, &vaoC);
    glBindVertexArray(vaoC);
    glBindBuffer(GL_ARRAY_BUFFER, vboC);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, cube, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    // Pyramid

    Vertex top = newVertex(0,1,0,1,1,0);
    Vertex topLeft = newVertex(-1,-1,-1,0,1,1);
    Vertex topRight = newVertex(1,-1,-1,1,0,0);
    Vertex bottomLeft = newVertex(-1,-1,1,0,0,1);
    Vertex bottomRight = newVertex(1,-1,1,0,1,0);

    Vertex pyramid[18] = { top, bottomLeft, bottomRight,
                         bottomRight, topRight, top,
                         top, topRight, topLeft,
                         top, topLeft, bottomLeft,
                         topRight, bottomLeft,  topLeft,
                         bottomRight, bottomLeft,  topRight};


    glGenBuffers(1, &vboP);
    glGenVertexArrays(1, &vaoP);
    glBindVertexArray(vaoP);
    glBindBuffer(GL_ARRAY_BUFFER, vboP);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 18, pyramid, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

    sizeSphere = sphere.size();
    Vertex vertices[sizeSphere];
    float scale = 0.03;

    for(int i = 0; i < sizeSphere; i++) {
        float x = scale * sphere.at(i).operator[](0);
        float y = scale * sphere.at(i).operator[](1);
        float z = scale * sphere.at(i).operator[](2);
        float red = (float) (i % 3 == 0);
        float green = (float) (i % 2 == 1);
        float blue = (float) (i % 5 == 0);
        vertices[i] = newVertex(x, y, z, red, green, blue);
    }

    glGenBuffers(1, &vboS);
    glGenVertexArrays(1, &vaoS);
    glBindVertexArray(vaoS);
    glBindBuffer(GL_ARRAY_BUFFER, vboS);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * sizeSphere, vertices, GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glVertexAttribPointer(1, 3,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));


    createShaderProgram();
}

void MainView::createShaderProgram() {
    // Create shader program
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader.glsl");
    shaderProgram.link();

    modelTransformLocation = shaderProgram.uniformLocation("modelTransform");
    projectionTransformLocation = shaderProgram.uniformLocation("projectionTransform");
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

    shaderProgram.bind();

    glUniformMatrix4fv(projectionTransformLocation, 1, GL_FALSE, proj->data());


    // Draw here
    glBindVertexArray(vaoC);
    QMatrix4x4 cubeTransformation = (*cubeRotate * *cubeModel * *cubeScale);
    glUniformMatrix4fv(modelTransformLocation, 1, GL_FALSE, cubeTransformation.data());
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glBindVertexArray(vaoP);
    QMatrix4x4 pyramidTransformation = (*pyramidModel * *pyramidRotate * *pyramidScale);
    glUniformMatrix4fv(modelTransformLocation, 1, GL_FALSE, pyramidTransformation.data());
    glDrawArrays(GL_TRIANGLES, 0, 18);

    glBindVertexArray(vaoS);
    QMatrix4x4 sphereTransformation = (*sphereModel * *sphereRotate * *sphereScale);
    glUniformMatrix4fv(modelTransformLocation, 1, GL_FALSE, sphereTransformation.data());
    glDrawArrays(GL_TRIANGLES, 0, sizeSphere);

    shaderProgram.release();
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
    delete proj;
    proj = new QMatrix4x4();
    proj->perspective(60.0f, (float)newWidth / (float)newHeight, 0.1f, 100.0f);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ) {
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << "," << rotateZ << ")";
    delete cubeRotate;
    cubeRotate = new QMatrix4x4();
    cubeRotate->rotate(rotateX, 1, 0, 0);
    cubeRotate->rotate(rotateY, 0, 1, 0);
    cubeRotate->rotate(rotateZ, 0, 0, 1);

    delete pyramidRotate;
    pyramidRotate = new QMatrix4x4();
    pyramidRotate->rotate(rotateX, 1, 0, 0);
    pyramidRotate->rotate(rotateY, 0, 1, 0);
    pyramidRotate->rotate(rotateZ, 0, 0, 1);

    delete sphereRotate;
    sphereRotate = new QMatrix4x4();
    sphereRotate->rotate(rotateX, 1, 0, 0);
    sphereRotate->rotate(rotateY, 0, 1, 0);
    sphereRotate->rotate(rotateZ, 0, 0, 1);

    update();
}

void MainView::setScale(int scale) {
    qDebug() << "Scale changed to " << scale;
    delete cubeScale;
    cubeScale = new QMatrix4x4();
    cubeScale->scale( (float) scale / (float) 100);

    delete pyramidScale;
    pyramidScale = new QMatrix4x4();
    pyramidScale->scale( (float) scale / (float) 100);

    delete sphereScale;
    sphereScale = new QMatrix4x4();
    sphereScale->scale( (float) scale / (float) 100);

    update();
}


void MainView::setShadingMode(ShadingMode shading) {
    qDebug() << "Changed shading to" << shading;
    Q_UNIMPLEMENTED();
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
