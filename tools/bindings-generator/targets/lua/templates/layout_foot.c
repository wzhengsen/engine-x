void register_all_${prefix}() {
	auto& lua = *cocos2d::Lua::GetInstance();
	#for jsclass in $sorted_classes
	#if $in_listed_classes(jsclass)
	lua_register_${prefix}_${jsclass}(lua);
	#end if
	#end for
}
#if $macro_judgement
\#endif
#end if