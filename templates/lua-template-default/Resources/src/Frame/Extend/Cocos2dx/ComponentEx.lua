-- Copyright (c) 2021 wzhengsen

-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to deal
-- in the Software without restriction, including without limitation the rights
-- to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-- copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:

-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.

-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
-- THE SOFTWARE.

local Component = cc.Component;

function Component:OnEnter(_)end
function Component:OnExit(_)end
function Component:OnAdd(_)end
function Component:OnRemove(_)end

function Component.__properties__()
    return {
        w = {
            EnableEvents = function (self,val)
                if val then
                    self.OnEnterHandler = class.Handler(self,self.OnEnter);
                    self.OnExitHandler = class.Handler(self,self.OnExit);
                    self.OnAddHandler = class.Handler(self,self.OnAdd);
                    self.OnRemoveHandler = class.Handler(self,self.OnRemove);
                else
                    self.OnEnterHandler = nil;
                    self.OnExitHandler = nil;
                    self.OnAddHandler = nil;
                    self.OnRemoveHandler = nil;
                end
            end
        }
    };
end