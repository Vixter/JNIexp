#include <jni.h>
#include "string"
using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_ru_jniexp_MainActivity_encrypt(JNIEnv *env, jobject instance, jstring plainText_) {
    jboolean isCopy = JNI_TRUE;
    const char *plainText = (env)->GetStringUTFChars(plainText_, &isCopy);
    string result = "plane text";
    if (isCopy == JNI_FALSE)
        (env)->ReleaseStringUTFChars(plainText_, plainText);
    else
        delete plainText;
    return (env)->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_ru_jniexp_MainActivity_decrypt(JNIEnv *env, jobject instance, jstring ciphertext_) {
    jboolean isCopy = JNI_TRUE;
    const char *ciphertext = env->GetStringUTFChars(ciphertext_, &isCopy);


    if (isCopy == JNI_FALSE)
        env->ReleaseStringUTFChars(ciphertext_, ciphertext);
    else
        delete ciphertext;

    return env->NewStringUTF(ciphertext);
}
