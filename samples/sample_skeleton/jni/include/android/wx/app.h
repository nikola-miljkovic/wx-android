#ifndef __WX_APP
#define __WX_APP

#include <jni.h>
#include <stack>

#define IMPLEMENT_APP(appname) \
		jint JNI_OnLoad(JavaVM* vm, void* reserved) { 		\
		setApp(new appname); \
		return load(vm, reserved); }


class wxApp {
	public:
		virtual void OnInit() = 0;
};

namespace wxAppMgr
{
	extern JNIEnv* Env;
	extern jobject Activity;
	extern jobject OptionsMenuClick;

	extern wxApp* Application;
	extern std::stack<jobject*> ActivityStack;
};

#endif // __WX_APP
