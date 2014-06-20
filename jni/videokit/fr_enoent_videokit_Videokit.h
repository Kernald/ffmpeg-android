#ifndef __FR_ENOENT_VIDEOKIT_VIDEOKIT_H
#define __FR_ENOENT_VIDEOKIT_VIDEOKIT_H

#include <jni.h>

#ifdef __cplusplus
    extern "C" {
#endif // __cplusplus

JNIEXPORT jboolean JNICALL Java_fr_enoent_videokit_Videokit_run(JNIEnv *, jobject, jobjectArray);

#ifdef __cplusplus
    }
#endif // __cplusplus

#endif // __FR_ENOENT_VIDEOKIT_VIDEOKIT_H
