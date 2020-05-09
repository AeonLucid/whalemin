#ifndef WHALE_ANDROID_ART_INTERCEPT_PARAM_H_
#define WHALE_ANDROID_ART_INTERCEPT_PARAM_H_

#include <jni.h>
#include "base/primitive_types.h"
#include "ffi_cxx.h"

namespace whale {
namespace art {

struct ArtHookParam final {

    bool is_static_;
    const char *shorty_;
    void *user_data_;
    volatile ptr_t decl_class_;

    ptr_t origin_jni_code_;
    ptr_t origin_quick_code_;
    ptr_t origin_interpreter_code_ = nullptr;
    u4 origin_access_flags_;
    u4 origin_dex_offset_;
    jobject origin_method_clone_;

    FFIClosure *hooked_jni_closure_;
    jmethodID hooked_native_method_;
    jobject hooked_method_;

};

}  // namespace art
}  // namespace whale

#endif  // WHALE_ANDROID_ART_INTERCEPT_PARAM_H_
