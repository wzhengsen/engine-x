#set fields = $current_class.fields
static void RegisterLua${current_class.class_name}(cocos2d::Lua& lua) {
sol::table ${generator.target_ns} = lua.get_or("${generator.target_ns}",lua.create_named_table("${generator.target_ns}"));
${generator.target_ns}.new_enum("${current_class.class_name}"
    #for m in fields
,"${m['name']}", ${m['value']}
    #end for
);
}
