// simple.vert — Vertex Shader for full-screen textured quad

attribute vec4 aPosition;     // Vertex position (clip space)
attribute vec2 aTexCoord;     // Texture coordinates

varying vec2 vTexCoord;       // Pass texture coordinate to fragment shader

void main() {
    gl_Position = aPosition;  // Pass position directly
    vTexCoord = aTexCoord;    // Pass texture coordinates
}
