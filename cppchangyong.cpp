
//创建多级路径
#include <io.h>
#include <direct.h>
#include <string>
int createDirectory(std::string path)
{
    /*原文链接：https ://blog.csdn.net/yuejisuo1948/article/details/88643491*/
    if (!(path[path.length() - 1] == '\\' || path[path.length() - 1] == '/')) path.append("\\");
    int len = path.length();
    char tmpDirPath[256] = { 0 };
    for (int i = 0; i < len; i++)
    {
        tmpDirPath[i] = path[i];
        if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
        {
            if (_access(tmpDirPath, 0) == -1)
            {
                int ret = _mkdir(tmpDirPath);
                if (ret == -1) return ret;
            }
        }
    }
    return 0;
}
void demo(){
    std::string prefix = "a\\b\\c";
    if (_access(prefix.c_str(), 0) == -1)	//如果文件夹不存在
        createDirectory(prefix.c_str());				//则创建
}
