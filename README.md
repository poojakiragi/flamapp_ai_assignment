# Flamapp.AI Assignment — Android (Camera2 + JNI + OpenCV + OpenGL ES) + Web Viewer

This repository contains my implementation of the **Flamapp.AI Android + OpenCV-C++ + OpenGL + Web RnD Intern assessment**.

It demonstrates:

- Android camera feed using **Camera2** and `TextureView` / `SurfaceTexture`
- **JNI bridge** from Java/Kotlin to **C++** for native processing
- **OpenCV** C++ pipeline (Canny edge detection / grayscale)
- **OpenGL ES 2.0** textured rendering of the processed frame
- A minimal **TypeScript web viewer** that displays a processed frame and basic stats
- Clean project structure: `/app`, `/jni`, `/gl`, `/web`, `/docs`

> Focus is on integration and real-time rendering, not on fancy UI.

---

## 1. Features Implemented

### 1.1 Android (Camera + OpenCV + OpenGL ES)

- ✅ **Camera feed integration**
  - Uses **Camera2 API** with `TextureView` / `SurfaceTexture`
  - Continuous preview stream from the rear camera
- ✅ **Frame processing via OpenCV (C++)**
  - Frames are captured in YUV format
  - Converted to a format usable by OpenCV (`cv::Mat`)
  - Applied **Canny edge detection** (can be easily switched to grayscale or other effects)
  - Processed frames are kept in native memory to avoid unnecessary copies
- ✅ **JNI bridge**
  - Java/Kotlin ↔ C++ communication through JNI
  - Separate native functions for:
    - Initializing OpenCV / native pipeline
    - Submitting camera frames for processing
    - Getting / updating the processed texture
- ✅ **OpenGL ES 2.0 rendering**
  - Uses an OpenGL ES 2.0 renderer class under `/gl`
  - Renders the processed frame as a **texture** on a full-screen quad
  - Designed for **real-time** performance (~10–15 FPS or more on typical devices)
- ✅ **Basic UI**
  - Single screen preview of processed camera output
  - Optional toggle button to switch between:
    - Raw camera preview
    - Edge-detected view (if enabled in code)

> If you are reviewing the repo: all Android-specific code is under `app/src/main/java/com/example/flamapp` and native code is under `/jni`.

---

### 1.2 Web (TypeScript Viewer)

Located under `/web`.

- ✅ **TypeScript + HTML web page**
  - Simple build setup using `tsconfig.json` and `tsc`
  - Clean, modular TypeScript code
- ✅ **Static processed frame display**
  - Displays a **sample processed frame** exported from the Android app (PNG/JPEG or base64)
  - Shows a preview of what the edge-detection output looks like
- ✅ **Frame stats overlay**
  - Text overlay for:
    - Resolution (e.g. `1280x720`)
    - Example FPS or note (e.g., “Captured at ~15 FPS on device”)
- ✅ **DOM updates in TypeScript**
  - Using TypeScript to:
    - Set `src` of an `<img>` element
    - Update text in stats area dynamically
  - Demonstrates familiarity with TS, DOM, and a simple build flow

---

## 2. Project Structure

```text
.
├── app/                     # Android app module (Camera2, UI, JNI hooks)
│   └── src/main/java/com/example/flamapp/  # MainActivity, renderer glue, etc.
├── jni/                     # C++ code for JNI + OpenCV processing
│   ├── CMakeLists.txt       # Native build configuration
│   ├── native_lib.cpp       # JNI functions, OpenCV pipeline
│   └── ...
├── gl/                      # OpenGL ES renderer & shaders
│   ├── renderer/            # Renderer classes
│   └── shaders/             # Vertex/fragment shaders
├── web/                     # TypeScript web viewer
│   ├── src/                 # TS source files
│   ├── dist/ (ignored)      # Compiled JS output (after build)
│   └── index.html           # Entry HTML for the viewer
├── docs/                    # Screenshots / GIFs / exported sample frames
│   ├── android_preview.png
│   ├── android_edges.gif
│   └── web_viewer.png
├── README.md                # This file
└── create_repo.sh           # Helper to initialize repo (not required to run)
