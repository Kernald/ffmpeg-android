#include "logjam.h"
#include "fr_enoent_videokit_Videokit.h"

#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv);

JavaVM *sVm = NULL;

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	LOGI("Loading native library compiled at " __TIME__ " " __DATE__);
	sVm = vm;
	return JNI_VERSION_1_6;
}

JNIEXPORT jboolean JNICALL Java_fr_enoent_videokit_Videokit_run(JNIEnv *env, jobject obj, jobjectArray args) {
	int i = 0;
	int argc = 0;
	char **argv = NULL;
	jstring *strr = NULL;

	if (args != NULL) {
		argc = (*env)->GetArrayLength(env, args);
		argv = (char **) malloc(sizeof(char *) * argc);
		strr = (jstring *) malloc(sizeof(jstring) * argc);

		for (i = 0; i < argc; ++i) {
			strr[i] = (jstring)(*env)->GetObjectArrayElement(env, args, i);
			argv[i] = (char *)(*env)->GetStringUTFChars(env, strr[i], 0);
			LOGI("Option: %s", argv[i]);
		}
	}	

    LOGI("Running main");
	int result = main(argc, argv);
	LOGI("Main ended with status %d", result);

	for (i = 0; i < argc; ++i) {
		(*env)->ReleaseStringUTFChars(env, strr[i], argv[i]);
	}
	free(argv);
	free(strr);

	return result == 0;
}
