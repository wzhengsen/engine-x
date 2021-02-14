#
#set generator = $current_class.generator
#set methods = $current_class.methods_clean()
#set st_methods = $current_class.static_methods_clean()
#
void lua_register_${generator.prefix}_${current_class.class_name}() {
	auto& lua = *cocos2d::Lua::GetInstance();
	sol::table ${generator.target_ns} = lua.get_or("${generator.target_ns}",lua.create_table());
    auto mt = cocos2d::Lua::NewUserType<${current_class.namespaced_class_name}>(${generator.target_ns}, "${current_class.class_name}");
	#for m in methods
    #set fn = m['impl']
	mt["${m['name']}"] = &${current_class.namespaced_class_name}::${fn.func_name};
    #end for
    #for m in st_methods
    #set fn = m['impl']
	mt["${m['name']}"] = &${current_class.namespaced_class_name}::${fn.func_name};
    #end for
}
