#include <wx/android_def.h>
#include <wx/android_object.h>
#include <wx/app.h>

//
// PROOF OF CONCEPT NOT FINAL IMPLEMENTATION
// NOTHING BESIDES NAME IS SIMILAR TO ACTUAL wxButton
// Base classes are not correct, this is just example...

class wxButton : wxAndroidObject
{
public:
	wxButton();
	~wxButton()
	{ wxAppMgr::Env->DeleteGlobalRef(m_object); }

	void SetLabel(jstring label);

	operator jobject() { return m_object; }
};
