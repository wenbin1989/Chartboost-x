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


#ifndef ChartboostX_ChartboostXJni_h
#define ChartboostX_ChartboostXJni_h

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>

extern "C"
{
    extern void setAppIdJNI(const char * appId);
    extern void setAppSignatureJNI(const char * appSignature);
    extern void installJNI();
    extern void cacheInterstitialJNI(const char* location);
    extern void showInterstitialJNI(const char* location);
    extern void hasCachedInterstitialJNI(const char* location);
    extern void cacheMoreAppsJNI();
    extern void showMoreAppsJNI();
}

#endif // __FF_UTILS_JNI__
