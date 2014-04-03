LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := wxAndroid
LOCAL_SRC_FILES := $(LOCAL_PATH)/src/android/wxjni.cpp 
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/android
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)