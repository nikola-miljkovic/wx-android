#include "jni.h"

#include <stack>

namespace wxAndroidApp
{
	JNIEnv* JNIEnv;
	jobject Activity;
	jobject OptionsMenuClick;

	std::stack<jobject*> ActivityStack;
};
