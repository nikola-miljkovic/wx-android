#include "jni.h"
#include <stack>


#ifndef __wx_app
#define __wx_app

class wxApp {
	public:
		virtual void onStart() = 0;
};

namespace wxAndroidApp
{
	JNIEnv* JNIEnv;
	jobject Activity;
	jobject OptionsMenuClick;

	wxApp* Application;
	std::stack<jobject*> ActivityStack;
};

#endif // __wx_app
