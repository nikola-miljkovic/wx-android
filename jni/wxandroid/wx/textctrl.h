/*
 * wxTextCtrl.h
 *
 *  Created on: Mar 23, 2014
 *      Author: Tellis
 */
#ifndef __android_def
#include <wxandroid/wx/android_object.h>
#endif
class wxTextCtrl : wxAndroidObject
{
    public:
        wxTextCtrl();
	    void SetText(jstring text);

	    operator jobject() { return m_object; }
};


