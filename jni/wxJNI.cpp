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

	//Instantiates a wxNotificationMsg object with the desired text and duration
	wxNotificationMsg* newNotification=new wxNotificationMsg(env->NewStringUTF("wxNotificationMsg"),NOTIFICATION_DURATION_SHORT);

	env->CallVoidMethod(*c, setOrientation, 1);
	env->CallVoidMethod(*c, add_view, (jobject)(*textctrl));
	env->CallVoidMethod(*c, add_view, (jobject)(*btn));
	env->CallVoidMethod(*c, add_view, (jobject)(*btn2));

	env->CallVoidMethod(thiz, setContent, *c);
	//Shows the previously constructed wxNotificationMsg
	newNotification->show();

	return 0;
}

void
Java_com_example_hellojni_wxJNI_handleEvent( JNIEnv* env,jobject thiz,
													  jint code,jobject obj)
{
	if(!wxAndroidApp::Activity)
		return;
	switch(code)
	{
	    case 1:
	        if(env->IsSameObject(obj,jobject(*btn)))
	        {
	        	textctrl->SetText(env->NewStringUTF("Event one"));
	        	wxNotificationMsg* EventNotification=new wxNotificationMsg(env->NewStringUTF("Event one"),NOTIFICATION_DURATION_LONG);
	        	EventNotification->show();
	        }
		    else if(env->IsSameObject(obj,jobject(*btn2)))
		    {
		    	textctrl->SetText(env->NewStringUTF("Event two"));
		    	wxNotificationMsg* EventNotification=new wxNotificationMsg(env->NewStringUTF("Event two"),NOTIFICATION_DURATION_LONG);
	        	EventNotification->show();
		    }
	        break;
	    default:
			textctrl->SetText(env->NewStringUTF("Generic touch event"));
			wxMotionEvent* TouchEvent=new wxMotionEvent(obj);
			(void)TouchEvent->getRawX();
			(void)TouchEvent->getRawY();
			wxNotificationMsg* EventNotification=new wxNotificationMsg(env->NewStringUTF("Generic touch event"),NOTIFICATION_DURATION_LONG);
		    EventNotification->show();
		    break;

	}

}
