#include "art_utils.h"

jclass find_class_from_loader(JNIEnv *env, jobject class_loader, const char *class_name) {
    jclass clz = env->GetObjectClass(class_loader);
    jmethodID mid = env->GetMethodID(clz, "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;");

    if (mid == nullptr) {
        mid = env->GetMethodID(clz, "findClass", "(Ljava/lang/String;)Ljava/lang/Class;");
    }

    if (mid != nullptr) {
        jobject target = env->CallObjectMethod(class_loader, mid, env->NewStringUTF(class_name));
        if (target != nullptr) {
            return (jclass) target;
        } else {
            LOG(ERROR) << "Class %s not found" << class_name;
        }
    } else {
        LOG(ERROR) << "No loadClass/findClass method found";
    }

    return nullptr;
}