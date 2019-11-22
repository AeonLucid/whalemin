#include <string>
#include <sstream>
#include "art_helper.h"
#include "android/art/well_known_classes.h"
#include "base/logging.h"

namespace whale {
namespace art {

char GetShortyType(JNIEnv *env, jobject clazzObj) {
    char result = 'L';

    jclass clazz = env->GetObjectClass(clazzObj);
    jmethodID mid = env->GetMethodID(clazz, "toString", "()Ljava/lang/String;");

    auto str_obj = (jstring) env->CallObjectMethod(clazzObj, mid);
    auto str = env->GetStringUTFChars(str_obj, nullptr);

    if (strcmp(str, "void") == 0) {
        result = 'V';
    } else if (strcmp(str, "int") == 0) {
        result = 'I';
    } else if (strcmp(str, "double") == 0) {
        result = 'D';
    } else if (strcmp(str, "float") == 0) {
        result = 'F';
    } else if (strcmp(str, "char") == 0) {
        result = 'C';
    } else if (strcmp(str, "short") == 0) {
        result = 'S';
    } else if (strcmp(str, "boolean") == 0) {
        result = 'Z';
    } else if (strcmp(str, "byte") == 0) {
        result = 'B';
    } else if (strcmp(str, "long") == 0) {
        result = 'J';
    }

    env->ReleaseStringUTFChars(str_obj, str);

    return result;
}

const char *GetShorty(JNIEnv *env, jobject retType, jobjectArray parameterTypes) {
    jsize array_length = env->GetArrayLength(parameterTypes);
    char *result = (char *) calloc((size_t) array_length + 2, 1);

    result[0] = GetShortyType(env, retType);

    for (int i = 0; i < array_length; ++i) {
        result[i + 1] = GetShortyType(env, env->GetObjectArrayElement(parameterTypes, i));
    }

    return result;
}

const char *GetShorty(JNIEnv *env, jobject member) {
    if (env->IsInstanceOf(member, WellKnownClasses::java_lang_reflect_Method)) {
        return GetShorty(env,
                         env->CallObjectMethod(member, WellKnownClasses::java_lang_reflect_Method_getReturnType),
                        (jobjectArray) env->CallObjectMethod(member, WellKnownClasses::java_lang_reflect_Method_getParameterTypes));
    } else if (env->IsInstanceOf(member, WellKnownClasses::java_lang_reflect_Constructor)) {
        return GetShorty(env,
                         WellKnownClasses::java_lang_Void,
                         (jobjectArray) env->CallObjectMethod(member, WellKnownClasses::java_lang_reflect_Constructor_getParameterTypes));
    } else {
        return nullptr;
    }
}

}
}