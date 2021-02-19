void RegisterLua${prefix}Auto(cocos2d::Lua& lua) {
	#for jsclass in $sorted_classes
	#if $in_listed_classes(jsclass)
RegisterLua${prefix}${jsclass}(lua);
	#end if
	#end for
}
#if $macro_judgement
\#endif
#end if