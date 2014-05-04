LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE 	:= wxJNI_shared
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libwxAndroid.so

include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := wxAPP
LOCAL_SRC_FILES := main.cpp 
LOCAL_LDLIBS    := -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/android
LOCAL_SHARED_LIBRARIES := wxJNI_shared

include $(BUILD_SHARED_LIBRARY)