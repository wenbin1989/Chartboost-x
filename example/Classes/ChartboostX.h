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


#ifndef ChartboostX_ChartboostX_h
#define ChartboostX_ChartboostX_h

#include "cocos2d.h"

class ChartboostX {
    
public:
    static ChartboostX* sharedChartboostX();
    static void purgeChartboostX();
    
    // set app id
    void setAppId(const char * appId);
    // set app signature
    void setAppSignature(const char * appSignature);
    /*
     * Begin a user session.
     *
     * Wrapper startSession method in iOS Chartboost SDK, and install() methon in Android Chartboost SDK
     * 
     * This should be done once per boot.
     */
    void startSession();
    // Cache an interstitial, optionally takes a location argument
    void cacheInterstitial(const char* location = 0);
    // Show an interstitial, optionally takes a location argument
    void showInterstitial(const char* location = 0);
    // Cache the More Apps page
    void cacheMoreApps();
    // Show the More Apps page
    void showMoreApps();
    
private:
    ChartboostX()
    {
    }
};

#endif
