#include "wx/app.h"
#include "wx/wxjni.h"

class MyAPP : public wxApp
{
	virtual void OnInit() {
		LOGW("wxWidgets!");
	}
};

IMPLEMENT_APP(MyAPP);
