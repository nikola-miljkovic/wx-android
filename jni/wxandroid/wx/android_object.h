#include <wxandroid/wx/android_def.h>

#ifndef __wx_android_object
#define __wx_android_object

class wxAndroidObject
{
public:
	// BIND_DROID
	//wxAndroidObject(const char* bind);

	jobject m_object;
	jclass m_class;
};

#endif // __wx_android_object
