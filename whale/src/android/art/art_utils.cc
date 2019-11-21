#include "android/art/art_utils.h"
#include "base/logging.h"

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

jobject find_top_classloader(JNIEnv *env, jobject class_loader) {
    jclass clz = env->GetObjectClass(class_loader);
    jmethodID mid = env->GetMethodID(clz, "getParent", "()Ljava/lang/ClassLoader;");

    jobject top_classloader = class_loader;
    jobject parent = nullptr;

    while (true) {
        parent = env->CallObjectMethod(top_classloader, mid);

        if (parent == nullptr) {
            break;
        }

        top_classloader = parent;
    }

    return top_classloader;
}