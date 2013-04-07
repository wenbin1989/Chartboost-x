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

package com.wenbin.ChartboostX;

import java.lang.ref.WeakReference;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.util.Log;
import android.view.View;

import com.chartboost.sdk.*;

public class ChartboostXBridge {
    private static final String TAG = "ChartboostX";
    private static WeakReference<Cocos2dxActivity> s_activity;
    private static ChartBoost s_chartBoost;

    private static native boolean shouldRequestInterstitial(String location);
    private static native boolean shouldDisplayInterstitial(String location);
    private static native void didCacheInterstitial(String location);
    private static native void didFailToLoadInterstitial(String location);
    private static native void didDismissInterstitial(String location);
    private static native void didCloseInterstitial(String location);
    private static native void didClickInterstitial(String location);
    private static native boolean shouldDisplayLoadingViewForMoreApps();
    private static native boolean shouldRequestMoreApps();
    private static native boolean shouldDisplayMoreApps();
    private static native void didFailToLoadMoreApps();
    private static native void didDismissMoreApps();
    private static native void didCloseMoreApps();
    private static native void didClickMoreApps();
    
    // the method must be called in main thread, before any other method
    public static void initChartboostXBridge(Cocos2dxActivity activity){
        ChartboostXBridge.s_activity = new WeakReference<Cocos2dxActivity>(activity);
        ChartboostXBridge.s_chartBoost = ChartBoost.getSharedChartBoost(ChartboostXBridge.s_activity.get());
        ChartboostXBridge.s_chartBoost.setDelegate(ChartboostXBridge.s_chartBoostDelegate);
    }
    
    public static void setAppId(String appId) {
        Log.v(TAG, "setAppId() is called... appId = " + appId);
        
        if (s_chartBoost != null) {
            s_chartBoost.setAppId(appId);
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void setAppSignature(String appSignature) {
        Log.v(TAG, "setAppSignature() is called... appSignature = " + appSignature);
        
        if (s_chartBoost != null) {
            s_chartBoost.setAppSignature(appSignature);
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void install() {
        Log.v(TAG, "install() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.install();
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void cacheInterstitial() {
        Log.v(TAG, "cacheInterstitial() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.cacheInterstitial();
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void cacheInterstitial(final String location) {
        Log.v(TAG, "cacheInterstitial(\"" + location + "\") is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.cacheInterstitial(location);
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void showInterstitial() {
        Log.v(TAG, "showInterstitial() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.showInterstitial();
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void showInterstitial(final String location) {
        Log.v(TAG, "showInterstitial(\"" + location + "\") is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.showInterstitial(location);
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void hasCachedInterstitial() {
        Log.v(TAG, "hasCachedInterstitial() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    if (s_chartBoost.hasCachedInterstitial()) {
                        ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                            public void run() {
                                ChartboostXBridge.didCacheInterstitial("Default");
                            }
                        });
                    }
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void hasCachedInterstitial(final String location) {
        Log.v(TAG, "hasCachedInterstitial(\"" + location + "\") is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    if (s_chartBoost.hasCachedInterstitial(location)) {
                        ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                            public void run() {
                                ChartboostXBridge.didCacheInterstitial(location);
                            }
                        });
                    }
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void cacheMoreApps() {
        Log.v(TAG, "cacheMoreApps() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.cacheMoreApps();
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    public static void showMoreApps() {
        Log.v(TAG, "showMoreApps() is called...");
        
        if (s_chartBoost != null) {
            ChartboostXBridge.s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                    s_chartBoost.showMoreApps();
                }
            });
        } else {
            Log.w(TAG, "Abort! cannot get shared Chartboost!");
        }
    }
    
    static private ChartBoostDelegate s_chartBoostDelegate = new ChartBoostDelegate() {
        /**
         * Interstital
         */
        @Override
        public boolean shouldRequestInterstitial()
        {
            return ChartboostXBridge.shouldRequestInterstitial("");
        }

        @Override
        public boolean shouldDisplayInterstitial(View interstitialView)
        {
            return ChartboostXBridge.shouldDisplayInterstitial("");
        }
        
        @Override
        public void didFailToLoadInterstitial()
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didFailToLoadInterstitial("");
                }
            });
        }

        @Override
        public void didDismissInterstitial(View interstitialView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didDismissInterstitial("");
                }
            });
        }
        
        @Override
        public void didCloseInterstitial(View interstitialView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didCloseInterstitial("");
                }
            });
        }

        @Override
        public void didClickInterstitial(View interstitialView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didClickInterstitial("");
                }
            });
        }

        /**
         * More Apps
         */
        @Override 
        public boolean shouldDisplayLoadingViewForMoreApps()
        {
            return ChartboostXBridge.shouldDisplayLoadingViewForMoreApps();
        }
        
        @Override
        public boolean shouldRequestMoreApps() {
            
            return ChartboostXBridge.shouldRequestMoreApps();
        }
        
        @Override
        public boolean shouldDisplayMoreApps(View interstitialView)
        {
            return ChartboostXBridge.shouldDisplayMoreApps();
        }
        
        @Override
        public void didFailToLoadMoreApps()
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didFailToLoadMoreApps();
                }
            });
        }

        @Override
        public void didDismissMoreApps(View moreAppsView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didDismissMoreApps();
                }
            });
        }
        
        @Override
        public void didCloseMoreApps(View interstitialView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didCloseMoreApps();
                }
            });
        }

        @Override
        public void didClickMoreApps(View moreAppsView)
        {
            ChartboostXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                    ChartboostXBridge.didClickMoreApps();
                }
            });
        }       
    };
}
