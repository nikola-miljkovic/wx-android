#ifndef __android_def
#include <wxandroid/wx/android_object.h>
#endif

//
// PROOF OF CONCEPT NOT FINAL IMPLEMENTATION
// NOTHING BESIDES NAME IS SIMILAR TO ACTUAL wxButton
// Base classes are not correct, this is just example...

class wxButton : wxAndroidObject
{
public:
	wxButton();

	void SetLabel(jstring label);

	operator jobject() { return m_object; }
};
