#ifndef WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_
#define WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_

#include <jni.h>
#include "android/art/native_on_load_types.h"

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

jlong Whale_hookMethodNative(JNIEnv *env, jclass decl_class, jobject method_obj, void* addition_info);

jobject Whale_invokeOriginalMethodNative(jlong slot, jobject this_object, jobjectArray args);

jlong Whale_getMethodSlot(JNIEnv *env, jclass cl, jclass decl_class, jobject method_obj);

void Whale_setObjectClassNative(JNIEnv *env, jclass cl, jobject obj, jclass parent_class);

jobject Whale_cloneToSubclassNative(JNIEnv *env, jclass cl, jobject obj, jclass sub_class);

void Whale_removeFinalFlagNative(JNIEnv *env, jclass cl, jclass java_class);

bool Whale_enforceDisableHiddenAPIPolicy();

bool Whale_OnLoad(JavaVM *vm, t_bridgeMethod bridge_method);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // WHALE_ANDROID_ART_NATIVE_ON_LOAD_H_
