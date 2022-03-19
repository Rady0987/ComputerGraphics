#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertCoordinates;
in vec3 vertNormal;
in vec3 vertColor;
in vec2 textureCoordinates;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example
uniform mat4 projectionTransform;
uniform mat4 modelViewTransform;
uniform mat3 normalTransform;

uniform vec3 lightPosition;
uniform vec3 lightIntensity;
uniform vec3 lightColor;
uniform vec3 material;

uniform sampler2D texture;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;

void main()
{
    vec3 lightVector, viewVector, normal, reflectionVector;

    vec4 textureColor = texture2D(texture, textureCoordinates);
    vec4 tmpVector = modelViewTransform * vec4(vertCoordinates, 1.0);

    normal = normalize(normalTransform * vertNormal);
    viewVector = normalize(-tmpVector.xyz);
    lightVector = normalize(lightPosition - tmpVector.xyz);
    reflectionVector = -reflect(lightVector, normal);


    int colDiv = 3;

    vec3 ambient = material.x * lightIntensity.x * lightColor;
    vec3 diffuse =  material.y * lightIntensity.y * lightColor * max(0, dot(normal, lightVector));
    vec3 spectacular = material.z * lightIntensity.z * lightColor * pow(max(0, dot(reflectionVector, viewVector)), colDiv);

    fColor = vec4(ambient + diffuse + spectacular, 1.0) * textureColor;
}
