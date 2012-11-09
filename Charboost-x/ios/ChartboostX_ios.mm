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

#include "ChartboostX.h"

#import "Chartboost.h"

// ChartboostDelegateBridge
@interface ChartboostDelegateBridge : NSObject<ChartboostDelegate>
@end
static ChartboostDelegateBridge* s_pDelegateBridge = nil;

static ChartboostX* s_pChartboostX = NULL;

ChartboostX* ChartboostX::sharedChartboostX()
{
    if (s_pChartboostX == NULL)
    {
        s_pChartboostX = new ChartboostX();
        s_pDelegateBridge = [[ChartboostDelegateBridge alloc] init];
        [[Chartboost sharedChartboost] setDelegate:s_pDelegateBridge];
    }
    return s_pChartboostX;
}

void ChartboostX::purgeChartboostX()
{
    CC_SAFE_DELETE(s_pChartboostX);
    [s_pDelegateBridge dealloc];
}


void ChartboostX::setAppId(const char * appId)
{
    Chartboost *cb = [Chartboost sharedChartboost];
    cb.appId = [NSString stringWithUTF8String:appId];
}

void ChartboostX::setAppSignature(const char * appSignature)
{
    Chartboost *cb = [Chartboost sharedChartboost];
    cb.appSignature = [NSString stringWithUTF8String:appSignature];
}

void ChartboostX::startSession()
{
    Chartboost *cb = [Chartboost sharedChartboost];
    [cb startSession];
}

void ChartboostX::cacheInterstitial(const char* location)
{
    Chartboost *cb = [Chartboost sharedChartboost];
    if (location) {
        [cb cacheInterstitial : [NSString stringWithUTF8String:location]];
    } else {
        [cb cacheInterstitial];
    }
}

void ChartboostX::showInterstitial(const char* location)
{
    Chartboost *cb = [Chartboost sharedChartboost];
    if (location) {
        [cb showInterstitial : [NSString stringWithUTF8String:location]];
    } else {
        [cb showInterstitial];
    }
}

bool ChartboostX::hasCachedInterstitial(const char* location)
{
    Chartboost *cb = [Chartboost sharedChartboost];
    if (location) {
        return [cb hasCachedInterstitial : [NSString stringWithUTF8String:location]];
    } else {
        return [cb hasCachedInterstitial];
    }
}

void ChartboostX::cacheMoreApps()
{
    Chartboost *cb = [Chartboost sharedChartboost];
    [cb cacheMoreApps];
}

void ChartboostX::showMoreApps()
{
    Chartboost *cb = [Chartboost sharedChartboost];
    [cb showMoreApps];
}

/*
 * Chartboost Delegate Methods
 *
 */
@implementation ChartboostDelegateBridge

- (BOOL)shouldRequestInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        return delegate->shouldRequestInterstitial([location UTF8String]);
    }

    return YES;
}

- (BOOL)shouldDisplayInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        return delegate->shouldDisplayInterstitial([location UTF8String]);
    }

    return YES;
}

- (void)didCacheInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didCacheInterstitial([location UTF8String]);
    }
}

- (void)didFailToLoadInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didFailToLoadInterstitial([location UTF8String]);
    }
}

- (void)didDismissInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didDismissInterstitial([location UTF8String]);
    }
}

- (void)didCloseInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didCloseInterstitial([location UTF8String]);
    }
}

- (void)didClickInterstitial:(NSString *)location {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didClickInterstitial([location UTF8String]);
    }
}

- (BOOL)shouldDisplayLoadingViewForMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        return delegate->shouldDisplayLoadingViewForMoreApps();
    }
    
    return YES;
}

- (BOOL)shouldDisplayMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        return delegate->shouldDisplayMoreApps();
    }
    
    return YES;
}

- (void)didCacheMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didCacheMoreApps();
    }
}

- (void)didFailToLoadMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didFailToLoadMoreApps();
    }
}

- (void)didDismissMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didDismissMoreApps();
    }
}

- (void)didCloseMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didCloseMoreApps();
    }
}

- (void)didClickMoreApps {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        delegate->didClickMoreApps();
    }
}

- (BOOL)shouldRequestInterstitialsInFirstSession {
    if (ChartboostXDelegate* delegate = ChartboostX::sharedChartboostX()->getDelegate()) {
        return delegate->shouldRequestInterstitialsInFirstSession();
    }
    
    return YES;
}

@end


