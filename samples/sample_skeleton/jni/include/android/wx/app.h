#include "jni.h"
#include <stack>


#ifndef __WX_APP
#define __WX_APP

class wxApp {
	public:
		virtual void OnInit() = 0;
};

namespace wxAndroidApp
{
	JNIEnv* JNIEnv;
	jobject Activity;
	jobject OptionsMenuClick;

	wxApp* Application;
	std::stack<jobject*> ActivityStack;
};

#endif // __WX_APP
