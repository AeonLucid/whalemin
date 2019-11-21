#ifndef WHALE_ANDROID_ART_NATIVE_ON_LOAD_TYPES_H
#define WHALE_ANDROID_ART_NATIVE_ON_LOAD_TYPES_H

#include <jni.h>

typedef jobject (*t_bridgeMethod)(JNIEnv *, jobject, jlong, void *, jobject, jobjectArray);

#endif //WHALE_ANDROID_ART_NATIVE_ON_LOAD_TYPES_H
