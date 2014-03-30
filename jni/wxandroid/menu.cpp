#include <wxandroid/wx/menu.h>

wxMenu::wxMenu()
{

}

void wxMenu::AppendCheckItem(int id, const jstring & item)
{
	// add to some vector etc...->
	// now we do jni thing?
	JNIEnv* env = wxAndroidApp::JNIEnv;
	jmethodID add = env->GetMethodID(env->GetObjectClass(m_object), "add", BIND_MENU_ADD_ARGS);
	jobject menu_item = env->CallObjectMethod(m_object, add, 0, id, 0, item);
	jclass mi_class = env->GetObjectClass(menu_item);
	jmethodID setCheckable = env->GetMethodID(mi_class, "setCheckable", "(Z)Landroid/view/MenuItem;");
	jmethodID setChecked = env->GetMethodID(mi_class, "setChecked", "(Z)Landroid/view/MenuItem;");
	env->CallObjectMethod(menu_item, setCheckable, true);
	env->CallObjectMethod(menu_item, setChecked, false);

	//if(menu_item)
	{
		// Add event listener
	}

	// this would be cool :D :
	//return wxMenuItem(menu_item);
}
