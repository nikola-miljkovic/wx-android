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
 *
 */
#include <wx/wxjni.h>

void setApp(wxApp* application) {
	wxAppMgr::Application = application;
}

jint
Java_org_wxwidgets_MainActivity_wxStart( JNIEnv* env,
													  jobject thiz)
{
	wxAppMgr::Env = env;
	wxAppMgr::Activity = env->NewGlobalRef(thiz);
	wxAppMgr::OptionsMenuClick = NULL;

	if(wxAppMgr::ActivityStack.size() == 0) {
		if(wxAppMgr::Application) {
			wxAppMgr::Application->OnInit();
		}
	}
	else {

	}

	wxAppMgr::ActivityStack.push(&thiz);
	return wxAppMgr::ActivityStack.size();
}

void
Java_org_wxwidgets_MainActivity_handleEvent( JNIEnv* env,jobject thiz,
													  jint code,jobject obj)
{
}

void
Java_org_wxwidgets_MainActivity_onCreateOMenu( JNIEnv* env,jobject thiz,
													  jobject obj)
{
}
