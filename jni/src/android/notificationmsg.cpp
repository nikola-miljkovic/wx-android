/*
 * notificationmsg.cpp
 *
 *  Created on: Mar 27, 2014
 *      Author: Melroy Tellis
 */
#include <wx/notificationmsg.h>


//Here,I have used the Toast.makeText() static method to generate
//a toast object with the required text and duration
wxNotificationMsg::wxNotificationMsg(jstring text,jint duration)
{
	JNIEnv* env = wxAppMgr::Env;
	m_class = env->FindClass(BIND_TOAST);
	jmethodID makeTextMethod=env->GetStaticMethodID(m_class,"makeText","(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");
	m_object=env->NewGlobalRef(env->CallStaticObjectMethod(m_class, makeTextMethod, wxAppMgr::Activity, text, duration));
}

void wxNotificationMsg::show()
{
	JNIEnv* env = wxAppMgr::Env;
	jmethodID showMethod = env->GetMethodID(env->GetObjectClass(m_object), "show", "()V");
	env->CallVoidMethod(m_object, showMethod);
}



