#include "wx/app.h"

// include this because of logging
#include "wx/wxjni.h"

class MyAPP : public wxApp
{
	virtual void OnInit() {
		LOGW("wxWidgets!");
	}
};

IMPLEMENT_APP(MyAPP);
