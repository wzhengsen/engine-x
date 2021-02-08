#pragma once
#include "lua.hpp"
#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <map>
#ifdef WIN32
#include <Windows.h>
#endif
#ifndef PushLiteral
#define PushLiteral PushString("" s)
#endif // !PushLiteral
#ifndef OOLUA_PointerSaveKey
#define OOLUA_PointerSaveKey "@_OO_LuaPointerSaveKey_"
#endif // !PushLiteral

#ifdef _WIN32
#define OOLUA_DEPRECATED __declspec(deprecated)
#else
#define OOLUA_DEPRECATED __attribute__((__deprecated__))
#endif

namespace OO_Lua {
	struct Lua final {
	public:
		inline Lua(lua_State* L) noexcept : L(L) {}

		typedef lua_Alloc Alloc;
		typedef lua_CFunction CFunction;
		typedef lua_Debug Debug;
		typedef lua_Hook Hook;
		typedef lua_Integer Integer;
		typedef lua_KContext KContext;
		typedef lua_KFunction KFunction;
		typedef lua_Number Number;
		typedef lua_Reader Reader;
		typedef lua_State State;
		typedef lua_Unsigned Unsigned;
		typedef lua_Writer Writer;

		typedef luaL_Buffer Buffer;
		typedef	luaL_Reg Reg;
		typedef	luaL_Stream Stream;

		template<typename K, typename V>
		struct KVPair {
			K k;
			V v;
			KVPair(K k, V v) :k(k), v(v) {}
		};

		typedef std::function<bool(const Lua& l)> ForFunc;

		enum OP_A {
			ADD = LUA_OPADD,//加法(+)
			SUB = LUA_OPSUB,//减法(-)
			MUL = LUA_OPMUL,//乘法(*)
			DIV = LUA_OPDIV,//浮点除法(/ )
			IDIV = LUA_OPIDIV,//向下取整的除法(//)
			MOD = LUA_OPMOD,//取模(%)
			POW = LUA_OPPOW,//乘方(^)
			UNM = LUA_OPUNM,//取负(一元 - )
			BNOT = LUA_OPBNOT,//按位取反(~)
			BAND = LUA_OPBAND,//按位与(&)
			BOR = LUA_OPBOR,//按位或(| )
			BXOR = LUA_OPBXOR,//按位异或(~)
			SHL = LUA_OPSHL,//左移(<< )
			SHR = LUA_OPSHR//右移(>> )
		};

		enum OP_C {
			EQ = LUA_OPEQ,//相等比较(== )
			LT = LUA_OPLT,//小于比较(< )
			LE = LUA_OPLE,//小于等于比较(<= )
		};

		enum ERR {
			OK = LUA_OK,//成功。
			RUN = LUA_ERRRUN,//运行时错误。
			MEM = LUA_ERRMEM,//内存分配错误。对于这种错，Lua 不会调用错误处理函数。
			ERR = LUA_ERRERR,//在运行错误处理函数时发生的错误。
			SYNTAX = LUA_ERRSYNTAX,
			YIELD = LUA_YIELD,
		};

		enum MASK {
			CALL = LUA_MASKCALL,
			RET = LUA_MASKRET,
			LINE = LUA_MASKLINE,
			COUNT = LUA_MASKCOUNT
		};

		enum class STATUS {
			OK = LUA_OK,
			YIELD = LUA_YIELD
		};

		enum TYPE {
			TNIL = LUA_TNIL,
			TNUMBER = LUA_TNUMBER,
			TBOOLEAN = LUA_TBOOLEAN,
			TSTRING = LUA_TSTRING,
			TTABLE = LUA_TTABLE,
			TFUNCTION = LUA_TFUNCTION,
			TUSERDATA = LUA_TUSERDATA,
			TTHREAD = LUA_TTHREAD,
			TLIGHTUSERDATA = LUA_TLIGHTUSERDATA,
			TNONE = LUA_TNONE
		};

		static constexpr int RegistryIndex = LUA_REGISTRYINDEX;
		static constexpr int MaxStack = LUAI_MAXSTACK;

		inline int AbsIndex(int idx) const noexcept {
			return lua_absindex(L, idx);
		}

		inline void Arith(OP_A op) const noexcept {
			return lua_arith(L, op);
		}

		inline CFunction AtPanic(CFunction panicf) const noexcept {
			return lua_atpanic(L, panicf);
		}

		inline void Call(int nargs = 0, int nresults = 0) const noexcept {
			return lua_call(L, nargs, nresults);
		}

		inline void CallK(int nargs, int nresults, KContext ctx, KFunction k) const noexcept {
			return lua_callk(L, nargs, nresults, ctx, k);
		}

		inline int CheckStack(int n) const noexcept {
			return lua_checkstack(L, n);
		}

		inline void Close() const noexcept {
			return lua_close(L);
		}

		inline int Compare(int index1, int index2, OP_C op) const noexcept {
			return lua_compare(L, index1, index2, op);
		}

		inline void Concat(int n) const noexcept {
			return lua_concat(L, n);
		}

		inline void Copy(int fromidx, int toidx) const noexcept {
			return lua_copy(L, fromidx, toidx);
		}

		inline void CreateTable(int narr = 0, int nrec = 0) const noexcept {
			return lua_createtable(L, narr, nrec);
		}

		inline int Dump(Writer writer, void* data, int strip) const noexcept {
			return lua_dump(L, writer, data, strip);
		}

		inline int Error() const noexcept {
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
#endif
			const auto ret = lua_error(L);
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
			return ret;
		}

		inline int Error(const char* fmt, ...) const noexcept {
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
#endif
			va_list _ArgList;
			va_start(_ArgList, fmt);
			auto ret = luaL_error(L, fmt, _ArgList);
			va_end(_ArgList);
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif

			return ret;
		}

		inline int Error(const std::string fmt, ...) const noexcept {
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
#endif
			va_list _ArgList;
			va_start(_ArgList, fmt);
			auto ret = luaL_error(L, fmt.c_str(), _ArgList);
			va_end(_ArgList);
#ifdef WIN32
			::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
			return ret;
		}

		inline int GC(int what, int data) const noexcept {
			return lua_gc(L, what, data);
		}

		inline Alloc GetAllocF(void** ud) const noexcept {
			return lua_getallocf(L, ud);
		}

		inline void* GetExtraSpace() const noexcept {
			return lua_getextraspace(L);
		}

		inline int GetField(int idx, const char* k) const noexcept {
			return lua_getfield(L, idx, k);
		}

		inline int GetField(int idx, const std::string& k) const noexcept {
			return lua_getfield(L, idx, k.c_str());
		}

		inline int GetField(int idx, Integer n) const noexcept {
			return lua_geti(L, idx, n);
		}

		inline int GetField(int idx) const noexcept {
			return lua_gettable(L, idx);
		}

		inline int GetGlobal(const char* name) const noexcept {
			return lua_getglobal(L, name);
		}

		inline int GetGlobal(const std::string& name) const noexcept {
			return lua_getglobal(L, name.c_str());
		}

		inline Hook GetHook() const noexcept {
			return lua_gethook(L);
		}

		inline int GetHookCount() const noexcept {
			return lua_gethookcount(L);
		}

		inline int GetHookMask() const noexcept {
			return lua_gethookmask(L);
		}

		inline int GetI(int idx, Integer n) const noexcept {
			return lua_geti(L, idx, n);
		}

		inline int GetInfo(int idx, const char* what, Debug* ar) const noexcept {
			return lua_getinfo(L, what, ar);
		}

		inline int GetInfo(int idx, const std::string& what, Debug* ar) const noexcept {
			return lua_getinfo(L, what.c_str(), ar);
		}

		inline const char* GetLocal(const Debug* ar, int n) const noexcept {
			return lua_getlocal(L, ar, n);
		}

		inline int GetMetaTable(int objindex = -1) const noexcept {
			return lua_getmetatable(L, objindex);
		}

		inline int GetMetaTable(const char* name) const noexcept {
			return luaL_getmetatable(L, name);
		}

		inline int GetMetaTable(const std::string& name) const noexcept {
			return luaL_getmetatable(L, name.c_str());
		}

		inline int GetStack(int level, Debug* ar) const noexcept {
			return lua_getstack(L, level, ar);
		}

		inline int GetTable(int idx) const noexcept {
			return lua_gettable(L, idx);
		}

		inline int GetTop() const noexcept {
			return lua_gettop(L);
		}

		inline const char* GetUpValue(int funcindex, int n) const noexcept {
			return lua_getupvalue(L, funcindex, n);
		}

		inline int GetUserValue(int idx) const noexcept {
			return lua_getuservalue(L, idx);
		}

		inline void Insert(int idx) const noexcept {
			return lua_insert(L, idx);
		}

		inline int IsBoolean(int n = -1) const noexcept {
			return lua_isboolean(L, n);
		}

		inline int IsCFunction(int idx = -1) const noexcept {
			return lua_iscfunction(L, idx);
		}

		inline int IsFunction(int n = -1) const noexcept {
			return lua_isfunction(L, n);
		}

		inline int IsInteger(int idx = -1) const noexcept {
			return lua_isinteger(L, idx);
		}

		inline int IsLightUserData(int n = -1) const noexcept {
			return lua_islightuserdata(L, n);
		}

		inline int IsNil(int n = -1) const noexcept {
			return lua_isnil(L, n);
		}

		inline int IsNone(int n = -1) const noexcept {
			return lua_isnone(L, n);
		}

		inline int IsNoneOrNil(int n = -1) const noexcept {
			return lua_isnoneornil(L, n);
		}

		inline int IsNumber(int idx = -1) const noexcept {
			return lua_isnumber(L, idx);
		}

		inline int IsString(int idx = -1) const noexcept {
			return lua_isstring(L, idx);
		}

		inline int IsTable(int n = -1) const noexcept {
			return lua_istable(L, n);
		}

		inline int IsThread(int n = -1) const noexcept {
			return lua_isthread(L, n);
		}

		inline int IsUserData(int idx = -1) const noexcept {
			return lua_isuserdata(L, idx);
		}

		inline int IsYieldable() const noexcept {
			return lua_isyieldable(L);
		}

		inline void Len(int idx = -1) const noexcept {
			return lua_len(L, idx);
		}

		inline int Load(Reader reader, void* dt, const std::string& chunkname, const char* mode = nullptr) const noexcept {
			return lua_load(L, reader, dt, chunkname.c_str(), mode);
		}

		inline int Load(Reader reader, void* dt, const char* chunkname, const std::string& mode) const noexcept {
			return lua_load(L, reader, dt, chunkname, mode.c_str());
		}

		inline int Load(Reader reader, void* dt, const char* chunkname, const char* mode = nullptr) const noexcept {
			return lua_load(L, reader, dt, chunkname, mode);
		}

		inline int Load(Reader reader, void* dt, const std::string& chunkname, const std::string& mode) const noexcept {
			return lua_load(L, reader, dt, chunkname.c_str(), mode.c_str());
		}

		inline State* NewState(Alloc f, void* ud) const noexcept {
			return lua_newstate(f, ud);
		}

		inline void NewTable(int narr = 0, int nrec = 0) const noexcept {
			return lua_createtable(L, narr, nrec);
		}

		inline State* NewThread() const noexcept {
			return lua_newthread(L);
		}

		inline void* NewUserData(size_t sz) const noexcept {
			return lua_newuserdata(L, sz);
		}

		inline int Next(int idx) const noexcept {
			return lua_next(L, idx);
		}

		inline static int NumberToInteger(Number n, Integer* p) noexcept {
			return lua_numbertointeger(n, p);
		}

		inline static int Num2Int(Number n, Integer* p) noexcept {
			return lua_numbertointeger(n, p);
		}

		inline int PCall(int nargs = 0, int nresults = 0, int msgh = 0) const noexcept {
			return lua_pcall(L, nargs, nresults, msgh);
		}

        inline void PrintErr() const noexcept {
#if COCOS2D_DEBUG > 0
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
#endif
            ::printf("[Lua Error] %s\n", CheckString(-1));
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
#endif
        }

        inline void PrintWarn() const noexcept {
#if COCOS2D_DEBUG > 0
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
#endif
            ::printf("[Lua Warn] %s\n", CheckString(-1));
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
#endif
        }

        inline void PrintInfo() const noexcept {
#if COCOS2D_DEBUG > 0
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
#endif
            ::printf("[Lua Info] %s\n", CheckString(-1));
#ifdef WIN32
            ::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
#endif
        }

        // 介于xpcall和pcall之间，发生错误时会打印并弹出错误消息。
        inline int XCall(int nargs = 0, int nresults = 0, int msgh = 0) const noexcept {
            const int err = lua_pcall(L, nargs, nresults, msgh);
            if (ERR::OK != err) {
                PrintErr();
                Pop(1);
            }
            return err;
        }

		inline int PCallK(int nargs, int nresults, int msgh, KContext ctx, KFunction k) const noexcept {
			return lua_pcallk(L, nargs, nresults, msgh, ctx, k);
		}

		inline void Pop(int n) const noexcept {
			return lua_pop(L, n);
		}

		inline void PushBoolean(int b) const noexcept {
			return lua_pushboolean(L, b);
		}

		inline void PushCClosure(CFunction fn, int n = 0) const noexcept {
			return lua_pushcclosure(L, fn, n);
		}

		inline void PushCFunction(CFunction fn) const noexcept {
			return lua_pushcfunction(L, fn);
		}

		inline const char* PushFString(const char* fmt, ...) const noexcept {
			va_list _ArgList;
			va_start(_ArgList, fmt);
			auto ret = lua_pushfstring(L, fmt, _ArgList);
			va_end(_ArgList);
			return ret;
		}

		inline const char* PushFString(const std::string fmt,...) const noexcept {
			va_list _ArgList;
			va_start(_ArgList, fmt);
			auto ret = lua_pushfstring(L, fmt.c_str(), _ArgList);
			va_end(_ArgList);
			return ret;
		}

		inline void PushGlobalTable() const noexcept {
			return lua_pushglobaltable(L);
		}

		inline void PushInteger(Integer n) const noexcept {
			return lua_pushinteger(L, n);
		}

		inline void PushLightUserData(void* p) const noexcept {
			return lua_pushlightuserdata(L, p);
		}

		inline const char* PushLString(const char* s,size_t len) const noexcept {
			return lua_pushlstring(L, s, len);
		}

		inline void PushNil() const noexcept {
			return lua_pushnil(L);
		}

		inline void PushNumber(Number n) const noexcept {
			return lua_pushnumber(L, n);
		}

		inline const char* PushString(const char* s) const noexcept {
			return lua_pushstring(L, s);
		}

		inline int PushThread(State* L) const noexcept {
			return lua_pushthread(L);
		}

		inline int PushThread() const noexcept {
			return lua_pushthread(L);
		}

		inline void PushValue(int idx = -1) const noexcept {
			return lua_pushvalue(L, idx);
		}

		inline const char* PushVFString(const char* fmt, va_list argp) const noexcept {
			return lua_pushvfstring(L, fmt, argp);
		}

		inline const char* PushVFString(const std::string& fmt, va_list argp) const noexcept {
			return lua_pushvfstring(L, fmt.c_str(), argp);
		}

		inline int RawEqual(int idx1, int idx2) const noexcept {
			return lua_rawequal(L, idx1, idx2);
		}



		//栈+1
		template<typename K>
		inline int RawGet(int idx, const K& k) const noexcept {
			Push(k);
			if (idx < 0 && ::abs(idx) < MaxStack) {
				return lua_rawget(L, idx - 1);
			}
			return lua_rawget(L, idx);
		}

		inline int RawGet(int idx) const noexcept {
			return lua_rawget(L, idx);
		}

		inline int RawGet(int idx, Integer n) const noexcept {
			return lua_rawgeti(L, idx, n);
		}

		inline int RawGet(int idx, const void* p) const noexcept {
			return lua_rawgetp(L, idx, p);
		}

		inline int RawGetI(int idx, Integer n) const noexcept {
			return lua_rawgeti(L, idx, n);
		}

		inline int RawGetP(int idx, const void* p) const noexcept {
			return lua_rawgetp(L, idx, p);
		}

		inline size_t RawLen(int idx) const noexcept {
			return lua_rawlen(L, idx);
		}

		//栈+0
		template<typename K, typename V>
		inline void RawSet(int idx, const K& k, const V& v) const noexcept {
			Push(k);
			Push(v);
			if (idx < 0 && ::abs(idx) < MaxStack) {
				return lua_rawset(L, idx - 2);
			}
			return lua_rawset(L, idx);
		}

		inline void RawSet(int idx) const noexcept {
			return lua_rawset(L, idx);
		}

		inline void RawSet(int idx, Integer n) const noexcept {
			return lua_rawseti(L, idx, n);
		}

		//栈-1
		template<typename K>
		inline void RawSet(int idx, const K& k) const noexcept {
			Push(k);
			Rotate(-2, 1);
			if (idx < 0 && ::abs(idx) < MaxStack) {
				return lua_rawset(L, idx - 1);
			}
			return lua_rawset(L, idx);
		}

		inline void RawSetI(int idx, Integer n) const noexcept {
			return lua_rawseti(L, idx, n);
		}

		inline void RawSetP(int idx, const void* p) const noexcept {
			return lua_rawsetp(L, idx, p);
		}

		inline void Register(const char* name,CFunction f) const noexcept {
			return lua_register(L, name, f);
		}

		inline void Register(const std::string& name, CFunction f) const noexcept {
			return lua_register(L, name.c_str(), f);
		}

		inline void Remove(int idx = -1) const noexcept {
			return lua_remove(L, idx);
		}

		inline void Replace(int idx) const noexcept {
			return lua_replace(L, idx);
		}

		inline int Resume(State* from,int narg = 0) const noexcept {
			return lua_resume(L, from, narg, nullptr);
		}

		inline void Rotate(int idx, int n) const noexcept {
			return lua_rotate(L, idx, n);
		}

		inline void SetAllocF(Alloc f, void* ud) const noexcept {
			return lua_setallocf(L, f, ud);
		}

		inline void SetField(int idx, const char* k) const noexcept {
			return lua_setfield(L, idx, k);
		}

		inline void SetField(int idx, Integer n) const noexcept {
			return lua_seti(L, idx, n);
		}

		inline void SetField(int idx, const std::string& k) const noexcept {
			return lua_setfield(L, idx, k.c_str());
		}

		inline void SetField(int idx) const noexcept {
			return lua_settable(L, idx);
		}

		inline void SetGlobal(const char* name) const noexcept {
			return lua_setglobal(L, name);
		}

		inline void SetGlobal(const std::string& name) const noexcept {
			return lua_setglobal(L, name.c_str());
		}

		inline void SetHook(Hook func, int mask, int count) const noexcept {
			return lua_sethook(L, func, mask, count);
		}

		inline void SetI(int idx, Integer n) const noexcept {
			return lua_seti(L, idx, n);
		}

		inline const char* SetLocal(const Debug* ar, int n) const noexcept {
			return lua_setlocal(L, ar, n);
		}

		inline int SetMetaTable(int objindex) const noexcept {
			return lua_setmetatable(L, objindex);
		}

		inline void SetTable(int idx) const noexcept {
			return lua_settable(L, idx);
		}

		inline void SetTop(int idx) const noexcept {
			return lua_settop(L, idx);
		}

		inline const char* SetUpValue(int funcindex,int n) const noexcept {
			return lua_setupvalue(L, funcindex, n);
		}

		inline void SetUserValue(int idx) const noexcept {
			lua_setuservalue(L, idx);
		}

		inline int Status() const noexcept {
			return lua_status(L);
		}

		inline size_t StringToNumber(const char* s) const noexcept {
			return lua_stringtonumber(L, s);
		}

		inline size_t StringToNumber(const std::string& s) const noexcept {
			return lua_stringtonumber(L, s.c_str());
		}

		inline size_t Str2Num(const char* s) const noexcept {
			return lua_stringtonumber(L, s);
		}

		inline size_t Str2Num(const std::string& s) const noexcept {
			return lua_stringtonumber(L, s.c_str());
		}

		inline int ToBoolean(int idx = -1) const noexcept {
			return lua_toboolean(L, idx);
		}

		inline CFunction ToCFunction(int idx = -1) const noexcept {
			return lua_tocfunction(L, idx);
		}

		inline Integer ToInteger(int idx = -1, int* isnum = nullptr) const noexcept {
			return lua_tointegerx(L, idx, isnum);
		}

		inline Integer ToIntegerX(int idx = -1, int* isnum = nullptr) const noexcept {
			return lua_tointegerx(L, idx, isnum);
		}

		inline const char* ToLString(int idx = - 1, size_t* len = nullptr) const noexcept {
			return lua_tolstring(L, idx, len);
		}

		inline Number ToNumber(int idx = -1, int* isnum = nullptr) const noexcept {
			return lua_tonumberx(L, idx, isnum);
		}

		inline Number ToNumberX(int idx = -1, int* isnum = nullptr) const noexcept {
			return lua_tonumberx(L, idx, isnum);
		}

		inline const void* ToPointer(int idx = -1) const noexcept {
			return lua_topointer(L, idx);
		}

		inline const char* ToString(int idx = -1) const noexcept {
			return lua_tostring(L, idx);
		}

		inline State* ToThread(int idx = -1) const noexcept {
			return lua_tothread(L, idx);
		}

		inline void* ToUserData(int idx = -1) const noexcept {
			return lua_touserdata(L, idx);
		}

		inline int Type(int idx = -1) const noexcept {
			return lua_type(L, idx);
		}

		inline const char* TypeName(TYPE tp) const noexcept {
			return lua_typename(L, tp);
		}

		inline void* UpValueId(int fidx, int n) const noexcept {
			return lua_upvalueid(L, fidx, n);
		}

		inline constexpr static int UpValueIndex(int i) noexcept {
			return lua_upvalueindex(i);
		}

		inline const Number Version(State* L) const noexcept {
			return lua_version(L);
		}

		inline const Number Version() const noexcept {
			return lua_version(L);
		}

		inline void UpValueJoin(int fidx1, int n1, int fidx2, int n2) const noexcept {
			return lua_upvaluejoin(L, fidx1, n1, fidx2, n2);
		}

		inline static void XMove(State* from, State* to, int n) noexcept {
			return lua_xmove(from, to, n);
		}

		inline void XMove(State* to, int n) const noexcept {
			return lua_xmove(L, to, n);
		}

		inline int (Yield)(int nresults = 0) const noexcept {
			return lua_yield(L, nresults);
		}

		inline int YieldK(int nresults, KContext ctx, KFunction k) const noexcept {
			return lua_yieldk(L, nresults, ctx, k);
		}

		inline static void AddChar(Buffer* B, char c) noexcept {
			luaL_addchar(B, c);
		}

		inline static void AddLString(Buffer* B, const char* s, size_t l) noexcept {
			return luaL_addlstring(B, s, l);
		}

		inline static void AddLString(Buffer* B, const std::string& s, size_t l) noexcept {
			return luaL_addlstring(B, s.c_str(), l);
		}

		inline static void AddSize(Buffer* B, size_t n) noexcept {
			luaL_addsize(B, n);
		}

		inline static void AddString(Buffer* B, const char* s) noexcept {
			return luaL_addstring(B, s);
		}

		inline static void AddString(Buffer* B, const std::string& s) noexcept {
			return luaL_addstring(B, s.c_str());
		}

		inline static void AddValue(Buffer* B) noexcept {
			return luaL_addvalue(B);
		}

		inline void ArgCheck(int cond, int arg, const char* extramsg = "") const noexcept {
			return luaL_argcheck(L, cond, arg, extramsg);
		}

		inline void ArgCheck(int cond, int arg, const std::string& extramsg) const noexcept {
			return luaL_argcheck(L, cond, arg, extramsg.c_str());
		}

		inline int ArgError(int arg, const char* extramsg) const noexcept {
			return luaL_argerror(L, arg, extramsg);
		}

		inline int ArgError(int arg, const std::string& extramsg) const noexcept {
			return luaL_argerror(L, arg, extramsg.c_str());
		}

		inline void BuffInit(Buffer* B) const noexcept {
			return luaL_buffinit(L, B);
		}

		inline void BufferInit(Buffer* B) const noexcept {
			return luaL_buffinit(L, B);
		}

		inline char* BuffInitSize(Buffer* B, size_t sz) const noexcept {
			return luaL_buffinitsize(L, B, sz);
		}

		inline char* BufferInitSize(Buffer* B, size_t sz) const noexcept {
			return luaL_buffinitsize(L, B, sz);
		}

		inline int CallMeta(int obj,const char* e) const noexcept {
			return luaL_callmeta(L, obj, e);
		}

		inline void CheckAny(int arg = -1) const noexcept {
			return luaL_checkany(L, arg);
		}

		inline Integer CheckInteger(int arg = -1) const noexcept {
			return luaL_checkinteger(L, arg);
		}

		inline const char* CheckLString(int arg = -1, size_t* l = nullptr) const noexcept {
			return luaL_checklstring(L, arg, l);
		}

		inline const char* CheckLString(int arg, size_t& l) const noexcept {
			return luaL_checklstring(L, arg, &l);
		}

		inline Number CheckNumber(int arg = -1) const noexcept {
			return luaL_checknumber(L, arg);
		}

		inline int CheckOption(int arg, const char* def, const char* const lst[]) const noexcept {
			return luaL_checkoption(L, arg, def, lst);
		}

		inline int CheckOption(int arg, const std::string& def, const char* const lst[]) const noexcept {
			return luaL_checkoption(L, arg, def.c_str(), lst);
		}

		inline void CheckStack(int sz, const char* msg) const noexcept {
			return luaL_checkstack(L, sz, msg);
		}

		inline void CheckStack(int sz, const std::string& msg) const noexcept {
			return luaL_checkstack(L, sz, msg.c_str());
		}

		inline const char* CheckString(int arg) const noexcept {
			return luaL_checkstring(L, arg);
		}

		inline const char* CheckString(int arg,size_t& len) const noexcept {
			return luaL_checklstring(L, arg, &len);
		}

		inline const char* CheckString(int arg,size_t* len) const noexcept {
			return luaL_checklstring(L, arg, len);
		}

		inline void CheckType(int arg, TYPE t) const noexcept {
			return luaL_checktype(L, arg, t);
		}

		inline void* CheckUData(int ud, const char* tname) const noexcept {
			return luaL_checkudata(L, ud, tname);
		}

		inline void* CheckUData(int ud, const std::string& tname) const noexcept {
			return luaL_checkudata(L, ud, tname.c_str());
		}

		inline void* CheckUserData(int ud, const char* tname) const noexcept {
			return luaL_checkudata(L, ud, tname);
		}

		inline void* CheckUserData(int ud, const std::string& tname) const noexcept {
			return luaL_checkudata(L, ud, tname.c_str());
		}

		inline static void CheckVersion(State* L) noexcept {
			return luaL_checkversion(L);
		}

		inline void CheckVersion() const noexcept {
			return luaL_checkversion(L);
		}

		inline int DoFile(const char* filename) const noexcept {
			return luaL_dofile(L, filename);
		}

		inline int DoFile(const std::string& filename) const noexcept {
			return luaL_dofile(L, filename.c_str());
		}

		inline int DoString(const char* str) const noexcept {
			return luaL_dostring(L, str);
		}

		inline int DoString(const std::string& str) const noexcept {
			return luaL_dostring(L, str.c_str());
		}

		inline int ExecResult(int stat) const noexcept {
			return luaL_execresult(L, stat);
		}

		inline int FileResult(int stat, const char* fname) const noexcept {
			return luaL_fileresult(L, stat, fname);
		}

		inline int GetMetaField(int obj, const char* e) const noexcept {
			return luaL_getmetafield(L, obj, e);
		}

		inline int GetMetaField(int obj, const std::string& e) const noexcept {
			return luaL_getmetafield(L, obj, e.c_str());
		}

		inline int GetSubTable(int idx, const char* fname) const noexcept {
			return luaL_getsubtable(L, idx, fname);
		}

		inline int GetSubTable(int idx, const std::string& fname) const noexcept {
			return luaL_getsubtable(L, idx, fname.c_str());
		}

		template<typename T1, typename T2, typename T3>
		inline const char* GetSub(const T1& s, const T2& p, const T3& r) const noexcept {
			return luaL_gsub(L,
				std::is_same<T1, std::string&>() ? s.c_str() : s,
				std::is_same<T2, std::string&>() ? p.c_str() : p,
				std::is_same<T3, std::string&>() ? r.c_str() : r);
		}

		OOLUA_DEPRECATED inline Integer Len(int idx,void* p) const noexcept {
			(void)p;
			return luaL_len(L, idx);
		}

		template<typename T1, typename T2>
		inline int LoadBuffer(const T1& buff, size_t sz, const T2& name) const noexcept {
			return luaL_loadbufferx(L,
				std::is_same<T1, std::string&>() ? buff.c_str() : buff,
				sz,
				std::is_same<T2, std::string&>() ? name.c_str() : name,
				nullptr);
		}

		template<typename T1, typename T2, typename T3>
		inline int LoadBuffer(const T1& buff, size_t sz, const T2& name, const T3& mode) const noexcept {
			return luaL_loadbufferx(L,
				std::is_same<T1, std::string&>() ? buff.c_str() : buff,
				sz,
				std::is_same<T2, std::string&>() ? name.c_str() : name,
				std::is_same<T3, std::string&>() ? mode.c_str() : mode);
		}

		template<typename T1, typename T2, typename T3>
		inline int LoadBufferX(const T1& buff, size_t sz, const T2& name, const T3& mode) const noexcept {
			return luaL_loadbufferx(L,
				std::is_same<T1, std::string&>() ? buff.c_str() : buff,
				sz,
				std::is_same<T2, std::string&>() ? name.c_str() : name,
				std::is_same<T3, std::string&>() ? mode.c_str() : mode);
		}

		template<typename T1, typename T2>
		inline int LoadBufferX(const T1& buff, size_t sz, const T2& name) const noexcept {
			return luaL_loadbufferx(L,
				std::is_same<T1, std::string&>() ? buff.c_str() : buff,
				sz,
				std::is_same<T2, std::string&>() ? name.c_str() : name,
				nullptr);
		}

		template<typename T1>
		inline int LoadFile(const T1& filename) const noexcept {
			return luaL_loadfilex(L, std::is_same<T1, std::string&>() ? filename.c_str() : filename, nullptr);
		}

		template<typename T1, typename T2>
		inline int LoadFile(const T1& filename, size_t sz, const T2& mode) const noexcept {
			return luaL_loadfilex(L,
				std::is_same<T1, std::string&>() ? filename.c_str() : filename,
				std::is_same<T2, std::string&>() ? mode.c_str() : mode);
		}

		template<typename T1, typename T2>
		inline int LoadFileX(const T1& filename, size_t sz, const T2& mode) const noexcept {
			return luaL_loadfilex(L,
				std::is_same<T1, std::string&>() ? filename.c_str() : filename,
				std::is_same<T2, std::string&>() ? mode.c_str() : mode);
		}

		template<typename T1>
		inline int LoadFileX(const T1& filename) const noexcept {
			return luaL_loadfilex(L,
				std::is_same<T1, std::string&>() ? filename.c_str() : filename,
				nullptr);
		}

		inline int LoadString(const char* s) const noexcept {
			return luaL_loadstring(L, s);
		}

		inline int LoadString(const std::string& s) const noexcept {
			return luaL_loadstring(L, s.c_str());
		}

		template<typename R, size_t len>
		inline void NewLib(const R (&l)[len]) const noexcept {
			return luaL_newlib(L, l);
		}

		template<typename R, size_t len>
		inline void NewLibTable(const R (&l)[len]) const noexcept {
			return luaL_newlibtable(L, l);
		}

		inline int NewMetaTable(const char* tname) const noexcept {
			return luaL_newmetatable(L, tname);
		}

		inline int NewMetaTable(const std::string& tname) const noexcept {
			return luaL_newmetatable(L, tname.c_str());
		}

		inline static State* NewState() noexcept {
			return luaL_newstate();
		}

		inline void OpenLibs() const noexcept {
			return luaL_openlibs(L);
		}

		inline Integer OptInteger(int arg = -1,Integer def = 0) const noexcept {
			return luaL_optinteger(L, arg, def);
		}

		inline const char* OptLString(int arg = -1, const char* def = "", size_t* l = nullptr) const noexcept {
			return luaL_optlstring(L, arg, def, l);
		}

		inline const char* OptLString(int arg = -1, const std::string& def = "", size_t* l = nullptr) const noexcept {
			return luaL_optlstring(L, arg, def.c_str(), l);
		}

		inline Number OptNumber(int arg = -1, Number def = 0.0f) const noexcept {
			return luaL_optnumber(L, arg, def);
		}

		inline const char* OptString(int arg = -1, const char* def = "") const noexcept {
			return luaL_optstring(L, arg, def);
		}

		inline const char* OptString(int arg = -1, const std::string& def = "") const {
			return luaL_optstring(L, arg, def.c_str());
		}

		inline static char* PrepBuffer(Buffer* B, size_t sz = LUAL_BUFFERSIZE) noexcept {
			return luaL_prepbuffsize(B, sz);
		}

		inline static char* PrepBuffSize(Buffer* B, size_t sz = LUAL_BUFFERSIZE) noexcept {
			return luaL_prepbuffsize(B, sz);
		}

		inline static char* PrepBufferSize(Buffer* B, size_t sz = LUAL_BUFFERSIZE) noexcept {
			return luaL_prepbuffsize(B, sz);
		}

		inline static void PushResult(Buffer* B) noexcept {
			return luaL_pushresult(B);
		}

		inline static void PushResult(Buffer* B, size_t sz) noexcept {
			return luaL_pushresultsize(B, sz);
		}

		inline static void PushResultSize(Buffer* B, size_t sz) noexcept {
			return luaL_pushresultsize(B, sz);
		}

		inline int Ref(int idx = RegistryIndex) const noexcept {
			return luaL_ref(L, idx);
		}

		inline void RequireF(const char* modename, CFunction openf, int glb = 0) const noexcept {
			return luaL_requiref(L, modename, openf, glb);
		}

		template<typename R, size_t len>
		inline void SetFuncs(const R (&l)[len], int nup = 0) const noexcept {
			return luaL_setfuncs(L, l, nup);
		}

		inline void SetMetaTable(const char* tname) const noexcept {
			return luaL_setmetatable(L, tname);
		}

		inline void SetMetaTable(const std::string& tname) const noexcept {
			return luaL_setmetatable(L, tname.c_str());
		}

		inline void* TestUData(int arg, const char* tname) const noexcept {
			return luaL_testudata(L, arg, tname);
		}

		inline void* TestUData(int arg, const std::string& tname) const noexcept {
			return luaL_testudata(L, arg, tname.c_str());
		}

		inline void* TestUserData(int arg, const char* tname) const noexcept {
			return luaL_testudata(L, arg, tname);
		}

		inline void* TestUserData(int arg, const std::string& tname) const noexcept {
			return luaL_testudata(L, arg, tname.c_str());
		}

		OOLUA_DEPRECATED inline const char* ToLString(int idx, size_t* len, void* p) const noexcept {
			(void)p;
			return luaL_tolstring(L, idx, len);
		}

		inline void TraceBack(State* L1, const char* msg, int level) const noexcept {
			return luaL_traceback(L, L1, msg, level);
		}

		inline void TraceBack(State* L1, const std::string& msg, int level) const noexcept {
			return luaL_traceback(L, L1, msg.c_str(), level);
		}

		inline const char* TypeName(int i) const noexcept {
			return luaL_typename(L, i);
		}

		inline void Unref(int t, int ref) const noexcept {
			return luaL_unref(L, t, ref);
		}

		inline void Where(int lvl = 0) const noexcept {
			return luaL_where(L, lvl);
		}

		inline int OpenBase() const noexcept {
			return luaopen_base(L);
		}

		inline int OpenCoroutine() const noexcept {
			return luaopen_coroutine(L);
		}

		inline int OpenDebug() const noexcept {
			return luaopen_debug(L);
		}

		inline int OpenIO() const noexcept {
			return luaopen_io(L);
		}

		inline int OpenMath() const noexcept {
			return luaopen_math(L);
		}

		inline int OpenOS() const noexcept {
			return luaopen_os(L);
		}

		inline int OpenPackage() const noexcept {
			return luaopen_package(L);
		}

		inline int OpenString() const noexcept {
			return luaopen_string(L);
		}

		inline int OpenTable() const noexcept {
			return luaopen_table(L);
		}

		inline int OpenUTF8() const noexcept {
			return luaopen_utf8(L);
		}


		//Extra

		//栈+1
		inline void Push() const noexcept {
			lua_pushnil(L);
		}

		inline void Push(nullptr_t) const noexcept {
			lua_pushlightuserdata(L, nullptr);
		}

		inline void Push(const char* s) const noexcept {
			lua_pushstring(L, s);
		}

		inline void Push(const char* s,size_t len) const noexcept {
			lua_pushlstring(L, s, len);
		}

		inline void Push(const unsigned char* s, size_t len) const noexcept {
			lua_pushlstring(L, reinterpret_cast<const char*>(s), len);
		}

		inline void Push(const std::string& s) const noexcept {
			lua_pushlstring(L, s.c_str(), s.length());
		}

		inline void Push(Number n) const noexcept {
			lua_pushnumber(L, n);
		}

		inline void Push(float n) const noexcept {
			lua_pushnumber(L, n);
		}

		template<typename T>
		inline void Push(T i) const noexcept {
			lua_pushinteger(L, i);
		}

        OOLUA_DEPRECATED inline void Push(uint64_t i) const noexcept {
			lua_pushinteger(L, i);
		}

		inline void Push(bool b) const noexcept {
			lua_pushboolean(L, static_cast<int>(b));
		}

		inline void Push(void* p) const noexcept {
			lua_pushlightuserdata(L, p);
		}

		inline void Push(const void* p) const noexcept {
			lua_pushlightuserdata(L, const_cast<void*>(p));
		}

		inline void Push(CFunction f,int n = 0) const noexcept {
			if (n) {
				return lua_pushcclosure(L, f, n);
			}
			lua_pushcfunction(L, f);
		}

		inline static void Push(State* L) noexcept {
			lua_pushthread(L);
		}

		template<typename K, typename V>
		inline void Push(const std::map<K,V>& map) const noexcept {
			NewTable(0, map.size());
			for (const auto& pair : map) {
				Push(pair.first);
				Push(pair.second);
				SetTable(-3);
			}
		}

		template<typename V>
		inline void Push(const std::vector<V>& vec) const noexcept {
			NewTable(0, vec.size());
			size_t idx = 1;
			for (const auto& value : vec) {
				Push(value);
				SetI(-2, idx);
				idx++;
			}
		}

		//栈+1
		template<typename K>
		inline int GetField(int idx, const K& k) const noexcept {
			Push(k);
            if (idx < 0 && ::abs(idx) < MaxStack) {
                return lua_gettable(L, idx - 1);
            }
			return lua_gettable(L, idx);
		}

		//栈+0
		template<typename K, typename V>
		inline void SetField(int idx, const K& k, const V& v) const noexcept {
			Push(k);
			Push(v);
            if (idx < 0 && ::abs(idx) < MaxStack){
                return lua_settable(L, idx - 2);
            }
			return lua_settable(L, idx);
		}

		//栈+0
		template<typename K, typename V>
		inline void SetPair(int idx, const KVPair<K,V>& kv,bool raw = false) const noexcept {
			if (raw) {
				RawSet(idx, kv.k, kv.v);
			}
			else {
				SetField(idx, kv.k, kv.v);
			}
		}

		//栈+0
		template<typename K, typename V>
		inline void SetPairs(int idx, const KVPair<K, V> kvs[], size_t len, bool raw = false) const noexcept {
			for (size_t i = 0; i < len; i++) {
				const auto kv = kvs + i;
				SetPair(idx, *kv, raw);
			}
		}

		//栈+0
		template<typename K, typename V, size_t len>
		inline void SetPairs(int idx, const KVPair<K, V>(& kvs)[len], bool raw = false) const noexcept {
			for (size_t i = 0; i < len; i++) {
				const auto kv = kvs + i;
				SetPair(idx, *kv, raw);
			}
		}

		//栈+0
		/*
			Func:	循环idx处的顺序表，并以forF作为回调。
					请保证forF的回调在返回时不会改变栈空间，
					forF返回false以实现break
		*/
		inline void For(int idx,const ForFunc& forF) const {
			if (!forF) {
				return;
			}
			if (idx < 0 && ::abs(idx) < MaxStack) {
				--idx;
			}
			/*  表放在索引 'idx' 处 */
			lua_pushnil(L);  /* 第一个键 */
			while (lua_next(L, idx) != 0) {
				/* 使用 '键' （在索引 -2 处） 和 '值' （在索引 -1 处）*/
				if (forF(*this)) {
					/* 移除 '值' ；保留 '键' 做下一次迭代 */
					lua_pop(L, 1);
				}
				else {
					/* 移除 '值' 和 '键'*/
					lua_pop(L, 2);
					break;
				}
			}
		}

        // 栈+0
        // 若给定索引处为一个表，将表中的连续数字键对应的值转换为字符串数组。
        inline std::vector<std::string> ToStringArray(int idx) const {
            std::vector<std::string> vec = std::vector<std::string>();
            if (IsTable(idx)) {
                int i = 1;
                while (true) {
                    GetField(idx, i);
                    if (IsString(-1)) {
                        vec.emplace_back(ToString(-1));
                        Pop(1);
                        i++;
                    }
                    else {
                        Pop(1);
                        break;
                    }
                }
            }
            return vec;
        }

        // 栈+0
        // 若给定索引处为一个表，将表中的连续数字键对应的值转换为整数数组。
        inline std::vector<Integer> ToIntArray(int idx) const {
            std::vector<Integer> vec = std::vector<Integer>();
            if (IsTable(idx)) {
                int i = 1;
                while (true) {
                    GetField(idx, i);
                    if (IsInteger(-1)) {
                        vec.push_back(ToInteger(-1));
                        Pop(1);
                        i++;
                    }
                    else {
                        Pop(1);
                        break;
                    }
                }
            }
            return vec;
        }

        // 栈+0
        // 若给定索引处为一个表，将表中的连续数字键对应的值转换为双精度数组。
        inline std::vector<double> ToDoubleArray(int idx) const {
            std::vector<double> vec = std::vector<double>();
            if (IsTable(idx)) {
                int i = 1;
                while (true) {
                    GetField(idx, i);
                    if (IsNumber(-1)) {
                        vec.push_back(ToNumber(-1));
                        Pop(1);
                        i++;
                    }
                    else {
                        Pop(1);
                        break;
                    }
                }
            }
            return vec;
        }


		void DumpStack() const {
			const auto top = GetTop();
			std::cout << std::endl;
			for (auto i = top; i >= 1; i--) {
				const auto type = static_cast<TYPE>(Type(i));
				switch (type) {
					case TSTRING: {
                        ::printf("(-%d)%s:%.20s\n", top - i + 1, TypeName(type), ToString(i));
						break;
					}
					case TBOOLEAN: {
						std::cout << "(-" << top - i + 1 << ")" << TypeName(type) << ":" << bool((ToBoolean(i)));
						break;
					}
					case TNUMBER: {
						if (IsInteger(i)) {
							std::cout << "(-" << top - i + 1 << ")" << TypeName(type) << "(integer):" << ToInteger(i);
						}
						else {
							std::cout << "(-" << top - i + 1 << ")" << TypeName(type) << "(double):" << ToNumber(i);
						}
						break;
					}
					case TNIL: {
						std::cout << "(-" << top - i + 1 << ")" << TypeName(type);
						break;
					}
					default: {
						std::cout << "(-" << top - i + 1 << ")" << TypeName(type) << ":" << ToPointer(i);;
						break;
					}
				}
                if (type != TSTRING) {
                    std::cout << std::endl;
                }
			}
			std::cout << std::endl;
		}
		//栈-1
		//将指针作为键，在一个特定的表中保存并弹出栈顶的值
		inline void SaveValue(const void* p) const noexcept {
			RawGet(RegistryIndex, OOLUA_PointerSaveKey);//table? value
			if (!IsTable()) {
				Pop(1);//value
				NewTable();//table value
				PushValue();//table table value
				RawSet(RegistryIndex, OOLUA_PointerSaveKey);//table value
			}
			Push(p);//lightuserdata table value
			PushValue(-3);//value lightuserdata table value
			SetField(-3);//table value
			Pop(2);//
		}

		//栈+1
		//将指针作为键，在一个特定的表中获取值，并将结果压栈
		inline void LoadValue(const void* p) const noexcept {
			RawGet(RegistryIndex, OOLUA_PointerSaveKey);//table?
			if (!IsTable()) {
				Pop(1);//
				NewTable();//table
				RawSet(RegistryIndex, OOLUA_PointerSaveKey);//
				Push();//nil
				return;
			}
			Push(p);//lightuserdata table
			GetField(-2);//value table
			Remove(-2);//value
		}

		// 栈+0
		// 清除指针上保存的值
		inline void ClearValue(const void* p) const noexcept {
			Push();
			SaveValue(p);
		}

		// 栈+1
		/*
			Func:	新增一个普遍用于UserData的元表，并压栈。
			Return:	当元表存在时，返回false，并压入已存在的元表
		*/
		inline bool NewUserDataMetaTable(const std::string& name) const noexcept {
			if (!NewMetaTable(name)) {
				//元表存在时返回
				return false;
			}// table
			SetField(-1,".isclass",true);

			// 压入一个 __index 指向的 CFunction
			Push(UserDataMetaIndexFunc);//function table
			SetField(-2, "__index");//table

			// __newindex 指向的 CFunction
			Push(UserDataMetaNewIndexFunc);//function table
			SetField(-2, "__newindex");//table

			Push(UserDataMetaGCFunc);//function table
			SetField(-2, "__gc");//table

			NewTable();//table table
			PushValue();//table table table
			Push(UserDataMeta_gtor, 1);//function table table
			SetField(-3, "gtor");//table table
			SetField(-2, ".get");//table

			NewTable();//table table
			PushValue();//table table table
			Push(UserDataMeta_stor, 1);//function table table
			SetField(-3, "stor");//table table
			SetField(-2, ".set");//table
			return true;
		}

		// 栈+0
		/*
			Func:	将栈顶的 UserData 的元表设置为指定的普遍用于UserData的元表
		*/
		inline void SetUserDataMetaTable(const std::string& name) const noexcept {
			NewUserDataMetaTable(name);// table userdata
			SetMetaTable(-2);//userdata
		}

		// 栈+1
		/*
			Func:	创建一个指针类型的用户数据在栈顶，设置一个有__index和__newindex的元表；
					并绑定一个table的uservalue
		*/
		template<typename T>
		inline void PushUserData(const T* t, const std::string& name) const noexcept {
			*static_cast<const T**>(NewUserData(sizeof(const T*))) = t;//userdata ...
			SetUserDataMetaTable(name);//userdata ...
			NewTable();//table userdata ...
			SetUserValue(-2);//userdata ...
		}

		// 栈+0
		/*
			Func:	检查索引处的lua值是否为给定类型的UserData
			Return:	失败返回nullptr
		*/
		template<typename T>
		inline T* CheckUserData(int idx, const std::string& name) const noexcept {
			const auto ret = static_cast<T*>(CheckUData(idx, name));
			if (ret && *ret) {
				return ret;
			}
			return nullptr;
		}

		// 栈+0
		// 此函数和 CheckUserData 类似。 但它在测试失败时会返回 nullptr 而不是抛出错误。
		template<typename T>
		inline T* TestUserData(int arg, const std::string& tname) const noexcept {
			return static_cast<T*>(luaL_testudata(L, arg, tname.c_str()));
		}

		// 栈+1
		// 生成一个与指针绑定的userdata，并命名为className指定的类名，将生成的userdata留在栈顶。
		template<typename T>
		inline void BindUserData(const T* p, const std::string& className) const noexcept {
			PushUserData(p, className);// userdata ...
			PushValue();// userdata userdata ...
			SaveValue(p);// userdata ...
		}

		// 栈+1
		// 得到绑定到指针的userdata，并确保userdata是className指定的类名，将得到的userdata留在栈顶。
		inline void GetUserData(const void* p, const std::string& className) const noexcept {
			LoadValue(p);// value ...
			CheckUserData(-1, className);
		}

		// 栈+0
		// 清除指针上绑定的指定类名的UserData
		inline void ClearUserData(const void* p, const std::string& className) const noexcept {
			LoadValue(p);
			if (TestUserData(-1, className)) {
				ClearValue(p);
			}
			Pop(1);
		}

		// 栈-1
		// 将栈顶的函数保存为一个整数。
		inline int SaveFunction() const noexcept {
			CheckType(-1, Lua::TYPE::TFUNCTION);
			return Ref();
		}

		// 栈+1
		// 将一个整数还原为保存的函数。
		inline void LoadFunction(int ref) const noexcept {
			RawGet(RegistryIndex, ref);
			CheckType(-1, Lua::TYPE::TFUNCTION);
		}

		// 栈+0
		// 清除保存为整数ref的函数。
		inline void ClearFunction(int ref) const noexcept {
			Unref(RegistryIndex, ref);
		}

		// 栈+0
		// UserDataMetaTable的Gtor
		void Gtor(int idx,const std::map<std::string, Lua::CFunction>& gs) const {
			PushValue(idx);//table ...
			GetField(-1,".get");//gtor table ...
			if (!IsTable()) {
				Pop(1);
				NewTable();//table table ...
				PushValue();//table table table ...
				SetField(-2, ".get");//gtor table ...
			}
			for (const auto& p : gs) {
				Push(p.first);//stringF gtor table ...
				Push(p.second);//function stringF gtor table ...
				RawSet(-3);//gtor table ...
			}
			Pop(2);
		}

		// 栈+0
		// UserDataMetaTable的Stor
		void Stor(int idx, const std::map<std::string, Lua::CFunction>& gs) const {
			PushValue(idx);//table ...
			GetField(-1, ".set");//stor table ...
			if (!IsTable()) {
				Pop(1);
				NewTable();//table table ...
				PushValue();//table table table ...
				SetField(-2, ".set");//gtor table ...
			}
			for (const auto& p : gs) {
				Push(p.first);//stringF gtor table ...
				Push(p.second);//function stringF stor table ...
				RawSet(-3);//gtor table ...
			}
			Pop(2);
		}


	private:
		lua_State* L = nullptr;

		static int UserDataMetaIndexFunc(State* L) noexcept {
			const auto lua = Lua(L);//key userdata

			lua.GetUserValue(1);//uservalue key userdata
			if (lua.IsTable()) {//table key userdata
				lua.PushValue(-2);//key table key userdata
				lua.GetField(-2);//table[key] table key userdata
				if (!lua.IsNil()) {
					return 1;
				}
			}
			lua.SetTop(2);//key userdata

			lua.PushValue(1);//userdata key userdata
			while (lua.GetMetaTable()) {//mt?|nil userdata key userdata
				lua.Remove(-2);//mt key userdata
				lua.RawGet(-1, ".get");//gtor? mt key userdata
				if (lua.IsTable()) {
					lua.PushValue(2);//key gtor mt key userdata
					lua.RawGet(-2);//function? gtor mt key userdata
					if (lua.IsFunction()) {
						lua.PushValue(1);//userdata function gtor mt key userdata
						lua.Call(1, 1);//ret gtor mt key userdata
						return 1;
					}
				}
				lua.SetTop(3);//mt key userdata
			}
			lua.SetTop(2);//key userdata
			lua.PushValue(1);//userdata key userdata
			if (lua.GetMetaTable()) {//mt?|nil userdata key userdata
				lua.PushValue(2);//key mt userdata key userdata
				lua.GetField(-2);//ret mt  userdata key userdata
				return 1;
			}
			lua.Push();
			return 1;
		}

		static int UserDataMetaNewIndexFunc(State* L) noexcept {
			const auto lua = Lua(L);//value key userdata
			// 先在UserValue的.cls.set中查找.set，将lua中的class继承类的优先级排在最前，.get的查找类似，
			// 也是优先级在最前，但是通过对UserValue的元表实现的。

			lua.GetUserValue(1);//uv value key userdata
			if (lua.IsTable()) {
				lua.GetField(-1, ".cls.set");//.cls.set uv value key userdata
				if (!lua.IsNil()) {
					lua.PushValue(2);//key .cls.set uv value key userdata
					lua.RawGet(-2);//ret .cls.set uv value key userdata
					if (lua.IsFunction()) {//function .cls.set uv value key userdata
						lua.PushValue(1);//userdata function .cls.set uv value key userdata
						lua.PushValue(3);//value userdata function .cls.set uv value key userdata
						lua.Call(2);//.cls.set uv value key userdata
						return 0;
					}
				}
			}
			lua.SetTop(3);//value key userdata

			lua.PushValue(1);//userdata value key userdata
			while (lua.GetMetaTable()) {//mt?|nil userdata value key userdata
				lua.Remove(-2);//mt value key userdata
				lua.RawGet(-1, ".set");//stor? mt value key userdata
				if (lua.IsTable()) {
					lua.PushValue(2);//key stor mt value key userdata
					lua.RawGet(-2);//function? stor mt value key userdata
					if (lua.IsFunction()) {
						lua.PushValue(1);//userdata function stor mt value key userdata
						lua.PushValue(3);//value userdata function stor mt value key userdata
						lua.Call(2);//stor mt value key userdata
						return 0;
					}
				}
				lua.SetTop(4);//mt value key userdata
			}

			lua.SetTop(3);//value key userdata
			lua.GetUserValue(1);//uservalue value key userdata
			if (lua.IsTable()) {//table? value key userdata
				lua.Insert(-3);//value key table userdata
				lua.RawSet(-3);//table userdata
			}
			return 0;
		}

		static int UserDataMetaGCFunc(State* L) noexcept {
			const auto lua = Lua(L);//userdata
            void **ud = static_cast<void**>(lua.ToUserData());

			while (lua.GetMetaTable()) {//mt?|nil userdata
				lua.RawGet(-1, ".collector");//gc_function? mt userdata
				if (lua.IsFunction()) {//gc_function mt userdata
					lua.PushValue(-1);//userdata gc_function mt userdata
					lua.Call(1);//mt userdata
					break;
				}
				lua.SetTop(2);//mt userdata
			}
			lua.SetTop(1);//userdata
			if (ud) {
				lua.ClearValue(*ud);//userdata
			}
			return 0;
		}

		static int UserDataMeta_gtor(State* L) {
			const auto lua = Lua(L);
			constexpr int idx = Lua::UpValueIndex(1);//table
			lua.PushValue(idx);//table table
			lua.For(1, [](const Lua & lua)->bool {
				lua.PushValue(-2);
				lua.PushValue(-2);
				lua.RawSet(-5);
				return true;
			});
			return 0;
		}

		static int UserDataMeta_stor(State* L) {
			const auto lua = Lua(L);
			constexpr int idx = Lua::UpValueIndex(1);//table
			lua.PushValue(idx);//table table
			lua.For(1, [](const Lua& lua)->bool {
				lua.PushValue(-2);
				lua.PushValue(-2);
				lua.RawSet(-5);
				return true;
			});
			return 0;
		}
	};
}