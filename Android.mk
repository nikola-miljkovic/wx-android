LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := wxJNI
LOCAL_SRC_FILES := wxJNI.cpp 
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)