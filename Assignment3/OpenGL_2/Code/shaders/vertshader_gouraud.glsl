#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertColor_in;
layout (location = 2) in vec3 normalCoordinates_in;
layout (location = 3) in vec2 textureCoordinates_in;

// Specify the Uniforms of the vertex shader
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform mat3 normalTransform;

uniform vec3 lightPositions;
uniform vec3 lightIntensity;
uniform vec3 lightColor;

uniform vec3 material;

// Specify the output of the vertex stage
out vec3 vertColor;
out vec2 textureCoordinates;

void main()
{
    vec3  lightVector, viewVector, reflectionVector, normal;
    vec4 vertCoordTransform = modelViewTransform * vec4(vertCoordinates_in, 1.0F);

    // gl_Position is the output (a vec4) of the vertex shader
    gl_Position = projectionTransform * vertCoordTransform;

    normal = normalize(normalTransform * normalCoordinates_in);
    lightVector = normalize(lightPositions - vertCoordTransform.xyz);
    reflectionVector = -reflect(lightVector, normal);
    viewVector = normalize(-vertCoordTransform.xyz);

    int colDiv = 2;

    vec3 ambient = material.x * lightIntensity.x * lightColor;
    vec3 diffuse =  material.y * lightIntensity.y * lightColor * max(0, dot(normal, lightVector));
    vec3 spectacular = material.z * lightIntensity.z * lightColor * pow(max(0, dot(reflectionVector, viewVector)), colDiv);

    textureCoordinates = textureCoordinates_in;
    vertColor = ambient + diffuse + spectacular;
}
