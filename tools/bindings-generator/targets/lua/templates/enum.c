#set fields = $current_class.fields
void lua_register_${generator.prefix}_${current_class.class_name}(cocos2d::Lua& lua) {
    sol::table ${generator.target_ns} = lua.get_or("${generator.target_ns}",lua.create_table());
    ${generator.target_ns}.new_enum("${current_class.class_name}"
    #for m in fields
        ,"${m['name']}", ${m['value']}
    #end for
    );
    lua["${generator.target_ns}"] = ${generator.target_ns};
}
