#include <wxandroid/wx/android_object.h>

//
// PROOF OF CONCEPT NOT FINAL IMPLEMENTATION
// NOTHING BESIDES NAME IS SIMILAR TO ACTUAL wxButton
// Base classes are not correct, this is just example...

class wxButton : wxAndroidObject
{
public:
	wxButton();

	void SetLabel(const char* label);

	operator jobject() { return m_object; }
};
