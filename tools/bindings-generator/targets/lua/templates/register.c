#
#set generator = $current_class.generator
#set methods = $current_class.methods_clean()
#set st_methods = $current_class.static_methods_clean()
#
void lua_register_${generator.prefix}_${current_class.class_name}(cocos2d::Lua& lua) {
	sol::table ${generator.target_ns} = lua.get_or("${generator.target_ns}",lua.create_table());
	#if len($current_class.parents) > 0
	auto mt = cocos2d::Lua::NewUserType<
	${current_class.namespaced_class_name}
	#for p in $current_class.parents
	,${p.namespaced_class_name}
	#end for
	>(${generator.target_ns}, "${current_class.class_name}");
	#else
	auto mt = cocos2d::Lua::NewUserType<${current_class.namespaced_class_name}>(${generator.target_ns}, "${current_class.class_name}");
	#end if
	#for m in methods
	#set fn = m['impl']
	#set implementations = fn.implementations
	#if fn.is_overloaded == False
	mt["${m['name']}"] = &${current_class.namespaced_class_name}::${fn.func_name};
	#end if
	#end for
	#for m in st_methods
	#set fn = m['impl']
	#set implementations = fn.implementations
	#if fn.is_overloaded == False
	mt["${m['name']}"] = &${current_class.namespaced_class_name}::${fn.func_name};
	#end if
	#end for
	lua["${generator.target_ns}"] = ${generator.target_ns};
}
