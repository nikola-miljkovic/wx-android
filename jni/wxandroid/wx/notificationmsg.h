/*
 * NotificationMsg.h
 *
 *  Created on: Mar 27, 2014
 *      Author: Melroy Tellis
 */
#ifndef __android_def
#include <wxandroid/wx/android_object.h>
#endif
#define NOTIFICATION_DURATION_SHORT 0
#define NOTIFICATION_DURATION_LONG 1
class wxNotificationMsg : wxAndroidObject
{
    public:
        wxNotificationMsg(jstring text,jint duration);
        ~wxNotificationMsg()
        { wxAndroidApp::JNIEnv->DeleteGlobalRef(m_object); }

	    void show();
	    operator jobject() { return m_object; }
};
