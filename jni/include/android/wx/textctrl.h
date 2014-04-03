/*
 * wxTextCtrl.h
 *
 *  Created on: Mar 23, 2014
 *      Author: Tellis
 */
#include "jni.h"
#ifndef __android_def
	#include <wx/android_object.h>
	#include <wx/android_def.h>
#endif

#include "wx/app.h"

class wxTextCtrl : wxAndroidObject
{
    public:
        wxTextCtrl();
        ~wxTextCtrl()
        { wxAndroidApp::JNIEnv->DeleteGlobalRef(m_object); }

	    void SetText(jstring text);

	    operator jobject() { return m_object; }
};


