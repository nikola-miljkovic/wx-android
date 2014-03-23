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
#include <wxJNI.h>
/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 *   apps/samples/hello-jni/project/src/com/example/hellojni/HelloJni.java
 */
jint
Java_com_example_hellojni_wxJNI_wxStart( JNIEnv* env,
													  jobject thiz ,jstring label)
{
    // MACHINE GENERATED DO NOT TOUCH
    set_jni_id(0);

	wxAndroidApp::JNIEnv = env;
	wxAndroidApp::Activity = &thiz;

	jclass this_c = env->GetObjectClass(thiz);
	jclass cl_ll = env->FindClass("android/widget/LinearLayout");

	wxButton* btn = new wxButton();
	btn->SetLabel(label);

	wxTextCtrl* textctrl=new wxTextCtrl();
	textctrl->SetText(label);

	jmethodID construct = env->GetMethodID(cl_ll, "<init>", "(Landroid/content/Context;)V");
	jmethodID add_view = env->GetMethodID(cl_ll, "addView", "(Landroid/view/View;)V");
	jmethodID setContent = env->GetMethodID(this_c, "setContentView", "(Landroid/view/View;)V");

	// construct layout and button
	jobject c = env->NewObject(cl_ll, construct, thiz);

	env->CallVoidMethod(c, add_view, (jobject)(*btn));
	env->CallVoidMethod(c, add_view, (jobject)(*textctrl));
	env->CallVoidMethod(thiz, setContent, c);

	return 0;
}
