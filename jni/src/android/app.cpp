#include <jni.h>
#include <wx/app.h>

namespace wxAppMgr
{
	JNIEnv* Env;
	jobject Activity;
	jobject OptionsMenuClick;

	wxApp* Application;
	std::stack<jobject*> ActivityStack;
};

