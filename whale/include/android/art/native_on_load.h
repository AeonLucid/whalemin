#ifndef WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_
#define WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_

#include <jni.h>

constexpr const char *kMethodReserved0 = "reserved0";
constexpr const char *kMethodReserved1 = "reserved1";

/**
 * DO NOT rename the following function
 */
extern "C" {

void WhaleRuntime_reserved0(JNIEnv *env, jclass cl);

void WhaleRuntime_reserved1(JNIEnv *env, jclass cl);

}

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

jlong WhaleRuntime_hookMethodNative(JNIEnv *env, jclass cl, jclass decl_class, jobject method_obj, jobject addition_info);

jobject WhaleRuntime_invokeOriginalMethodNative(JNIEnv *env, jclass cl, jlong slot, jobject this_object, jobjectArray args);

jlong WhaleRuntime_getMethodSlot(JNIEnv *env, jclass cl, jclass decl_class, jobject method_obj);

void WhaleRuntime_setObjectClassNative(JNIEnv *env, jclass cl, jobject obj, jclass parent_class);

jobject WhaleRuntime_cloneToSubclassNative(JNIEnv *env, jclass cl, jobject obj, jclass sub_class);

void WhaleRuntime_removeFinalFlagNative(JNIEnv *env, jclass cl, jclass java_class);

void WhaleRuntime_enforceDisableHiddenAPIPolicy(JNIEnv *env, jclass cl);

bool Native_OnLoad(JavaVM *vm);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_
