#include "android/art/native_on_load.h"
#include "android/art/art_runtime.h"
#include "base/logging.h"

extern "C" {

OPEN_API void WhaleRuntime_reserved0(JNI_START) {}

OPEN_API void WhaleRuntime_reserved1(JNI_START) {}

OPEN_API
jlong
Whale_hookMethodNative(JNIEnv *env, jclass decl_class, jobject method_obj, void* addition_info) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->HookMethod(env, decl_class, method_obj, addition_info);
}

OPEN_API
jobject
Whale_invokeOriginalMethodNative(jlong slot, jobject this_object,
                                 jobjectArray args) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->InvokeOriginalMethod(slot, this_object, args);
}

OPEN_API
jlong
Whale_getMethodSlot(JNI_START, jclass decl_class, jobject method_obj) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->GetMethodSlot(env, decl_class, method_obj);
}

OPEN_API
void
Whale_setObjectClassNative(JNI_START, jobject obj, jclass parent_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->SetObjectClass(env, obj, parent_class);
}

OPEN_API
jobject
Whale_cloneToSubclassNative(JNI_START, jobject obj, jclass sub_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->CloneToSubclass(env, obj, sub_class);
}

OPEN_API
void
Whale_removeFinalFlagNative(JNI_START, jclass java_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    runtime->RemoveFinalFlag(env, java_class);
}

OPEN_API
void
Whale_enforceDisableHiddenAPIPolicy(JNI_START) {
    auto runtime = whale::art::ArtRuntime::Get();
    runtime->EnforceDisableHiddenAPIPolicy();
}

OPEN_API bool Whale_OnLoad(JavaVM *vm, t_bridgeMethod bridge_method) {
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK) {
        LOG(ERROR) << "GetEnv failed";
        return false;
    }

    auto runtime = whale::art::ArtRuntime::Get();
    if (!runtime->OnLoad(vm, env, bridge_method)) {
        LOG(ERROR) << "Runtime setup failed";
        return false;
    }

    return true;
}

};