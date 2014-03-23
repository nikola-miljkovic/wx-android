/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <jni.h>
#include <string.h>
#include <wxandroid/button.cpp>
#include <wxandroid/textctrl.cpp>
#include <android/log.h>

#ifndef __wx_jni
#define __wx_jni
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__arm__)
	#if defined(__ARM_ARCH_7A__)
		#if defined(__ARM_NEON__)
			#define ABI "armeabi-v7a/NEON"
		#else
		  	  #define ABI "armeabi-v7a"
		#endif
	#else
	   	#define ABI "armeabi"
	#endif
#elif defined(__i386__)
	#define ABI "x86"
#elif defined(__mips__)
	#define ABI "mips"
#else
	#define ABI "unknown"
#endif


#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))


/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
//jint JNI_OnLoad(JavaVM* vm, void* reserved) { return JNI_VERSION_1_6; }

jint
Java_com_example_hellojni_wxJNI_wxStart( JNIEnv* env,
													  jobject thiz ,jstring label);


jint
Java_com_example_hellojni_wxJNI_handleEvent( JNIEnv* env,
													  jobject thiz,
													  jint code,
													  jobject obj);

#ifdef __cplusplus
}
#endif
#endif
