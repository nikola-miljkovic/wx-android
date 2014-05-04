package org.wxwidgets;

import android.view.View;
import android.view.View.OnClickListener;

public class OnClick implements OnClickListener {

	@Override
	public void onClick(View arg0) {
    	MainActivity.handleEvent(1, arg0);
	}
}
