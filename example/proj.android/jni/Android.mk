LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellochartboostx_shared

LOCAL_MODULE_FILENAME := libhellochartboostx

LOCAL_SRC_FILES := hellochartboostx/main.cpp \
				   ChartboostX_android.cpp \
				   ChartboostXJni.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)

