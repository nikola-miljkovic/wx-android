#ifndef __ANDROID_DEF
#define __ANDROID_DEF

// Android class binds

// activity
#define BIND_ACTIVITY			"android/app/Activity"

#define FILL_PARENT			0xffffffff
// parents
#define BIND_LINEAR_LAYOUT 	"android/widget/LinearLayout"

#define BIND_MENU_VIEW			"android/view/Menu"
#define BIND_MENU_ADD_ARGS     "(IIILjava/lang/CharSequence;)Landroid/view/MenuItem;"

#define BIND_OPTIONS_MENU_CLICK "org/wxwidgets/OptionsMenuClick"
#define BIND_MENU_ONCLICKLISTENER_ARGS "(Landroid/view/MenuItem$OnMenuItemClickListener;)Landroid/view/MenuItem;"
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

#endif // __ANDROID_DEF
