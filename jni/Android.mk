LOCAL_PATH := $(call my-dir)
SOURCE_PATH := $(LOCAL_PATH)/src/android/

include $(CLEAR_VARS)

LOCAL_MODULE    := wxAndroid
LOCAL_SRC_FILES := $(SOURCE_PATH)/app.cpp\
    $(SOURCE_PATH)/wxjni.cpp\
    $(SOURCE_PATH)/android_object.cpp\
    $(SOURCE_PATH)/textctrl.cpp\
    $(SOURCE_PATH)/button.cpp\
    $(SOURCE_PATH)/motionevent.cpp\
    $(SOURCE_PATH)/notificationmsg.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/android
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)