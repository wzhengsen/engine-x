void register_all_${prefix}(cocos2d::Lua& lua) {
	#for jsclass in $sorted_classes
	#if $in_listed_classes(jsclass)
	lua_register_${prefix}_${jsclass}(lua);
	#end if
	#end for
}
#if $macro_judgement
\#endif
#end if