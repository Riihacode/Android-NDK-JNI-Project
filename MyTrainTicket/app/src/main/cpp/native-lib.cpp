#include <jni.h>
#include <string>

/*
extern "C" JNIEXPORT jstring JNICALL
Java_com_development_mytrainticket_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
 */



extern "C" JNIEXPORT jstring JNICALL
Java_com_development_mytrainticket_MainActivity_getSeatStatus(
        JNIEnv *env,
        jobject /* this */,
        jint row,
        jint col) {
    // TODO: implement getSeatStatus()
}