/*
 * motionevent.cpp
 *
 *  Created on: Mar 29, 2014
 *      Author: Melroy Tellis
 */

#include <wxandroid/wx/motionevent.h>

wxMotionEvent::wxMotionEvent()
{
}

jfloat wxMotionEvent::getRawX()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID getRawXMethod = env->GetMethodID(env->GetObjectClass(m_object), "getRawX", "()F");
	return env->CallFloatMethod(m_object,getRawXMethod);
}

jfloat wxMotionEvent::getRawY()
{
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID getRawYMethod = env->GetMethodID(env->GetObjectClass(m_object), "getRawY", "()F");
	return env->CallFloatMethod(m_object,getRawYMethod);
}





