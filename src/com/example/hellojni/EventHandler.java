package com.example.hellojni;

import android.view.View;
import android.view.View.OnClickListener;

public class EventHandler implements OnClickListener {

	@Override
	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		NativeEvent.handleEvent(1, arg0);
	}
}
