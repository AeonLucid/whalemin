#ifndef WHALE_ANDROID_ART_UTILS_H
#define WHALE_ANDROID_ART_UTILS_H

#include <jni.h>

jclass find_class_from_loader(JNIEnv *env, jobject class_loader, const char *class_name);

jobject find_top_classloader(JNIEnv *env, jobject class_loader);

#endif //WHALE_ANDROID_ART_UTILS_H
