#include <wxandroid/wx/button.h>

wxButton::wxButton()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	m_class = env->FindClass(BIND_BUTTON);
	m_object = env->NewObject(m_class, env->GetMethodID(m_class,
			"<init>", BIND_BUTTON_CONSTRUCTOR_ARGS), (*wxAndroidApp::Activity));
}

void wxButton::SetLabel(const char* label)
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID method = env->GetMethodID(m_class, "setText", "(Ljava/lang/CharSequence;)V");
	env->CallVoidMethod(m_object, method, env->NewStringUTF(label));
}
