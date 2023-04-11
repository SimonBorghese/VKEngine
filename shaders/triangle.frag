#version 450

layout (location = 0) out vec4 FragColor;

layout (location = 0) in vec3 vertColor;

void main(){
    FragColor = vec4(vertColor, 1.0f);
}