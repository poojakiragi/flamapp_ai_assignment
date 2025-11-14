// simple.frag — Fragment Shader for rendering RGBA frame

precision mediump float;

varying vec2 vTexCoord;       // From vertex shader
uniform sampler2D uTexture;   // Processed frame (RGBA)

void main() {
    gl_FragColor = texture2D(uTexture, vTexCoord);
}
