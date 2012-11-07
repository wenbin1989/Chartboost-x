/****************************************************************************
 Copyright (c) 2012      Wenbin Wang
 
 http://geeksavetheworld.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ChartboostXJni.h"

#define  CLASS_NAME "com/wenbin/ChartboostX/ChartboostXBridge"

using namespace cocos2d;

extern "C"
{
    
    void setAppIdJNI(const char * appId)
    {
        JniMethodInfo methodInfo;
        
		if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setAppId", "(Ljava/lang/String;)V"))
		{
			return;
		}
        jstring stringArg = methodInfo.env->NewStringUTF(appId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
    
    void setAppSignatureJNI(const char * appSignature)
    {
        JniMethodInfo methodInfo;
        
		if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "setAppSignature", "(Ljava/lang/String;)V"))
		{
			return;
		}
        jstring stringArg = methodInfo.env->NewStringUTF(appSignature);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
    
    void installJNI()
    {
		JniMethodInfo methodInfo;
        
		if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "install", "()V"))
		{
			return;
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
    
    void cacheInterstitialJNI(const char* location)
    {
        JniMethodInfo methodInfo;
        
        if (location) {
            if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cacheInterstitial", "(Ljava/lang/String;)V"))
            {
                return;
            }
            jstring stringArg = methodInfo.env->NewStringUTF(location);
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
            
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            methodInfo.env->DeleteLocalRef(stringArg);
        } else {
            if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cacheInterstitial", "()V"))
            {
                return;
            }
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
    }
    
    void showInterstitialJNI(const char* location)
	{
		JniMethodInfo methodInfo;

        if (location) {
            if (! JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showInterstitial", "(Ljava/lang/String;)V"))
            {
                return;
            }
            jstring stringArg = methodInfo.env->NewStringUTF(location);
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg);
            
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            methodInfo.env->DeleteLocalRef(stringArg);
        } else {
            if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showInterstitial", "()V"))
            {
                return;
            }
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
	}
    
    void cacheMoreAppsJNI()
	{
		JniMethodInfo methodInfo;
        
		if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cacheMoreApps", "()V"))
		{
			return;
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
    
    void showMoreAppsJNI()
	{
		JniMethodInfo methodInfo;
        
		if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showMoreApps", "()V"))
		{
			return;
		}
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}
