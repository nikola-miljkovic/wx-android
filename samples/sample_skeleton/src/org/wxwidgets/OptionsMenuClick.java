package org.wxwidgets;

import android.view.MenuItem;
import android.view.MenuItem.OnMenuItemClickListener;

public class OptionsMenuClick implements OnMenuItemClickListener {

	@Override
	public boolean onMenuItemClick(MenuItem item) {
		if(item.isCheckable())
			item.setChecked(!item.isChecked());
		
		return false;
	}
}
