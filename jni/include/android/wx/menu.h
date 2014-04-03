#ifndef __ANDROID_DEF
#include <android_object.h>
#endif

class wxMenu : wxAndroidObject
{
    public:
        wxMenu();
        ~wxMenu()
        { wxAndroidApp::JNIEnv->DeleteGlobalRef(m_object); }

        // imagine wxMenuItem* instead of void :P and wxstring instead of jstring
	    void AppendCheckItem(int id,
	    		const jstring & item);
	    		//const jstring & help = "HELP"); wxString is needed here :)

	    void setObject(jobject object) { m_object = object; }
	    operator jobject() { return m_object; }
};
