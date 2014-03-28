/*
 * motionevent.cpp
 *
 *  Created on: Mar 29, 2014
 *      Author: Melroy Tellis
 */

#include <wxandroid/wx/motionevent.h>

wxMotionEvent::wxMotionEvent(jobject obj)
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	m_class=env->FindClass(BIND_MOTION_EVENT);
	m_object=obj;
}

jfloat wxMotionEvent::getRawX()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID getRawXMethod = env->GetMethodID(m_class, "getRawX", "()F");
	return env->CallFloatMethod(m_object,getRawXMethod);
}

jfloat wxMotionEvent::getRawY()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID getRawYMethod = env->GetMethodID(m_class, "getRawY", "()F");
	return env->CallFloatMethod(m_object,getRawYMethod);
}





