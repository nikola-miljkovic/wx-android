#include "wxJNI.h"

#ifndef __wx_app
#define "wxandroid/wx/app.h"
#endif

class MyAPP : public wxApp
{
	virtual void onStart() {
		LOGW("wxWidgets!");
	}
};

IMPLEMENT_APP(MyAPP);
