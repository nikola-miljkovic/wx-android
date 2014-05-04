/*
 * motionevent.h
 *
 *  Created on: Mar 29, 2014
 *      Author: Melroy Tellis
 */

#include <wx/android_object.h>
#include <wx/app.h>

#ifndef MOTIONEVENT_H_
#define MOTIONEVENT_H_

class wxMotionEvent : wxAndroidObject
{
    public:
        wxMotionEvent();
	    jfloat getRawX();
	    jfloat getRawY();

	    void setObject(jobject object) { m_object = object; }
	    operator jobject() { return m_object; }
};

#endif /* MOTIONEVENT_H_ */
