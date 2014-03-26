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

wxButton* btn;
wxButton* btn2;
wxTextCtrl* textctrl;

jobject* c;

jint
Java_com_example_hellojni_wxJNI_wxStart( JNIEnv* env,
													  jobject thiz ,jstring label)
{
	wxAndroidApp::JNIEnv = env;
	wxAndroidApp::Activity = env->NewGlobalRef(thiz);

	jclass this_c = env->GetObjectClass(thiz);
	jclass cl_ll = env->FindClass("android/widget/LinearLayout");

	btn = new wxButton();
	btn->SetLabel(env->NewStringUTF("Button one"));

	btn2 = new wxButton();
	btn2->SetLabel(env->NewStringUTF("Button two"));

	textctrl= new wxTextCtrl();
	textctrl->SetText(label);

	jmethodID construct = env->GetMethodID(cl_ll, "<init>", "(Landroid/content/Context;)V");
	jmethodID add_view = env->GetMethodID(cl_ll, "addView", "(Landroid/view/View;)V");
	jmethodID setContent = env->GetMethodID(this_c, "setContentView", "(Landroid/view/View;)V");
	jmethodID setOrientation = env->GetMethodID(cl_ll, "setOrientation", "(I)V");
	// construct layout and button
	jobject c_l = env->NewObject(cl_ll, construct, thiz);
	c = &c_l;

	env->CallVoidMethod(*c, setOrientation, 1);
	env->CallVoidMethod(*c, add_view, (jobject)(*textctrl));
	env->CallVoidMethod(*c, add_view, (jobject)(*btn));
	env->CallVoidMethod(*c, add_view, (jobject)(*btn2));

	env->CallVoidMethod(thiz, setContent, *c);

	return 0;
}

void
Java_com_example_hellojni_wxJNI_handleEvent( JNIEnv* env,
													  jobject thiz,
													  jint code,
													  jobject obj)
{
	if(!wxAndroidApp::Activity)
		return;
	if(env->IsSameObject(obj, (jobject)(*btn)) && code == 1)
		textctrl->SetText(env->NewStringUTF("Event one"));
	else if(env->IsSameObject(obj, (jobject)(*btn2)) && code == 1)
		textctrl->SetText(env->NewStringUTF("Event two"));
	else if(code == 2)
		textctrl->SetText(env->NewStringUTF("Event three"));
}
