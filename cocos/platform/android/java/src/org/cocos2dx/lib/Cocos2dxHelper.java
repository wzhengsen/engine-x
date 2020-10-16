/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

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
package org.cocos2dx.lib;

import android.Manifest;
import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.DialogInterface;
import android.content.IntentFilter;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.graphics.Color;
import android.graphics.Rect;
import android.graphics.drawable.Icon;
import android.media.AudioAttributes;
import android.media.AudioManager;
import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.net.ConnectivityManager;
import android.net.NetworkCapabilities;
import android.net.NetworkInfo;
import android.net.Uri;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.BatteryManager;
import android.os.Build;
import android.os.Environment;
import android.os.IBinder;
import android.os.ParcelFileDescriptor;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.preference.PreferenceManager.OnActivityResultListener;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.Display;
import android.view.DisplayCutout;
import android.view.KeyCharacterMap;
import android.view.KeyEvent;
import android.view.ViewConfiguration;
import android.view.Window;
import android.view.WindowManager;

import com.android.vending.expansion.zipfile.APKExpansionSupport;
import com.android.vending.expansion.zipfile.ZipResourceFile;

import com.baidu.location.BDAbstractLocationListener;
import com.baidu.location.BDLocation;
import com.baidu.location.LocationClient;
import com.baidu.location.LocationClientOption;
import com.enhance.gameservice.IGameTuningService;

import java.io.IOException;
import java.io.File;
import java.io.FilenameFilter;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.nio.charset.StandardCharsets;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Locale;
import java.util.Set;


public class Cocos2dxHelper {
    // ===========================================================
    // Constants
    // ===========================================================
    private static final String PREFS_NAME = "Cocos2dxPrefsFile";
    private static final int RUNNABLES_PER_FRAME = 5;
    private static final String TAG = Cocos2dxHelper.class.getSimpleName();

    // ===========================================================
    // Fields
    // ===========================================================
    private static AssetManager sAssetManager;
    private static Cocos2dxAccelerometer sCocos2dxAccelerometer = null;
    private static boolean sAccelerometerEnabled;
    private static boolean sCompassEnabled;
    private static boolean sActivityVisible;
    private static String sPackageName;
    private static Cocos2dxActivity sActivity = null;
    private static Cocos2dxHelperListener sCocos2dxHelperListener;
    private static Set<OnActivityResultListener> onActivityResultListeners = new LinkedHashSet<OnActivityResultListener>();
    private static Vibrator sVibrateService = null;
    private static ClipboardManager sClipboardService = null;
    private static ConnectivityManager sConnectivityService = null;
    private static WifiManager sWifiService = null;
    private static TelephonyManager sTelephonyService = null;
    private static NotificationManager sNotifyService = null;
    private static Intent sIntentBattery = null;
    //Enhance API modification begin
    private static IGameTuningService mGameServiceBinder = null;
    private static final int BOOST_TIME = 7;
    //Enhance API modification end

    // The absolute path to the OBB if it exists, else the absolute path to the APK.
    private static String sAssetsPath = "";

    // The OBB file
    private static ZipResourceFile sOBBFile = null;

    // ===========================================================
    // Constructors
    // ===========================================================

    public static void runOnGLThread(final Runnable r) {
        ((Cocos2dxActivity) sActivity).runOnGLThread(r);
    }

    private static boolean sInited = false;

    public static void init(final Cocos2dxActivity activity) {
        sActivity = activity;
        Cocos2dxHelper.sCocos2dxHelperListener = (Cocos2dxHelperListener) activity;
        if (!sInited) {

            PackageManager pm = activity.getPackageManager();
            boolean isSupportLowLatency = pm.hasSystemFeature(PackageManager.FEATURE_AUDIO_LOW_LATENCY);

            Log.d(TAG, "isSupportLowLatency:" + isSupportLowLatency);

            int sampleRate = 44100;
            int bufferSizeInFrames = 192;

            if (Build.VERSION.SDK_INT >= 17) {
                AudioManager am = (AudioManager) activity.getSystemService(Context.AUDIO_SERVICE);
                // use reflection to remove dependence of API 17 when compiling

                // AudioManager.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE);
                final Class audioManagerClass = AudioManager.class;
                Object[] parameters = new Object[]{Cocos2dxReflectionHelper.<String>getConstantValue(audioManagerClass, "PROPERTY_OUTPUT_SAMPLE_RATE")};
                final String strSampleRate = Cocos2dxReflectionHelper.<String>invokeInstanceMethod(am, "getProperty", new Class[]{String.class}, parameters);

                // AudioManager.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER);
                parameters = new Object[]{Cocos2dxReflectionHelper.<String>getConstantValue(audioManagerClass, "PROPERTY_OUTPUT_FRAMES_PER_BUFFER")};
                final String strBufferSizeInFrames = Cocos2dxReflectionHelper.<String>invokeInstanceMethod(am, "getProperty", new Class[]{String.class}, parameters);

                try {
                    sampleRate = Integer.parseInt(strSampleRate);
                    bufferSizeInFrames = Integer.parseInt(strBufferSizeInFrames);
                } catch (NumberFormatException e) {
                    Log.e(TAG, "parseInt failed", e);
                }
                Log.d(TAG, "sampleRate: " + sampleRate + ", framesPerBuffer: " + bufferSizeInFrames);
            } else {
                Log.d(TAG, "android version is lower than 17");
            }

            nativeSetAudioDeviceInfo(isSupportLowLatency, sampleRate, bufferSizeInFrames);

            final ApplicationInfo applicationInfo = activity.getApplicationInfo();

            Cocos2dxHelper.sPackageName = applicationInfo.packageName;

            Cocos2dxHelper.sAssetManager = activity.getAssets();
            Cocos2dxHelper.nativeSetContext((Context) activity, Cocos2dxHelper.sAssetManager);

            Cocos2dxBitmap.setContext(activity);

            sVibrateService = (Vibrator) activity.getSystemService(Context.VIBRATOR_SERVICE);
            sClipboardService = (ClipboardManager) activity.getSystemService(Context.CLIPBOARD_SERVICE);
            sWifiService = (WifiManager) activity.getSystemService(Context.WIFI_SERVICE);
            sConnectivityService = (ConnectivityManager) activity.getSystemService(Context.CONNECTIVITY_SERVICE);
            sTelephonyService = (TelephonyManager)activity.getSystemService(Context.TELEPHONY_SERVICE);
            sNotifyService = (NotificationManager)sActivity.getSystemService(Context.NOTIFICATION_SERVICE);

            // 通过粘性广播读取电池信息。
            // 注意，粘性广播不需要广播接收器。
            Cocos2dxHelper.sIntentBattery = activity.registerReceiver(null, new IntentFilter(Intent.ACTION_BATTERY_CHANGED));

            sInited = true;

            //Enhance API modification begin
            Intent serviceIntent = new Intent(IGameTuningService.class.getName());
            serviceIntent.setPackage("com.enhance.gameservice");
            boolean suc = activity.getApplicationContext().bindService(serviceIntent, connection, Context.BIND_AUTO_CREATE);
            //Enhance API modification end
        }
    }

    // This function returns the absolute path to the OBB if it exists,
    // else it returns the absolute path to the APK.
    public static String getAssetsPath() {
        if (Cocos2dxHelper.sAssetsPath.equals("")) {

            String pathToOBB = Environment.getExternalStorageDirectory().getAbsolutePath() + "/Android/obb/" + Cocos2dxHelper.sPackageName;

            // Listing all files inside the folder (pathToOBB) where OBB files are expected to be found.
            String[] fileNames = new File(pathToOBB).list(new FilenameFilter() { // Using filter to pick up only main OBB file name.
                public boolean accept(File dir, String name) {
                    return name.startsWith("main.") && name.endsWith(".obb");  // It's possible to filter only by extension here to get path to patch OBB file also.
                }
            });

            String fullPathToOBB = "";
            if (fileNames != null && fileNames.length > 0)  // If there is at least 1 element inside the array with OBB file names, then we may think fileNames[0] will have desired main OBB file name.
                fullPathToOBB = pathToOBB + "/" + fileNames[0];  // Composing full file name for main OBB file.

            File obbFile = new File(fullPathToOBB);
            if (obbFile.exists())
                Cocos2dxHelper.sAssetsPath = fullPathToOBB;
            else
                Cocos2dxHelper.sAssetsPath = Cocos2dxHelper.sActivity.getApplicationInfo().sourceDir;
        }

        return Cocos2dxHelper.sAssetsPath;
    }

    public static ZipResourceFile getObbFile() {
        if (null == sOBBFile) {
            int versionCode = 1;
            try {
                versionCode = Cocos2dxActivity.getContext().getPackageManager().getPackageInfo(Cocos2dxHelper.getCocos2dxPackageName(), 0).versionCode;
            } catch (NameNotFoundException e) {
                e.printStackTrace();
            }

            try {
                sOBBFile = APKExpansionSupport.getAPKExpansionZipFile(Cocos2dxActivity.getContext(), versionCode, 0);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return sOBBFile;
    }

    //Enhance API modification begin
    private static ServiceConnection connection = new ServiceConnection() {
        public void onServiceConnected(ComponentName name, IBinder service) {
            mGameServiceBinder = IGameTuningService.Stub.asInterface(service);
            fastLoading(BOOST_TIME);
        }

        public void onServiceDisconnected(ComponentName name) {
            sActivity.getApplicationContext().unbindService(connection);
        }
    };
    //Enhance API modification end

    public static Activity getActivity() {
        return sActivity;
    }

    public static void addOnActivityResultListener(OnActivityResultListener listener) {
        onActivityResultListeners.add(listener);
    }

    public static Set<OnActivityResultListener> getOnActivityResultListeners() {
        return onActivityResultListeners;
    }

    public static boolean isActivityVisible() {
        return sActivityVisible;
    }

    // ===========================================================
    // Getter & Setter
    // ===========================================================

    // ===========================================================
    // Methods for/from SuperClass/Interfaces
    // ===========================================================

    // ===========================================================
    // Methods
    // ===========================================================

    private static native void nativeSetEditTextDialogResult(final byte[] pBytes);

    private static native void nativeSetContext(final Context pContext, final AssetManager pAssetManager);

    private static native void nativeSetAudioDeviceInfo(boolean isSupportLowLatency, int deviceSampleRate, int audioBufferSizeInFames);

    public static String getCocos2dxPackageName() {
        return Cocos2dxHelper.sPackageName;
    }

    static public String GetStaticMethodsSignature() {
        Method[] methods = Cocos2dxHelper.class.getMethods();
        StringBuilder signature = new StringBuilder();
        for (Method method : methods) {
            if(!Modifier.isStatic(method.getModifiers())) {
                continue;
            }
            Class<?>[] parameters = method.getParameterTypes();
            for (Class<?> p : parameters) {
                signature.append(p.getName()).append(";");
            }
            signature.append(method.getReturnType().getName())
                    .append(";")
                    .append(method.getName())
                    .append("\n");
        }
        if(signature.length() > 0) {
            signature.deleteCharAt(signature.length() - 1);
        }
        return signature.toString();
    }

    public static String getCocos2dxWritablePath() {
        return sActivity.getFilesDir().getAbsolutePath();
    }

    public static String getCurrentLanguage() {
        return Locale.getDefault().getLanguage();
    }

    public static String getDeviceModel() {
        return Build.MODEL;
    }

    public static AssetManager getAssetManager() {
        return Cocos2dxHelper.sAssetManager;
    }

    public static void enableAccelerometer() {
        Cocos2dxHelper.sAccelerometerEnabled = true;
        Cocos2dxHelper.getAccelerometer().enableAccel();
    }

    public static void enableCompass() {
        Cocos2dxHelper.sCompassEnabled = true;
        Cocos2dxHelper.getAccelerometer().enableCompass();
    }

    public static void setAccelerometerInterval(float interval) {
        Cocos2dxHelper.getAccelerometer().setInterval(interval);
    }

    public static void disableAccelerometer() {
        Cocos2dxHelper.sAccelerometerEnabled = false;
        Cocos2dxHelper.getAccelerometer().disable();
    }

    public static void setKeepScreenOn(boolean value) {
        ((Cocos2dxActivity) sActivity).setKeepScreenOn(value);
    }

    public static void vibrate(float duration) {
        AudioAttributes audioAttributes = new AudioAttributes.Builder()
                .setUsage(AudioAttributes.USAGE_GAME)
                .build();
        sVibrateService.vibrate(VibrationEffect.createOneShot((long) (duration * 1000), VibrationEffect.DEFAULT_AMPLITUDE));
    }

    public static String GetClipboard() {
        try {
            ClipData clipData = sClipboardService.getPrimaryClip();
            if (clipData != null && clipData.getItemCount() > 0) {
                CharSequence text = clipData.getItemAt(0).getText();
                return text.toString();
            }
        } catch (Exception e) {
            Log.e(TAG, "GetClipboard error");
        }
        return "";
    }

    public static void SetClipboard(String str) {
        try {
            ClipData clipData = ClipData.newPlainText("text", str);
            sClipboardService.setPrimaryClip(clipData);
        } catch (Exception e) {
            Log.e(TAG, "SetClipboard error");
        }
    }

    public static long GetCompileVersion() {
        try {
            return sActivity.getPackageManager().getPackageInfo(sActivity.getPackageName(), 0).getLongVersionCode();
        } catch (Exception e) {
            return 0;
        }
    }

    public static void Dialog(final String title, final String content, final int ok, final int cancel) {
        sActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(sActivity)
                        .setTitle(title)
                        .setMessage(content)
                        .setCancelable(false);
                if (ok != 0) {
                    builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            sActivity.runOnGLThread(
                                    new Runnable() {
                                        @Override
                                        public void run() {
                                            LuaJavaBridge.callLuaFunction(ok);
                                            LuaJavaBridge.releaseLuaFunction(ok);
                                            LuaJavaBridge.releaseLuaFunction(cancel);
                                        }
                                    }
                            );
                            dialogInterface.dismiss();
                        }
                    });
                }
                if (cancel != 0) {
                    builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            if (cancel != -1) {
                                sActivity.runOnGLThread(
                                        new Runnable() {
                                            @Override
                                            public void run() {
                                                LuaJavaBridge.callLuaFunction(cancel);
                                                LuaJavaBridge.releaseLuaFunction(cancel);
                                                LuaJavaBridge.releaseLuaFunction(ok);
                                            }
                                        }
                                );
                            }
                            dialogInterface.dismiss();
                        }
                    });
                }
                builder.create().show();
            }
        });
    }

    public static void Dialog(String title, String content, final int ok) {
        Dialog(title, content, ok, 0);
    }
    public static void Dialog(String title, String content, final int ok,final boolean cancel) {
        Dialog(title, content, ok, cancel ? -1 : 0);
    }

    private static class LuaNotifyBroadcastReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            Intent toMainActivityIntent = new Intent(context, sActivity.getClass()).addFlags(Intent.FLAG_ACTIVITY_SINGLE_TOP);
            context.startActivity(toMainActivityIntent);

            final String action = intent.getAction();
            final int okFunc = intent.getIntExtra("okFunc", 0);
            if (0 == okFunc) {
                return;
            }
            sActivity.runOnGLThread(
                    new Runnable() {
                        @Override
                        public void run() {
                            if (action != null && action.equals("LuaNotifyClicked")) {
                                LuaJavaBridge.callLuaFunction(okFunc);
                            }
                            LuaJavaBridge.releaseLuaFunction(okFunc);
                        }
                    }
            );
        }
    }

    static public boolean NotifyEnabled() {
        return sNotifyService.areNotificationsEnabled();
    }

    static public void GotoNotifySetting() {
        Intent intent = new Intent();
        intent.setAction("android.settings.APP_NOTIFICATION_SETTINGS");
        intent.putExtra("android.provider.extra.APP_PACKAGE", sActivity.getPackageName());
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        sActivity.startActivity(intent);
    }

    static String nChannel = "";
    public static void Notify(String title, String content) {
        Notify(title, content, 0);
    }
    public static void Notify(String title, String content, final int ok) {
        if (!sNotifyService.areNotificationsEnabled() && ok != 0) {
            LuaJavaBridge.releaseLuaFunction(ok);
            return;
        }

        if (nChannel.equals("")) {
            nChannel = "LuaNotify";

            IntentFilter filter_click_remove = new IntentFilter();
            filter_click_remove.addAction("LuaNotifyClicked");
            filter_click_remove.addAction("LuaNotifyRemoved");
            sActivity.registerReceiver(new LuaNotifyBroadcastReceiver(), filter_click_remove);

            NotificationChannel channel = new NotificationChannel(
                    nChannel,
                    "通知",
                    NotificationManager.IMPORTANCE_HIGH
            );
            channel.enableLights(true);
            channel.setLightColor(Color.GREEN);
            channel.enableVibration(true);
            channel.setVibrationPattern(new long[]{500});
            channel.setShowBadge(false);
            sNotifyService.createNotificationChannel(channel);
        }
        long tm = System.currentTimeMillis();

        Intent intentC = new Intent("LuaNotifyClicked").putExtra("okFunc", ok);
        PendingIntent pic = PendingIntent.getBroadcast(sActivity, ok, intentC, PendingIntent.FLAG_ONE_SHOT);
        Intent intentR = new Intent("LuaNotifyRemoved").putExtra("okFunc", ok);
        PendingIntent pir = PendingIntent.getBroadcast(sActivity, ok, intentR, PendingIntent.FLAG_ONE_SHOT);

        int iconId = sActivity.getApplication().getApplicationInfo().icon;
        Notification n = new Notification.Builder(sActivity, nChannel)
                .setSmallIcon(iconId)
                .setLargeIcon(Icon.createWithResource(sActivity, iconId))
                .setContentTitle(title)
                .setContentText(content)
                .setShowWhen(true)
                .setWhen(tm)
                .setContentIntent(pic)
                .setDeleteIntent(pir)
                .setCategory(Notification.CATEGORY_MESSAGE)
                //.setFullScreenIntent(pi, true)
                .setAutoCancel(true)
                .setTicker(content)
                .build();
        sNotifyService.notify((int) (tm / 100), n);
    }

    public static int GetOrientation() {
        Configuration mConfiguration = sActivity.getResources().getConfiguration();
        if (mConfiguration.orientation == Configuration.ORIENTATION_PORTRAIT) {
            return 1;
        }
        return 0;
    }

    public static void SetOrientation(int ori) {
        int curORI = GetOrientation();
        if (!IsAutoOrientation() && ori == curORI) {
            return;
        }

        if (ori == 0) {
            sActivity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        } else if (ori == 1) {
            sActivity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        } else if (ori == 2) {
            sActivity.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR);
        }
    }

    static private int OnLuaOrientationChanged = 0;
    public static void OnOrientationChanged(final int ori) {
        if (OnLuaOrientationChanged != 0) {
            sActivity.runOnGLThread(
                    new Runnable() {
                        @Override
                        public void run() {
                            if (ori == Configuration.ORIENTATION_PORTRAIT) {
                                LuaJavaBridge.callLuaFunctionWithLong(OnLuaOrientationChanged, 1);
                            } else if (ori == Configuration.ORIENTATION_LANDSCAPE) {
                                LuaJavaBridge.callLuaFunctionWithLong(OnLuaOrientationChanged, 0);
                            }
                        }
                    }
            );
        }
    }

    public static void SetOnLuaOrientationChanged(int luaCallback) {
        if (OnLuaOrientationChanged != 0) {
            LuaJavaBridge.releaseLuaFunction(OnLuaOrientationChanged);
        }
        OnLuaOrientationChanged = luaCallback;
    }

    public static boolean IsAutoOrientation() {
        return sActivity.getRequestedOrientation() == ActivityInfo.SCREEN_ORIENTATION_SENSOR;
    }

    public static double GetBatteryPercent() {
        if (sIntentBattery != null) {
            //获取当前电量
            int batteryLevel = sIntentBattery.getIntExtra("level", 0);
            //电量的总刻度
            int batterySum = sIntentBattery.getIntExtra("scale", 100);
            return (double) batteryLevel / (double) batterySum;
        }

        return 0.0;
    }

    public static boolean IsBatteryCharge() {
        if (sIntentBattery != null) {
            int status = sIntentBattery.getIntExtra("status", BatteryManager.BATTERY_STATUS_UNKNOWN);
            return status == BatteryManager.BATTERY_STATUS_CHARGING;
        }
        return false;
    }

    public static int GetWifiLevel() {
        int wl = 0;
        WifiInfo wi = sWifiService.getConnectionInfo();
        if (wi != null) {
            int rssi = 100 + wi.getRssi();
            if (rssi > 0) {
                wl = (rssi - 1) / 20 + 1;
                if (wl > 5) {
                    wl = 5;
                }
            }
        }
        return wl;
    }

    public static int GetNetworkType() {
        try {
            NetworkInfo actInfo = sConnectivityService.getActiveNetworkInfo();
            NetworkCapabilities nc = sConnectivityService.getNetworkCapabilities(sConnectivityService.getActiveNetwork());
            if (actInfo != null && nc != null && actInfo.isConnected()) {
                if (nc.hasTransport(NetworkCapabilities.TRANSPORT_WIFI)) {
                    return 1;
                } else if (nc.hasTransport(NetworkCapabilities.TRANSPORT_CELLULAR)) {
                    return 2;
                } else {
                    return 3;
                }
            }
        } catch (Exception ignored) {
        }
        return 0;
    }

    private static String IntIP2StringIP(int ip) {
        return (ip & 0xFF) + "." +
                ((ip >> 8) & 0xFF) + "." +
                ((ip >> 16) & 0xFF) + "." +
                (ip >> 24 & 0xFF);
    }

    public static String GetIp() {
        int nt = GetNetworkType();
        if (1 == nt) {
            WifiInfo wi = sWifiService.getConnectionInfo();
            if (null != wi) {
                return IntIP2StringIP(wi.getIpAddress());
            }
        } else if (0 != nt) {
            try {
                for (Enumeration<NetworkInterface> en = NetworkInterface.getNetworkInterfaces(); en.hasMoreElements(); ) {
                    NetworkInterface intf = en.nextElement();
                    for (Enumeration<InetAddress> enumIpAddr = intf.getInetAddresses(); enumIpAddr.hasMoreElements(); ) {
                        InetAddress inetAddress = enumIpAddr.nextElement();
                        if (!inetAddress.isLoopbackAddress() && inetAddress instanceof Inet4Address) {
                            return inetAddress.getHostAddress();
                        }
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return "";
    }

    private static String GetMAC() {
        try {
            Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();
            while (interfaces.hasMoreElements()) {
                NetworkInterface iF = interfaces.nextElement();

                byte[] addr = iF.getHardwareAddress();
                if (addr == null || addr.length == 0) {
                    continue;
                }

                StringBuilder buf = new StringBuilder();
                for (byte b : addr) {
                    buf.append(String.format("%02X:", b));
                }
                if (buf.length() > 0) {
                    buf.deleteCharAt(buf.length() - 1);
                }
                return buf.toString();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    /*
     * 识别符来源标志：
     * 1， mac地址；
     * 2， IMEI（imei）；
     * 3， 序列号（sn）；
     * 4， android_id
     * @return String
     */
    private static String CacheId = null;
    @SuppressLint("HardwareIds")
    public static String GetId() {
        if (null != CacheId) {
            return CacheId;
        }

        StringBuilder deviceId = new StringBuilder();
        try {
            //mac地址
            String mac = GetMAC();
            if (mac != null) {
                deviceId.append("mac:");
                deviceId.append(mac);
            }

            //IMEI（imei）
            if (sActivity.checkSelfPermission(Manifest.permission.READ_PHONE_STATE) == PackageManager.PERMISSION_GRANTED) {
                String imei = sTelephonyService.getImei();

                if(imei != null){
                    deviceId.append("-imei:");
                    deviceId.append(imei);
                }

                //序列号（sn）
                String sn = sTelephonyService.getSimSerialNumber();
                if(sn != null){
                    deviceId.append("-sn:");
                    deviceId.append(sn);
                }
            }

            // android_id
            String aId = Settings.Secure.getString(sActivity.getContentResolver(), Settings.Secure.ANDROID_ID);
            if (aId != null) {
                deviceId.append("-android:");
                deviceId.append(aId);
            }

            CacheId = deviceId.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }

        return CacheId;
    }

    static private class BaiduLocationListener extends BDAbstractLocationListener {
        private LocationClient lc = null;
        private int luaCallback = 0;

        BaiduLocationListener(LocationClient lc, int cb) {
            this.lc = lc;
            luaCallback = cb;
        }
        @Override
        public void onReceiveLocation(BDLocation location){
            if (lc != null) {
                lc.stop();
            }

            if (luaCallback != 0) {
                final HashMap<String,String> hashMap = new HashMap<>();
                hashMap.put("code",String.valueOf(location.getLocType()));
                hashMap.put("x",String.valueOf(location.getLongitude()));
                hashMap.put("y",String.valueOf(location.getLatitude()));
                hashMap.put("province",location.getProvince());//获取省份
                hashMap.put("city",location.getCity());//获取城市
                hashMap.put("district",location.getDistrict());//获取区县
                hashMap.put("street",location.getStreet());//获取街道信息
                hashMap.put("num",location.getStreetNumber());

                sActivity.runOnGLThread(
                        new Runnable() {
                            @Override
                            public void run() {
                                LuaJavaBridge.callLuaFunctionWithMap(luaCallback, hashMap);
                                LuaJavaBridge.releaseLuaFunction(luaCallback);
                            }
                        }
                );
            }
        }
    }

    public static void RequestLocation(int luaCallback) {
        try {
            if (sActivity.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
                sActivity.requestPermissions(new String[]{Manifest.permission.ACCESS_FINE_LOCATION},0);
                LuaJavaBridge.releaseLuaFunction(luaCallback);
                return;
            }
            LocationClient lc = new LocationClient(sActivity);
            // 声明LocationClient类
            // 注册监听函数
            lc.registerLocationListener(new BaiduLocationListener(lc,luaCallback));

            LocationClientOption option = new LocationClientOption();

            // 可选，设置发起定位请求的间隔，int类型，单位ms
            // 如果设置为0，则代表单次定位，即仅定位一次，默认为0
            // 如果设置非0，需设置1000ms以上才有效
            option.setScanSpan(0);
            option.setOnceLocation(true);

            option.setIsNeedAddress(true);

            // 可选，设置是否使用gps，默认false
            // 使用高精度和仅用设备两种定位模式的，参数必须设置为true
            option.setOpenGps(true);

            option.SetIgnoreCacheException(true);

            //可选，V7.2版本新增能力
            //如果设置了该接口，首次启动定位时，会先判断当前Wi-Fi是否超出有效期，若超出有效期，会先重新扫描Wi-Fi，然后定位
            option.setWifiCacheTimeOut(5 * 60 * 1000);

            lc.setLocOption(option);
            lc.start();
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }

    public static boolean CheckPermission(String pmStr) {
        return sActivity.checkSelfPermission(pmStr) == PackageManager.PERMISSION_GRANTED;
    }

    public static void RequestPermission(String rpStr,int luaCallback) {
        // LuaRequest use request code bigger than 10000.
        sActivity.requestPermissions(new String[]{rpStr},10000 + luaCallback);
    }

    public static String getVersion() {
 		try {
            return Cocos2dxActivity.getContext().getPackageManager().getPackageInfo(Cocos2dxActivity.getContext().getPackageName(), 0).versionName;
 		} catch(Exception e) {
 			return "";
 		}
 	}

    public static boolean openURL(String url) { 
        boolean ret = false;
        try {
            Intent i = new Intent(Intent.ACTION_VIEW);
            i.setData(Uri.parse(url));
            sActivity.startActivity(i);
            ret = true;
        } catch (Exception ignored) {
        }
        return ret;
    }
    
    public static long[] getObbAssetFileDescriptor(final String path) {
        long[] array = new long[3];
        if (Cocos2dxHelper.getObbFile() != null) {
            AssetFileDescriptor descriptor = Cocos2dxHelper.getObbFile().getAssetFileDescriptor(path);
            if (descriptor != null) {
                try {
                    ParcelFileDescriptor parcel = descriptor.getParcelFileDescriptor();
                    Method method = parcel.getClass().getMethod("getFd", new Class[] {});
                    array[0] = (Integer)method.invoke(parcel);
                    array[1] = descriptor.getStartOffset();
                    array[2] = descriptor.getLength();
                } catch (NoSuchMethodException e) {
                    Log.e(Cocos2dxHelper.TAG, "Accessing file descriptor directly from the OBB is only supported from Android 3.1 (API level 12) and above.");
                } catch (IllegalAccessException | InvocationTargetException e) {
                    Log.e(Cocos2dxHelper.TAG, e.toString());
                }
            }
        }
        return array;
    }

    public static void onResume() {
        sActivityVisible = true;
        if (Cocos2dxHelper.sAccelerometerEnabled) {
            Cocos2dxHelper.getAccelerometer().enableAccel();
        }
        if (Cocos2dxHelper.sCompassEnabled) {
            Cocos2dxHelper.getAccelerometer().enableCompass();
        }
    }

    public static void onPause() {
        sActivityVisible = false;
        if (Cocos2dxHelper.sAccelerometerEnabled) {
            Cocos2dxHelper.getAccelerometer().disable();
        }
    }
    
    public static void terminateProcess() {
        // Remove it from recent apps.
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            sActivity.finishAndRemoveTask();
        }
        android.os.Process.killProcess(android.os.Process.myPid());
    }

    private static void showDialog(final String pTitle, final String pMessage) {
        Cocos2dxHelper.sCocos2dxHelperListener.showDialog(pTitle, pMessage);
    }


    public static void setEditTextDialogResult(final String pResult) {
        final byte[] bytesUTF8 = pResult.getBytes(StandardCharsets.UTF_8);

        Cocos2dxHelper.sCocos2dxHelperListener.runOnGLThread(new Runnable() {
            @Override
            public void run() {
                Cocos2dxHelper.nativeSetEditTextDialogResult(bytesUTF8);
            }
        });
    }

    private static int displayMetricsToDPI(DisplayMetrics metrics)
    {
        if(metrics.xdpi != metrics.ydpi) {
            Log.w(Cocos2dxHelper.TAG, "xdpi != ydpi, use (xdpi + ydpi)/2 instead.");
            return (int) ((metrics.xdpi + metrics.ydpi) / 2.0);
        } else {
            return (int)metrics.xdpi;
        }
    }

    public static int getDPI() {
        if (sActivity != null) {
            DisplayMetrics metrics = new DisplayMetrics();
            WindowManager wm = sActivity.getWindowManager();
            if (wm != null) {
                Display d = wm.getDefaultDisplay();
                if (d != null) {
                    try {
                        Method getRealMetrics = d.getClass().getMethod("getRealMetrics", metrics.getClass());
                        getRealMetrics.invoke(d, metrics);
                        return displayMetricsToDPI(metrics);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    d.getMetrics(metrics);
                    return displayMetricsToDPI(metrics);
                }
            }
        }
        return -1;
    }
    
    // ===========================================================
    // Inner and Anonymous Classes
    // ===========================================================

    public static interface Cocos2dxHelperListener {
        public void showDialog(final String pTitle, final String pMessage);

        public void runOnGLThread(final Runnable pRunnable);
    }

    //Enhance API modification begin
    public static int setResolutionPercent(int per) {
        try {
            if (mGameServiceBinder != null) {
                return mGameServiceBinder.setPreferredResolution(per);
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
    }

    public static int setFPS(int fps) {
        try {
            if (mGameServiceBinder != null) {
                return mGameServiceBinder.setFramePerSecond(fps);
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
    }

    public static int fastLoading(int sec) {
        try {
            if (mGameServiceBinder != null) {
                return mGameServiceBinder.boostUp(sec);
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
    }

    public static int getTemperature() {
        try {
            if (mGameServiceBinder != null) {
                return mGameServiceBinder.getAbstractTemperature();
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
    }

    public static int setLowPowerMode(boolean enable) {
        try {
            if (mGameServiceBinder != null) {
                return mGameServiceBinder.setGamePowerSaving(enable);
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
            return -1;
        }
    }

    /**
     * Returns whether the screen has a round shape. Apps may choose to change styling based
     * on this property, such as the alignment or layout of text or informational icons.
     *
     * @return true if the screen is rounded, false otherwise
     */
    public static boolean isScreenRound() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (sActivity.getResources().getConfiguration().isScreenRound()) {
                return true;
            }
        }

        return false;
    }

    /**
     * Returns whether the window is always allowed to extend into the DisplayCutout areas on the short edges of the screen.
     *
     * @return true if the window in display cutout mode on the short edges of the screen, false otherwise
     */
    @SuppressLint("InlinedApi")
    public static boolean isCutoutEnabled() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = sActivity.getWindow().getAttributes();
            return lp.layoutInDisplayCutoutMode == WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
        }

        return false;
    }

    /**
     * Returns safe insets array.
     *
     * @return array of int with safe insets values
     */
    @SuppressLint("NewApi") 
    public static int[] getSafeInsets() {
        final int[] safeInsets = new int[]{0, 0, 0, 0};
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            Window cocosWindow = sActivity.getWindow();
            DisplayCutout displayCutout = cocosWindow.getDecorView().getRootWindowInsets().getDisplayCutout();
            // Judge whether it is cutouts (aka notch) screen phone by judge cutout equle to null
            if (displayCutout != null) {
                List<Rect> rects = displayCutout.getBoundingRects();
                // Judge whether it is cutouts (aka notch) screen phone by judge cutout rects is null or zero size
                if (rects != null && rects.size() != 0) {
                    safeInsets[0] = displayCutout.getSafeInsetBottom();
                    safeInsets[1] = displayCutout.getSafeInsetLeft();
                    safeInsets[2] = displayCutout.getSafeInsetRight();
                    safeInsets[3] = displayCutout.getSafeInsetTop();
                }
            }
        }

        return safeInsets;
    }

    /**
     * Queries about whether any physical keys exist on the
     * any keyboard attached to the device and returns <code>true</code>
     * if the device does not have physical keys
     *
     * @return Returns <code>true</code> if the device have no physical keys,
     * otherwise <code>false</code> will returned.
     */
    public static boolean hasSoftKeys() {
        boolean hasSoftwareKeys = true;

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR1) {
            Display display = sActivity.getWindowManager().getDefaultDisplay();

            DisplayMetrics realDisplayMetrics = new DisplayMetrics();
            display.getRealMetrics(realDisplayMetrics);

            int realHeight = realDisplayMetrics.heightPixels;
            int realWidth = realDisplayMetrics.widthPixels;

            DisplayMetrics displayMetrics = new DisplayMetrics();
            display.getMetrics(displayMetrics);

            int displayHeight = displayMetrics.heightPixels;
            int displayWidth = displayMetrics.widthPixels;

            hasSoftwareKeys = (realWidth - displayWidth) > 0 ||
                    (realHeight - displayHeight) > 0;
        } else {
            boolean hasMenuKey = ViewConfiguration.get(sActivity).hasPermanentMenuKey();
            boolean hasBackKey = KeyCharacterMap.deviceHasKey(KeyEvent.KEYCODE_BACK);
            hasSoftwareKeys = !hasMenuKey && !hasBackKey;
        }
        return hasSoftwareKeys;
    }

    //Enhance API modification end     
    public static float[] getAccelValue() {
        return Cocos2dxHelper.getAccelerometer().accelerometerValues;
    }

    public static float[] getCompassValue() {
        return Cocos2dxHelper.getAccelerometer().compassFieldValues;
    }

    public static int getSDKVersion() {
        return Build.VERSION.SDK_INT;
    }

    private static Cocos2dxAccelerometer getAccelerometer() {
        if (null == sCocos2dxAccelerometer)
            Cocos2dxHelper.sCocos2dxAccelerometer = new Cocos2dxAccelerometer(sActivity);

        return sCocos2dxAccelerometer;
    }
}
