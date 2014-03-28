#include <jni.h>
#include <wxandroid/wx/app.h>

#ifndef __android_def
#define __android_def


// Android class binds

// activity
#define BIND_ACTIVITY			"android/app/Activity"

// parents
#define BIND_LINEAR_LAYOUT 	"android/widget/LinearLayout"

// child components
#define BIND_BUTTON 			"android/widget/Button"

#define BIND_BUTTON_CONSTRUCTOR_ARGS "(Landroid/content/Context;)V"

#define BIND_TEXTCTRL "android/widget/TextView"

#define BIND_TEXTCTRL_CONSTRUCTOR_ARGS "(Landroid/content/Context;)V"


#define BIND_TOAST "android/widget/Toast"

//Not being used currently but has been defined for uniformity
#define BIND_TOAST_CONSTRUCTOR_ARGS "(Landroid/content/Context;)V"

//binding to the MotionEvent class for unpacking Motion Events and aiding in handling of Touch Events
#define BIND_MOTION_EVENT "android/view/MotionEvent"
#endif // __android_def
