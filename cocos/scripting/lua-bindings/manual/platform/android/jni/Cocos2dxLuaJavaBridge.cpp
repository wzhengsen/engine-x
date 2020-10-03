/****************************************************************************
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


#include "scripting/lua-bindings/manual/platform/android/jni/Cocos2dxLuaJavaBridge.h"

#include <android/log.h>

#include "scripting/lua-bindings/manual/platform/android/CCLuaJavaBridge.h"

#include "base/ccUTF8.h"

#include <map>

#define  LOG_TAG    "Cocos2dxLuaJavaBridge_java"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaFunctionWithString
  (JNIEnv *env, jclass cls, jint functionId, jstring value)
{
    std::string strValue = cocos2d::StringUtils::getStringUTFCharsJNI(env, value);
    int ret = LuaJavaBridge::callLuaFunction(functionId, strValue.c_str());
    return ret;
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaFunctionWithLong
        (JNIEnv *env, jclass cls, jint functionId, jlong value)
{
    return LuaJavaBridge::callLuaFunction(functionId, value);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaFunctionWithBool
        (JNIEnv *env, jclass cls, jint functionId, jboolean value)
{
    return LuaJavaBridge::callLuaFunction(functionId, (bool) value);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaFunctionWithMap
        (JNIEnv *env, jclass cls, jint functionId, jobject value)
{
    // 获取HashMap类entrySet()方法ID
    jclass hashMapClass = env->FindClass("java/util/HashMap");
    jmethodID entrySetMID = env->GetMethodID(hashMapClass, "entrySet", "()Ljava/util/Set;");

    // 调用entrySet()方法获取Set对象
    jobject setObj = env->CallObjectMethod(value, entrySetMID);
    // 获取Set类中iterator()方法ID
    jclass setClass = env->FindClass("java/util/Set");
    jmethodID iteratorMID = env->GetMethodID(setClass, "iterator", "()Ljava/util/Iterator;");

    // 调用iterator()方法获取Iterator对象
    jobject iteratorObj = env->CallObjectMethod(setObj, iteratorMID);
    // 获取Iterator类中hasNext()方法ID
    // 用于while循环判断HashMap中是否还有数据
    jclass iteratorClass = env->FindClass("java/util/Iterator");
    jmethodID hasNextMID = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    // 获取Iterator类中next()方法ID
    // 用于读取HashMap中的每一条数据
    jmethodID nextMID = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");

    // 获取Map.Entry类中getKey()和getValue()的方法ID
    // 用于读取“K-V”键值对，注意：内部类使用$符号表示
    jclass entryClass = env->FindClass("java/util/Map$Entry");
    jmethodID getKeyMID = env->GetMethodID(entryClass, "getKey", "()Ljava/lang/Object;");
    jmethodID getValueMID = env->GetMethodID(entryClass, "getValue", "()Ljava/lang/Object;");

    auto jMap = std::map<std::string,std::string>();
    // 循环检测HashMap中是否还有数据
    while (env->CallBooleanMethod(iteratorObj, hasNextMID)) {
        // 读取一条数据
        jobject entryObj = env->CallObjectMethod(iteratorObj, nextMID);

        auto keyStr = (jstring)env->CallObjectMethod(entryObj, getKeyMID);
        if (keyStr != nullptr) {  // HashMap允许null类型
            const char* cKeyStr = env->GetStringUTFChars(keyStr, nullptr);

            auto valueStr = (jstring)env->CallObjectMethod(entryObj, getValueMID);
            if (valueStr != nullptr) {
                const char* cValueStr = env->GetStringUTFChars(valueStr, nullptr);
                jMap.emplace(cKeyStr,cValueStr);

                env->ReleaseStringUTFChars(valueStr, cValueStr);
                env->DeleteLocalRef(valueStr);
            }
            env->ReleaseStringUTFChars(keyStr, cKeyStr);
            env->DeleteLocalRef(keyStr);
        }
        env->DeleteLocalRef(entryObj);
    }

    // 释放JNI局部引用: jclass jobject
    env->DeleteLocalRef(hashMapClass);
    env->DeleteLocalRef(setObj);
    env->DeleteLocalRef(setClass);
    env->DeleteLocalRef(iteratorObj);
    env->DeleteLocalRef(iteratorClass);
    env->DeleteLocalRef(entryClass);

    return LuaJavaBridge::callLuaFunction(functionId, jMap);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaFunction
        (JNIEnv *env, jclass cls, jint functionId)
{
    return LuaJavaBridge::callLuaFunction(functionId);
}

JNIEXPORT jint JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_callLuaGlobalFunctionWithString
  (JNIEnv *env, jclass cls, jstring luaFunctionName, jstring value)
{
    std::string functionNameStr = cocos2d::StringUtils::getStringUTFCharsJNI(env, luaFunctionName);
    std::string valueStr = cocos2d::StringUtils::getStringUTFCharsJNI(env, value);
    
    int ret = LuaJavaBridge::callLuaGlobalFunction(functionNameStr.c_str(), valueStr.c_str());
    return ret;
}

JNIEXPORT void JNICALL Java_org_cocos2dx_lib_LuaJavaBridge_releaseLuaFunction
  (JNIEnv *env, jclass cls, jint luaFunctionId)
{
    LuaJavaBridge::releaseLuaFunction(luaFunctionId);
}

} // extern "C"
