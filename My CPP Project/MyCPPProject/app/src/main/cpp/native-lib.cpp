#include <jni.h>
#include "includes/StudentManager.h"
#include <string>

using namespace std;

StudentManager manager;

extern "C" JNIEXPORT void JNICALL
Java_com_development_mycppproject_MainActivity_tambahMahasiswa(
        JNIEnv* env,
        jobject /* this */,
        jstring nama,
        jint nim,
        jfloat ipk,
        jfloatArray nilai) {

    const char *nativeNama = env->GetStringUTFChars(nama, nullptr);
    jfloat *nilaiArray = env->GetFloatArrayElements(nilai, nullptr);

    manager.tambahMahasiswa(nativeNama, nim, ipk, nilaiArray);

    env->ReleaseStringUTFChars(nama, nativeNama);
    env->ReleaseFloatArrayElements(nilai, nilaiArray, 0);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_development_mycppproject_MainActivity_tampilkanMahasiswa(
        JNIEnv* env,
        jobject /* this */){

        // Panggil fungsi
        string hasil = manager.tampilkanMahasiswa();

        // kembalikan hasil sebagai jstring
        return env->NewStringUTF(hasil.c_str());
}

// Rekursif
extern "C" JNIEXPORT void JNICALL
Java_com_development_mycppproject_MainActivity_cariMahasiswaRekursif(
        JNIEnv* env,
        jobject /* this */,
        jstring nama,
        jint nim,
        jfloat ipk) {
    const char *nativeNama = env->GetStringUTFChars(nama, nullptr);
    manager.tambahMahasiswa(nativeNama, nim, ipk);
    env->ReleaseStringUTFChars(nama, nativeNama);
}

















