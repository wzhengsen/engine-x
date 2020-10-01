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


#include "scripting/lua-bindings/manual/platform/android/CCLuaJavaBridge.h"
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#include "base/ccUTF8.h"

#define  LOG_TAG    "luajc"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

extern "C" {
#include "scripting/lua-bindings/manual/tolua_fix.h"
}

LuaJavaBridge::CallInfo::~CallInfo()
{
	if (m_returnType == TypeString && m_ret.stringValue)
	{
		delete m_ret.stringValue;
	}
}

bool LuaJavaBridge::CallInfo::execute()
{
	switch (m_returnType)
    {
        case TypeVoid:
            m_env->CallStaticVoidMethod(m_classID, m_methodID);
            break;

        case TypeInteger:
            m_ret.intValue = m_env->CallStaticIntMethod(m_classID, m_methodID);
            break;

        case TypeFloat:
            m_ret.floatValue = m_env->CallStaticFloatMethod(m_classID, m_methodID);
            break;

        case TypeBoolean:
            m_ret.boolValue = m_env->CallStaticBooleanMethod(m_classID, m_methodID);
            break;

        case TypeString:
        {
            m_retjs = (jstring)m_env->CallStaticObjectMethod(m_classID, m_methodID);
            bool bValidStr = true;
            std::string strValue = cocos2d::StringUtils::getStringUTFCharsJNI(m_env, m_retjs, &bValidStr);
            m_ret.stringValue = !bValidStr ? nullptr : new string(strValue);
           break;
        }

        case TypeDouble:
            m_ret.doubleValue = m_env->CallStaticDoubleMethod(m_classID, m_methodID);
            break;

        case TypeLong:
            m_ret.longValue = m_env->CallStaticLongMethod(m_classID, m_methodID);
            break;

        case TypeByte:
            m_ret.byteValue = m_env->CallStaticByteMethod(m_classID, m_methodID);
            break;

        case TypeShort:
            m_ret.shortValue = m_env->CallStaticShortMethod(m_classID, m_methodID);
            break;

        default:
            m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
            LOGD("Return type '%d' is not supported", static_cast<int>(m_returnType));
            return false;
    }

	if (m_env->ExceptionCheck() == JNI_TRUE)
	{
		m_env->ExceptionDescribe();
		m_env->ExceptionClear();
		m_error = LuaBridgeError::kLuaBridgeErrorExceptionOccurred;
		return false;
	}

	return true;
}


bool LuaJavaBridge::CallInfo::executeWithArgs(jvalue *args)
{
    switch (m_returnType)
     {
         case TypeVoid:
             m_env->CallStaticVoidMethodA(m_classID, m_methodID, args);
             break;

         case TypeInteger:
             m_ret.intValue = m_env->CallStaticIntMethodA(m_classID, m_methodID, args);
             break;

         case TypeFloat:
             m_ret.floatValue = m_env->CallStaticFloatMethodA(m_classID, m_methodID, args);
             break;

         case TypeBoolean:
             m_ret.boolValue = m_env->CallStaticBooleanMethodA(m_classID, m_methodID, args);
             break;

         case TypeString:
        {
       		m_retjs = (jstring)m_env->CallStaticObjectMethodA(m_classID, m_methodID, args);
        	bool bValidStr = true;
            std::string strValue = cocos2d::StringUtils::getStringUTFCharsJNI(m_env, m_retjs, &bValidStr);
            m_ret.stringValue = !bValidStr ? nullptr : new string(strValue);
            break;
        }

         case TypeDouble:
             m_ret.doubleValue = m_env->CallStaticDoubleMethodA(m_classID, m_methodID, args);
             break;

         case TypeLong:
             m_ret.longValue = m_env->CallStaticLongMethodA(m_classID, m_methodID, args);
             break;

         case TypeByte:
             m_ret.byteValue = m_env->CallStaticByteMethod(m_classID, m_methodID, args);
             break;

         case TypeShort:
             m_ret.shortValue = m_env->CallStaticShortMethod(m_classID, m_methodID, args);
             break;

        default:
            m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
            LOGD("Return type '%d' is not supported", static_cast<int>(m_returnType));
            return false;
     }

	if (m_env->ExceptionCheck() == JNI_TRUE)
	{
		m_env->ExceptionDescribe();
		m_env->ExceptionClear();
		m_error = LuaBridgeError::kLuaBridgeErrorExceptionOccurred;
		return false;
	}

	return true;
}

int LuaJavaBridge::CallInfo::pushReturnValue(lua_State *L)
{
	if (m_error != LuaBridgeError::kLuaBridgeErrorOk)
	{
		lua_pushinteger(L, m_error);
		return 1;
	}

	switch (m_returnType)
	{
		case TypeInteger:
			lua_pushinteger(L, m_ret.intValue);
			return 1;
		case TypeFloat:
			lua_pushnumber(L, m_ret.floatValue);
			return 1;
		case TypeBoolean:
			lua_pushboolean(L, m_ret.boolValue);
			return 1;
		case TypeString:
			if(m_ret.stringValue == nullptr){
				lua_pushnil(L);
			}else{
				lua_pushstring(L, m_ret.stringValue->c_str());
			}
			return 1;
	    case TypeDouble:
	        lua_pushnumber(L, m_ret.doubleValue);
	        return 1;
	    case TypeLong:
            lua_pushinteger(L, m_ret.longValue);
            return 1;
        case TypeByte:
            lua_pushinteger(L, m_ret.byteValue);
            return 1;
        case TypeShort:
	        lua_pushinteger(L, m_ret.shortValue);
	        return 1;
        default:
            break;
	}

	return 0;
}


bool LuaJavaBridge::CallInfo::validateMethodSig()
{
    size_t len = m_methodSig.length();
    if (len < 3 || m_methodSig[0] != '(') // min sig is "()V"
    {
    	m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
    	return false;
	}

    size_t pos = 1;
    while (pos < len && m_methodSig[pos] != ')')
    {
    	LuaJavaBridge::ValueType type = checkType(m_methodSig, &pos);
    	if (type == TypeInvalid) return false;

		m_argumentsCount++;
		m_argumentsType.push_back(type);
        pos++;
    }

    if (pos >= len || m_methodSig[pos] != ')')
	{
    	m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
    	return false;
	}

    pos++;
    m_returnType = checkType(m_methodSig, &pos);
    return true;
}

LuaJavaBridge::ValueType LuaJavaBridge::CallInfo::checkType(const string& sig, size_t *pos)
{
    switch (sig[*pos])
    {
        case 'I':
            return TypeInteger;
        case 'F':
            return TypeFloat;
        case 'Z':
            return TypeBoolean;
        case 'V':
        	return TypeVoid;
        case 'D':
            return TypeDouble;
        case 'J':
            return TypeLong;
        case 'C':
            return TypeByte;
        case 'S':
            return TypeShort;
        case 'L':
            size_t pos2 = sig.find_first_of(';', *pos + 1);
            if (pos2 == string::npos)
            {
                m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
                return TypeInvalid;
            }

            const string t = sig.substr(*pos, pos2 - *pos + 1);
            if (t == "Ljava/lang/String;")
            {
            	*pos = pos2;
                return TypeString;
            }
            else if (t == "Ljava/util/Vector;")
            {
            	*pos = pos2;
                return TypeVector;
            }
            else
            {
            	m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
                return TypeInvalid;
            }
    }

    m_error = LuaBridgeError::kLuaBridgeErrorMethodSignature;
    return TypeInvalid;
}


bool LuaJavaBridge::CallInfo::getMethodInfo()
{
    m_methodID = nullptr;
    m_env = nullptr;

    JavaVM* jvm = cocos2d::JniHelper::getJavaVM();
    jint ret = jvm->GetEnv((void**)&m_env, JNI_VERSION_1_4);
    switch (ret) {
        case JNI_OK:
            break;

        case JNI_EDETACHED :
            if (jvm->AttachCurrentThread(&m_env, nullptr) < 0)
            {
                LOGD("%s", "Failed to get the environment using AttachCurrentThread()");
                m_error = LuaBridgeError::kLuaBridgeErrorJavaVMError;
                return false;
            }
            break;

        case JNI_EVERSION :
        default :
            LOGD("%s", "Failed to get the environment using GetEnv()");
            m_error = LuaBridgeError::kLuaBridgeErrorJavaVMError;
            return false;
    }
    jstring _jstrClassName = m_env->NewStringUTF(m_className.c_str());
    m_classID = (jclass) m_env->CallObjectMethod(cocos2d::JniHelper::classloader,
                                                   cocos2d::JniHelper::loadclassMethod_methodID,
                                                   _jstrClassName);
    m_env->DeleteLocalRef(_jstrClassName);

    if (nullptr == m_classID) {
        LOGD("Classloader failed to find class of %s", m_className.c_str());
        return false;
    }

    m_methodID = m_env->GetStaticMethodID(m_classID, m_methodName.c_str(), m_methodSig.c_str());
    if (!m_methodID)
    {
        m_env->ExceptionClear();
        LOGD("Failed to find method id of %s.%s %s",
                m_className.c_str(),
                m_methodName.c_str(),
                m_methodSig.c_str());
        m_error = LuaBridgeError::kLuaBridgeErrorMethodNotFound;
        return false;
    }

    return true;
}

/* ---------------------------------------- */

void LuaJavaBridge::luaopen_luaj(lua_State *L)
{
	LuaBridge::L = L;
    lua_newtable(L);
    lua_pushstring(L, "callStaticMethod");
    lua_pushcfunction(L, LuaJavaBridge::callJavaStaticMethod);
    lua_rawset(L, -3);
    lua_setglobal(L, "LuaJavaBridge");
}

/*
args:
    const char *className
    const char *methodName
    LUA_TABLE   args
    const char *sig
*/
int LuaJavaBridge::callJavaStaticMethod(lua_State *L)
{
    if (!lua_isstring(L, -4) || !lua_isstring(L, -3)  || !lua_istable(L, -2) || !lua_isstring(L, -1))
    {
    	lua_pushboolean(L, 0);
    	lua_pushinteger(L, LuaBridgeError::kLuaBridgeErrorMethodSignature);
    	return 2;
    }

    LOGD("%s", "LuaJavaBridge::callJavaStaticMethod(lua_State *L)");

    const char *className  = lua_tostring(L, -4);
    const char *methodName = lua_tostring(L, -3);
    const char *methodSig  = lua_tostring(L, -1);

    CallInfo call(className, methodName, methodSig);

    if (!call.isValid()) {
        lua_pushboolean(L, 0);
        lua_pushinteger(L, LuaBridgeError::kLuaBridgeErrorMethodSignature);
        return 2;
    }

    // check args
    lua_pop(L, 1);													/* L: args */
    int count = fetchArrayElements(L, -1);                      	/* L: args e1 e2 e3 e4 ... */
    jvalue *args = nullptr;
    if (count > 0)
    {
	    args = new jvalue[count];
	    for (int i = 0; i < count; ++i)
	    {
	        int index = -count + i;
	        switch (call.argumentTypeAtIndex(i))
	        {
	            case TypeInteger:
	            	if (lua_isfunction(L, index))
	            	{
	                    args[i].i = retainLuaFunction(L, index, nullptr);
	            	}
	            	else
	            	{
	            		args[i].i = (int)lua_tointeger(L, index);
	            	}
	                break;

	            case TypeFloat:
	                args[i].f = lua_tonumber(L, index);
	                break;

	            case TypeBoolean:
	                args[i].z = lua_toboolean(L, index) != 0 ? JNI_TRUE : JNI_FALSE;
	                break;

                case TypeDouble:
                    args[i].d = lua_tonumber(L, index);
                    break;

                case TypeLong:
                    args[i].j = lua_tointeger(L, index);
                    break;

	            case TypeString:
	            default:
	                args[i].l = call.getEnv()->NewStringUTF(lua_tostring(L, index));
	                break;
	        }
	    }
	    lua_pop(L, count);                               			/* L: args */
    }

    bool success = args ? call.executeWithArgs(args) : call.execute();
    if (args) delete []args;

    if (!success)
    {
    	LOGD("LuaJavaBridge::callJavaStaticMethod(\"%s\", \"%s\", args, \"%s\") EXECUTE FAILURE, ERROR CODE: %d",
    			className, methodName, methodSig, call.getErrorCode());

    	lua_pushboolean(L, 0);
    	lua_pushinteger(L, call.getErrorCode());
    	return 2;
    }

	LOGD("LuaJavaBridge::callJavaStaticMethod(\"%s\", \"%s\", args, \"%s\") SUCCESS",
			className, methodName, methodSig);

	lua_pushboolean(L, 1);
	return 1 + call.pushReturnValue(L);
}

// ----------------------------------------

int LuaJavaBridge::fetchArrayElements(lua_State *L, int index)
{
    int count = 0;
    do
    {
        lua_rawgeti(L, index - count, count + 1);
        if (lua_isnil(L, -1))
        {
            lua_pop(L, 1);
            break;
        }
        ++count;
    } while (true);
    return count;
}
