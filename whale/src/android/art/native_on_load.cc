#include "android/art/native_on_load.h"
#include "android/art/art_runtime.h"
#include "base/logging.h"

extern "C" {

void WhaleRuntime_reserved0(JNI_START) {}

void WhaleRuntime_reserved1(JNI_START) {}

jlong
Whale_hookMethodNative(JNIEnv *env, jclass decl_class, jobject method_obj, void* addition_info) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->HookMethod(env, decl_class, method_obj, addition_info);
}

bool
Whale_restoreMethod(JNIEnv *env, jobject method_obj) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->RestoreMethod(env, method_obj);
}

jobject
Whale_invokeOriginalMethodNative(jlong slot, jobject this_object,
                                 jobjectArray args) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->InvokeOriginalMethod(slot, this_object, args);
}

jlong
Whale_getMethodSlot(JNI_START, jclass decl_class, jobject method_obj) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->GetMethodSlot(env, decl_class, method_obj);
}

void
Whale_setObjectClassNative(JNI_START, jobject obj, jclass parent_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->SetObjectClass(env, obj, parent_class);
}

jobject
Whale_cloneToSubclassNative(JNI_START, jobject obj, jclass sub_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->CloneToSubclass(env, obj, sub_class);
}

void
Whale_removeFinalFlagNative(JNI_START, jclass java_class) {
    auto runtime = whale::art::ArtRuntime::Get();
    runtime->RemoveFinalFlag(env, java_class);
}

bool
Whale_enforceDisableHiddenAPIPolicy() {
    auto runtime = whale::art::ArtRuntime::Get();
    return runtime->EnforceDisableHiddenAPIPolicy();
}

bool Whale_OnLoad(JavaVM *vm, t_bridgeMethod bridge_method) {
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