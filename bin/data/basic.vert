
#version 150

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 textureMatrix;
uniform mat4 modelViewProjectionMatrix;
in vec4 position;
in vec2 texcoord;
in vec4 color;
uniform vec2 screenSize;
out vec2 texcoordvarying;
uniform float mouseX;

void main() {
    texcoordvarying = vec2(texcoord.x + mouseX, texcoord.y);
    gl_Position = modelViewProjectionMatrix * position;
}