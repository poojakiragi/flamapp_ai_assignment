
---

# 🚀 Features Implemented

## ✔ Android (Java + Camera2)
- Basic Camera2 preview pipeline  
- SurfaceTexture for frame updates  
- JNI hooks ready for sending NV21 frames to C++  
- Lightweight UI for assignment demonstration  

## ✔ JNI + C++ Native Layer
- Converts NV21 → BGR / Gray frame  
- Applies **OpenCV Canny Edge Detection**  
- Converts output to RGBA byte array  
- Fully compatible with OpenCV Android SDK  

## ✔ OpenGL ES Renderer (Stub)
- GLES20 renderer setup  
- Shader boilerplate (vertex + fragment)  
- Ready to bind textures for processed frames  
- Demonstrates full R&D pipeline structure  

## ✔ Web Viewer (TypeScript)
- Lightweight HTML/TS-based display  
- Shows processed frame (`processed_sample.png`)  
- Assignment-compliant folder + code  

---

# 🧠 Architecture Overview

The system follows this pipeline:

