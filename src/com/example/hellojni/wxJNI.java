/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.example.hellojni;

import android.app.Activity;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.TextView;
import android.os.Bundle;


public class wxJNI extends Activity implements OnClickListener  {
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        /* Create a TextView and set its content.
         * the text is retrieved by calling a native
         * function.
         */
        int i = wxStart("wxButton");
        System.out.println(i);
    }

    
    private native int wxStart(String label);
    // not sure if static actually does anything here?
    public native void handleEvent(int code, Object obj);
    
    static {
        System.loadLibrary("wxJNI");
    }   
    
    @Override
	public void onClick(View arg0) {
		handleEvent(1, arg0);
	}
    
    @Override
    public boolean onTouchEvent(MotionEvent event) {
    	// lets imagine it gets processed
    	// unpack event ->
    	handleEvent(2, null);
    	return true;
    }
}
