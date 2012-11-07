![Chartboost Icon](http://chartboost.com/img/web/logo_172x90.png) ==> ![-X Icon](http://pic.yupoo.com/diwup_v/BY5waKBY/MC5wD.png)

#ChartboostX
A C++ wrapper of [Chartboost](http://chartboost.com//) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

#Environment

* ###Chartboost SDK
	* Android: v3.0.1
	* iOS: v3.1.1

* ###cocos2d-x
	* cocos2d-2.0-rc0a-x-2.0 or higher

#Example Project
1. iOS: example/proj.ios/HelloChartboostX.xcodeproj
2. Android: example/proj.android

***You need to change the build script (such as build_native.sh) according to your own environment before compiling***.

#Add to Your Own Project

***iOS and Android will share the same `ChartboostX.h` header file. You need add `Charboost-x/ChartboostX.h` to your `Classes` folder in the beginning.***

### iOS

All the following files you need in iOS are in `Charboost-x/ios` fold.

1. Add the previous `ChartboostX.h` to your Xcode project
2. Add `CBAnalytics.h`, `Chartboost.h`, `ChartboostX_ios.mm`, `libChartboost.a` to your Xcode project
3. Ensure you're linking with the following libraries:
	* SystemConfiguration.framework
	* StoreKit.framework (weak-link)
	* AdSupport.framework (weak-link, needed in iOS 6)

### Android

All the following files you need in Android are in `Charboost-x/android` fold.

1. Add the package `com.wenbin.ChartboostX` and its `ChartboostXBridge.java` to your Eclipse project.
*(You can just copy the whole `com` fold to `src` fold in Eclipse project, and refresh in Eclipse)*
2. Add the `ChartBoost.jar` file as an external jar to your project.
*(You can just copy the `ChartBoost.jar` file to `libs` fold in Eclipse project, and refresh in Eclipse)*
3. Add `ChartboostX_android.cpp`, `ChartboostXJni.cpp` and `ChartboostXJni.h` to your `jni` fold.
4. Add `ChartboostX_android.cpp`, `ChartboostXJni.cpp` to your jni's `Android.mk`.
5. In the java implementation of your main activity (which should have been created by the Cocos2d-X script), `import android.os.Handler;` and `import com.wenbin.ChartboostX.*;`
6. At the beginning of `onCreate(Bundle savedInstanceState)`, right after `super.onCreate(savedInstanceState)`, add the following code:

		ChartboostXBridge.setContext(this);
		ChartboostXBridge.setHandler(new Handler());

7. Add the following code to your main activity:
s
		@Override 
		protected void onResume()
		{
			super.onResume();
			ChartboostXBridge.setContext(this);
		}

8. Add the following xml to your Android Manifest file:

Add permission:

		<uses-permission android:name="android.permission.INTERNET" />

Add activity:
	
		<activity android:name="com.chartboost.sdk.CBDialogActivity"
			android:configChanges="orientation|keyboard|keyboardHidden"
			android:windowSoftInputMode="adjustResize"
			android:theme="@android:style/Theme.Translucent"
			android:launchMode="singleTop" 
			>
		</activity>

#Email: <wenbin1989@gmail.com>
#Blog: <http://geeksavetheworld.com>

#You're welcome to contribute. ;-)
