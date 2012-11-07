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

import android.content.Context;
import android.os.Handler;
import android.util.Log;

import com.chartboost.sdk.*;

public class ChartboostXBridge {
	private static final String TAG = "ChartboostX";
	private static Context s_sessionContext;
	private static ChartBoost s_chartBoost;
	private static Handler s_handler;
	
	// the method must be called in main thread
	public static void setContext(Context context){
		ChartboostXBridge.s_sessionContext = context;
		ChartboostXBridge.s_chartBoost = ChartBoost.getSharedChartBoost(ChartboostXBridge.s_sessionContext);
	}
	// handler must be created in main thread
	public static void setHandler(Handler handler){
		ChartboostXBridge.s_handler = handler;
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
			s_handler.post(new Runnable() {
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
			s_handler.post(new Runnable() {
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
			s_handler.post(new Runnable() {
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
			s_handler.post(new Runnable() {
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
			s_handler.post(new Runnable() {
				 public void run() {
					 s_chartBoost.showInterstitial(location);
				 }
			 });
		} else {
			Log.w(TAG, "Abort! cannot get shared Chartboost!");
		}
	}
	
	public static void cacheMoreApps() {
		Log.v(TAG, "cacheMoreApps() is called...");
		
		if (s_chartBoost != null) {
			s_handler.post(new Runnable() {
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
			s_handler.post(new Runnable() {
				 public void run() {
					 s_chartBoost.showMoreApps();
				 }
			 });
		} else {
			Log.w(TAG, "Abort! cannot get shared Chartboost!");
		}
	}
}
