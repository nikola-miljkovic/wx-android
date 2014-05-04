#include <wx/button.h>

wxButton::wxButton()
{
	JNIEnv* env = wxAppMgr::Env;
	m_class = env->FindClass(BIND_BUTTON);
	m_object = env->NewGlobalRef(env->NewObject(m_class, env->GetMethodID(m_class,
			"<init>", BIND_BUTTON_CONSTRUCTOR_ARGS), wxAppMgr::Activity));

    if(m_object)
	{
		jmethodID set_listener = env->GetMethodID(m_class, "setOnClickListener", "(Landroid/view/View$OnClickListener;)V");
		env->CallVoidMethod(m_object, set_listener, wxAppMgr::Activity);
	}
}

void wxButton::SetLabel(jstring label)
{
	JNIEnv* env = wxAppMgr::Env;
	jmethodID method = env->GetMethodID(env->GetObjectClass(m_object), "setText", "(Ljava/lang/CharSequence;)V");
	env->CallVoidMethod(m_object, method, label);
}
