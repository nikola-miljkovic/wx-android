/*
 * motionevent.h
 *
 *  Created on: Mar 29, 2014
 *      Author: Melroy Tellis
 */

#ifndef __android_def
#include <wxandroid/wx/android_object.h>
#endif

#ifndef MOTIONEVENT_H_
#define MOTIONEVENT_H_

class wxMotionEvent : wxAndroidObject
{
    public:
        wxMotionEvent(jobject obj);
	    jfloat getRawX();
	    jfloat getRawY();
	    operator jobject() { return m_object; }
};

#endif /* MOTIONEVENT_H_ */
