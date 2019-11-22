#ifndef WHALE_ANDROID_ART_HELPER_H
#define WHALE_ANDROID_ART_HELPER_H

#include <jni.h>

namespace whale {
namespace art {

const char *GetShorty(JNIEnv *env, jobject member);

}
}


#endif //WHALE_ANDROID_ART_HELPER_H
