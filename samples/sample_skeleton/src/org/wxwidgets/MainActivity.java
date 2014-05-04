package org.wxwidgets;

import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.MotionEvent;
import android.os.Bundle;


public class MainActivity extends Activity {
    private native int wxStart();
    public native void onCreateOMenu(Object obj);
    public static native void handleEvent(int code, Object obj);
	
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        wxStart();
    }
    
    static {
        System.loadLibrary("wxAndroid");
        System.loadLibrary("wxAPP");
    }   
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
    	handleEvent(2, event);
     	return true;
    }
   
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	onCreateOMenu(menu);
		return true;
	}
    
    public void startNew() {
    	Intent intent = new Intent(this, MainActivity.class);
    	startActivity(intent);
    }
}
