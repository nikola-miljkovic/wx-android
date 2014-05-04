/*
 * wxTextCtrl.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: Melroy Tellis
 */
#include <wx/textctrl.h>


wxTextCtrl::wxTextCtrl()
{
	JNIEnv* env = wxAppMgr::Env;
	m_class = env->FindClass(BIND_TEXTCTRL);
	m_object = env->NewGlobalRef(env->NewObject(m_class, env->GetMethodID(m_class,
			"<init>", BIND_TEXTCTRL_CONSTRUCTOR_ARGS), wxAppMgr::Activity));
}

void wxTextCtrl::SetText(jstring text)
{
	JNIEnv* env = wxAppMgr::Env;
	jmethodID method = env->GetMethodID(env->GetObjectClass(m_object),"setText","(Ljava/lang/CharSequence;)V");
	env->CallVoidMethod(m_object, method, text);
}




