#
#set generator = $current_class.generator
#set methods = $current_class.methods_clean()
#set st_methods = $current_class.static_methods_clean()
#set $methods += st_methods
#
void lua_register_${generator.prefix}_${current_class.class_name}(cocos2d::Lua& lua) {
	sol::table ${generator.target_ns} = lua.get_or("${generator.target_ns}",lua.create_table());
	#set basesName = $current_class.namespaced_class_name
	#for p in $current_class.parents
		#set basesName += ","+ $p.namespaced_class_name
	#end for
	auto mt = cocos2d::Lua::NewUserType<${basesName}>(${generator.target_ns}, "${current_class.class_name}");
	#for m in methods
		#set fn = m['impl']
		#if fn.is_overloaded == True
			#set overload = "sol::overload("
			#for impl in fn.implementations
				#set castName = "static_cast<"
				#set castName += $impl.ret_type.get_whole_name($generator) + "("
				#if impl.static == False
					#set castName += $current_class.namespaced_class_name + "::"
				#end if
				#set castName += "*)("
				#set hasComma = False
				#for arg in $impl.arguments
					#set castName += $arg.get_whole_name($generator) + ","
					#set hasComma = True
				#end for
				#if hasComma == True
					#set castName = castName[0:-1]
				#end if
				#set castName += ")"
				#if impl.const == True
					#set castName += "const"
				#end if
				#set castName += ">(&" + $current_class.namespaced_class_name + "::" + $fn.func_name + "),"
				#set overload += castName
			#end for
			#set overload = overload[0:-1] + ");"
	mt["${m['name']}"] = $overload
		#else
			#set castName = "static_cast<"
			#set castName += $fn.ret_type.get_whole_name($generator) + "("
			#if fn.static == False
				#set castName += $current_class.namespaced_class_name + "::"
			#end if
			#set castName += "*)("
			#set hasComma = False
			#for arg in $fn.arguments
				#set castName += $arg.get_whole_name($generator) + ","
				#set hasComma = True
			#end for
			#if hasComma == True
				#set castName = castName[0:-1]
			#end if
			#set castName += ")"
			#if fn.const == True
				#set castName += "const"
			#end if
			#set castName += ">("
	mt["${m['name']}"] = ${castName}&${current_class.namespaced_class_name}::${fn.func_name});
		#end if
	#end for
	lua["${generator.target_ns}"] = ${generator.target_ns};
}
