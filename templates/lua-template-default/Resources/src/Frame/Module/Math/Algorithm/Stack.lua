---------------------------------------------
--	Class:	栈类
--	Auth:	WZS
--	Date:	2017年08月12日
--	Desc:	lua自定义的栈
---------------------------------------------
local Stack = class();

function Stack:__init__()
	self._stackTable = {};
end

function Stack:Push(...)
	for _,v in ipairs({...}) do
		table.insert(self._stackTable,v);
	end
end

--[[
	Param:		number		弹出的数量。
	Desc:		从栈顶开始弹出，可以弹出多个。
]]
function Stack:Pop(n)
	local len = #self._stackTable;
	if len == 0 then
		return nil;
	end
	n = n and math.min(n,len) or 1;
	if n == 1 then
		return table.remove(self._stackTable);
	elseif n > 1 then
		return Stack.Pop(self,1),Stack.Pop(self,n - 1);
	end
end

function Stack:Peek(i)
	local len = #self._stackTable
	i = i or len;
	if i < 0 then
		i = len + i + 1;
	end
	return self._stackTable[i];
end

--[[
	Param:		number		移除的数量。
	Desc:		从栈顶开始移除。
]]
function Stack:Remove(n)
	local len = #self._stackTable;
	for _ = 1,math.min(n,len) do
		table.remove(self._stackTable);
	end
end

function Stack:Clear()
    self._stackTable = {};
end

function Stack:GetSize()
	return #self._stackTable;
end

Stack.gtor({
    Size = Stack.GetSize
});
return Stack;