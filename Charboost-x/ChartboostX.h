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

class ChartboostXDelegate {
public:
    virtual ~ChartboostXDelegate() {}
    
    /**
     * Interstital
     */
    
    // Called before requesting an interestitial from the back-end
    // In Android, this method is called in UI Thread
    // In Android, the param "location" will always be '\0'
    virtual bool shouldRequestInterstitial(const char* location) { return true; }
    
    // Called when an interstitial has been received, before it is presented on screen
    // Return false if showing an interstitial is currently innapropriate, for example if the user has entered the main game mode.
    // In Android, this method is called in UI Thread
    // In Android, the param "location" will always be '\0'
    virtual bool shouldDisplayInterstitial(const char* location) { return true; }
    
    // Called when an interstitial has been received and cached.
    // In Android, this method will only be called if you call ChartboostX::hasCachedInterstitial(const char* location) first
    virtual void didCacheInterstitial(const char* location) {}
    
    // Called when an interstitial has failed to come back from the server
    // In Android, the param "location" will always be '\0'
    virtual void didFailToLoadInterstitial(const char* location) {}
    
    // Called when the user dismisses the interstitial
    // If you are displaying the add yourself, dismiss it now.
    // In Android, the param "location" will always be '\0'
    virtual void didDismissInterstitial(const char* location) {}
    
    // Same as above, but only called when dismissed for a close
    // In Android, the param "location" will always be '\0'
    virtual void didCloseInterstitial(const char* location) {}
    
    // Same as above, but only called when dismissed for a click
    // In Android, the param "location" will always be '\0'
    virtual void didClickInterstitial(const char* location) {}
    
    /**
     * More apps
     */
    
    // Called before requesting the more apps view from the back-end
    // Return false if when showing the loading view is not the desired user experience.
    // In Android, this method is called in UI Thread
    virtual bool shouldDisplayLoadingViewForMoreApps() { return true; }
    
    // Called before requesting the more apps from the back-end
    // Return false if when showing the more apps is not the desired user experience.
    // Only valid in Android
    // In Android, this method is called in UI Thread
    virtual bool shouldRequestMoreApps() { return true; }
    
    // Called when an more apps page has been received, before it is presented on screen
    // Return false if showing the more apps page is currently innapropriate
    // In Android, this method is called in UI Thread
    virtual bool shouldDisplayMoreApps() { return true; }
    
    // Called when the More Apps page has been received and cached
    // Only valid in iOS
    virtual void didCacheMoreApps() {}
    
    // Called when a more apps page has failed to come back from the server
    virtual void didFailToLoadMoreApps() {}
    
    // Called when the user dismisses the more apps view
    // If you are displaying the add yourself, dismiss it now.
    virtual void didDismissMoreApps() {}
    
    // Same as above, but only called when dismissed for a close
    virtual void didCloseMoreApps() {}
    
    // Same as above, but only called when dismissed for a click
    virtual void didClickMoreApps() {}
    
    // Whether Chartboost should show ads in the first session
    // Defaults to true
    // Only valid in iOS
    virtual bool shouldRequestInterstitialsInFirstSession() { return true; }
};

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
    void cacheInterstitial(const char* location = NULL);
    // Show an interstitial, optionally takes a location argument
    void showInterstitial(const char* location = NULL);
    // check if an interstitial is stored in cache for a default location, or a specific location
    // Only valid in iOS
    // In Android, it will always return false, if the interstitial has cached when call this method,
    // ChartboostXDelegate::didCacheInterstitial(const char* location) will be call-back.
    bool hasCachedInterstitial(const char* location = NULL);
    // Cache the More Apps page
    void cacheMoreApps();
    // Show the More Apps page
    void showMoreApps();
    
    void setDelegate(ChartboostXDelegate* delegate) { m_delegate = delegate; }
    ChartboostXDelegate* getDelegate() { return m_delegate; }
    
private:
    ChartboostX()
    : m_delegate(NULL)
    {
    }
    
    ChartboostXDelegate* m_delegate;
};

#endif
