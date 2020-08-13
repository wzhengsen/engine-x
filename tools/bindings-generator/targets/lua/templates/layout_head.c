\#include "scripting/lua-bindings/auto/${out_file}.hpp"
#if $macro_judgement
$macro_judgement
#end if
#for header in $headers
    #for sp in $search_path
        #set relative = os.path.relpath(header, sp)
        #if not '..' in relative
\#include "${relative.replace(os.path.sep, '/')}"
            #break
        #end if
    #end for
#end for
\#include "scripting/lua-bindings/manual/tolua_fix.h"
\#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#if $cpp_headers
#for header in $cpp_headers
\#include "${header}"
#end for
#end if
