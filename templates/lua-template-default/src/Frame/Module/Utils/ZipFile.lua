--[[
    Auth:       wzhengsen
    Date:       2019.12.26
    Content:    对package.preload.ZipFile的Lua封装。
]]
local ZipFile = require("StarryX::ZipFile");
--[====[
    #ZipFile#
    static member:
        R<userdata>
        Zip可读。

        W<userdata>
        Zip可写。

    ZipFile的操作要么可读，要么可写，不能同时读写。

    static method:
        new(
            pathName                                        <string>                    打开的Zip文件名。
            [,mode]                                         <userdata>{ZipFile.R}       操作模式。
        )                                                   -><userdata>#ZipFile#|nil
        参数数量不合法时会返回nil。

    method:
        delete()
        使用完成后务必关闭。

        First()                                             -><userdata>#ZipItem#|nil
        指向第一个内部文件/目录，返回ZipItem类型或nil。
        需要可读。

        Next()                                              -><userdata>#ZipItem#|nil
        向下一个文件/目录迭代，返回ZipItem，到达尽头返回nil。
        需要可读。

        Seek(
            fileName                                        <string>        要查找的文件/目录（目录最后需要/结尾），区分大小写。
        )                                                   -><userdata>#ZipItem#|nil
        指向查找的文件/目录，返回ZipItem，未找到返回nil，
        会改变当前的迭代到指定文件/目录。
        需要可读。

        Uncompress(
            path                                            <string>        解压目录。
            [,password]                                     <string>        若需要密码，则提供密码。
        )                                                   -><boolean>
        将当前压缩文件解压到指定的目录，返回值指示是否成功解压，
        解压过程可能影响当前的迭代过程。
        需要可读。

        UncompressAsync(
            path                                            <string>                        解压目录。
            [,password]                                     <string>                        若需要密码，则提供密码。
            [,callBack]                                     <function>#AsyncFunction#       异步回调函数。
        )
        异步将当前压缩文件解压到指定的目录，可以提供一个回调函数，指示是否成功，
        解压过程可能影响当前的迭代过程。
        需要可读，否则异步回调总是返回失败。

        Compress(
            fileNameInZip                                   <string>|<table>                文件被写入zip后的名字或路径。
            [,fileName                                      <string>|<table>                待写入zip的文件名字。
            [,password]]                                    <string>                        加密密码，可选。
        )                                                   -><boolean>                     指示是否写入成功。
        example:
            local zip = Zip.new("example.zip",Zip.W);
            if zip then
                -- 将a.txt写入zip文件的Dir/b.txt
                zip:Compress("Dir/b.txt","a.txt");
                -- 将my/c.txt以加密方式写入pwd.txt中，并打印是否成功。
                print(zip:Compress("pwd.txt","my/c.txt","password"));
                -- 写入一组目录。
                zip:Compress({
                    "dir1/",
                    "dir2/dirSub/",
                    "dir3",-- 会自动添加结尾的'/'
                });
                -- 将一组文件加密写入zip文件。
                zip:Compress(
                    {
                        "file1",
                        "dir3/file2",
                        "test.png"
                    },
                    -- 保证待写入文件和zip内文件列表长度一致。
                    {
                        "文件1",
                        "文件2"，
                        "目录/pic.png"
                    },
                    "password"
                );

                -- 务必delete()以关闭文件。
                zip:delete();
            end

        写入fileName指定的文件到zip的fileNameInZip中，需要可写操作模式。
        若只传入fileNameInZip参数，将以fileNameInZip创建目录。
        fileNameInZip和fileName可以为table，表示将table数组中的文件写入。
        fileName为一个目录时，并不表示将fileName指示的目录中的所有文件写入fileNameInZip。
        添加目录时，会自动添加'/'结尾；但使用'\'结尾可能导致创建的目录不正确（或许以'_'为目录名）。
        已写入的文件无法删除，无法修改，只能通过：解压zip->筛选出不需要文件->新建zip->添加需要文件来删除或修改文件。

        CompressAsync(
            fileNameInZip                                   <string>|<table>                文件被写入zip后的名字或路径。
            [,fileName                                      <string>|<table>                待写入zip的文件名字。
            [,password]]                                    <string>                        加密密码，可选。
            |callBack                                       <function>                      任务回调函数。
        )
        见Compress，唯二不同之处在于：
        1、由于是异步调用，该方法没有返回值；
        2、该方法可以传入一个回调函数。

    #AsyncFunction#
    function(
        sender,                                             <userdata>#ZipFile#             解压工作所属的ZipFile.
        ret                                                 <table>#AsyncData#              异步的通知数据。
    )


    #AsyncData#
    member:
        suc<boolean>
        指示当前工作是否成功完成。

        [error<string>]
        错误信息。


    #ZipItem#
    method:
        Read(
            [password]                                      <string>        文件密码。
        )                                                   -><string>|nil
        读取当前项目，若读取失败，返回nil，
        若当前项目类型为目录，返回空串。

        GetInfo()                                           -><table>#ZipInfo#
        返回一个记录项目信息的table，
        姑且认为是一个ZipInfo类型（C++中确实如此）。


    #ZipInfo#
    member:
        name<string>
        项目名称，若为目录，一定以"/"结尾。

        [size<number>]
        该项目解压后的大小，目录没有该属性。

        date<number>
        项目的日期。

        [encrypt<bool>]
        标识该项目是否加密，目录没有该属性。
]====]

ZipFile.gtor({
    --[[
        返回一个迭代函数，用于迭代Zip中的所有项目，
        不支持嵌套迭代。
        Seek()方法可能会影响迭代过程。
        Uncompress*()方法可能会影响迭代过程。
    ]]
    Iterator = function (self)
        local item = nil;
        return function()
            if not item then
                item = self:First();
            else
                item = self:Next();
            end
            return item;
        end
    end
});


return ZipFile;