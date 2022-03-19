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

// Specify the output of the vertex stage
out vec3 vertColor;
out vec3 vertCoordinates;
out vec3 vertNormal;
out vec2 textureCoordinates;

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    gl_Position = projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0);
    vertColor = vertColor_in;
    vertCoordinates = vertCoordinates_in;
    vertNormal = normalCoordinates_in;
    textureCoordinates = textureCoordinates_in;
}
