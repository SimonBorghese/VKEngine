#version 450

layout (location = 0) out vec3 outVert;

void main(){
    const vec3 positions[3] = vec3[3](
        vec3(0.5f, 0.5f, 0.f),
        vec3(-0.5f, 0.5f, 0.f),
        vec3(0.f, -0.5f, 0.f)
    );

    const vec3 colors[3] = vec3[3](
    vec3(0.5f, 0.0f, 0.f),
    vec3(0.0f, 0.5f, 0.f),
    vec3(0.f, 0.f, 0.5f)
    );

    outVert = colors[gl_VertexIndex];

    gl_Position = vec4(positions[gl_VertexIndex], 1.0f);

}