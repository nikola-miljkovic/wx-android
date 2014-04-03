#include <jni.h>

#ifndef __WX_ANDROID_OBJECT
#define __WX_ANDROID_OBJECT

class wxAndroidObject
{
public:
	jobject m_object;
	jclass m_class;
};

#endif // __WX_ANDROID_OBJECT
