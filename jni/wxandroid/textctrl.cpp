/*
 * wxTextCtrl.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: Tellis
 */
#include <wxandroid/wx/textctrl.h>


wxTextCtrl::wxTextCtrl()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	m_class = env->FindClass(BIND_TEXTCTRL);
	m_object = env->NewGlobalRef(env->NewObject(m_class, env->GetMethodID(m_class,
			"<init>", BIND_TEXTCTRL_CONSTRUCTOR_ARGS), wxAndroidApp::Activity));
	//m_object = env->NewObject(m_class, env->GetMethodID(m_class,
				//"<init>", BIND_TEXTCTRL_CONSTRUCTOR_ARGS), wxAndroidApp::Activity);
}

void wxTextCtrl::SetText(jstring text)
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID method = env->GetMethodID(m_class, "setText", "(Ljava/lang/CharSequence;)V");
	env->CallVoidMethod(m_object, method, text);
}




