#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_flamapp_NativeBridge_stringFromJNI(JNIEnv *env, jclass clazz) {
    std::string msg = "native loaded";
    return env->NewStringUTF(msg.c_str());
}


extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_flamapp_NativeBridge_nativeProcessFrame(
        JNIEnv *env,
        jclass clazz,
        jbyteArray data,
        jint width,
        jint height
) {
    // 1. Get input NV21 from Java
    jbyte *inputBytes = env->GetByteArrayElements(data, nullptr);
    if (inputBytes == nullptr) {
        return nullptr;
    }

    // 2. Wrap NV21 in OpenCV Mat
    // NV21 = Y plane + VU interleaved plane
    Mat yuv(height + height / 2, width, CV_8UC1, (unsigned char *) inputBytes);

    // 3. Convert NV21 → BGR
    Mat bgr;
    try {
        cvtColor(yuv, bgr, COLOR_YUV2BGR_NV21);
    } catch (...) {
        env->ReleaseByteArrayElements(data, inputBytes, 0);
        return nullptr;
    }

    // 4. Convert BGR → Gray
    Mat gray;
    cvtColor(bgr, gray, COLOR_BGR2GRAY);

    // 5. Apply Canny Edge Detection
    Mat edges;
    Canny(gray, edges, 50, 150);

    // 6. Convert GRAY → RGBA (for OpenGL texture)
    Mat rgba;
    cvtColor(edges, rgba, COLOR_GRAY2RGBA);

    // 7. Prepare output buffer
    int outSize = rgba.total() * rgba.elemSize();
    jbyteArray output = env->NewByteArray(outSize);

    // 8. Copy processed data to Java byte[]
    env->SetByteArrayRegion(output, 0, outSize, (jbyte *) rgba.data);

    // 9. Release input buffer
    env->ReleaseByteArrayElements(data, inputBytes, 0);

    return output;
}
