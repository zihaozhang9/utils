/*头文件*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
/*命名空间*/
using namespace std;

/*切割字符串*/
#pragma region split_find
/*
*用find、substr函数切割字符串；
*/
std::vector<std::string> split_find(std::string str, std::string pattern = ",")
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;
	int size = str.size();
	for (int i = 0; i<size; i++)
	{
		//[c++string.find（）函数用法整理](https://blog.csdn.net/monkeyduck/article/details/23541073)
		pos = str.find(pattern, i);
		if (pos<size)
		{
			//[C++ string substr()](https://blog.csdn.net/sunshihua12829/article/details/50484966)
			std::string s = str.substr(i, pos - i);
			if (s.size()>0) result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
#pragma endregion

#pragma region split_strtok
/*
*用strtok函数切割字符串；可以支持切割多个分隔符
*/
std::vector<std::string> split_strtok(std::string str, std::string pattern = ",")
{
	std::vector<std::string> result;
	char *p = strtok((char*)str.data(), (char const*)pattern.data());
	while (p != NULL) {
		result.push_back(p);
		p = strtok(NULL, (char const*)pattern.data());
	}
	return result;
}
#pragma endregion

/*
vector<string> 转vector<int> 需要：
#include <algorithm>
#include <iterator>
*/
int ToInt(const string &str) { return atoi(str.c_str()); }
vector <int> string2int(vector<string> vs) {
	std::vector <int> vi;
	std::transform(vs.begin(), vs.end(), std::back_inserter(vi), ToInt);
	//std::transform(vs.begin(), vs.end(), std::back_inserter(vi), [](string i) { return atoi(i.c_str()); });
	return vi;
}

void test_split()
{
	std::string str = "1,2;3-4;,-5,";
	cout << str << std::endl << std::endl;
	cout << "test split_find : patter:," << std::endl;
	std::vector<std::string> result = split_find(str, ";");//分割后是3个："1,2"、"3-4"、"-5"
	for (int i = 0; i<result.size(); i++)
	{
		std::cout << "string:" << result[i] << std::endl;
	}

	cout << std::endl << "test split_strtok:  patter:;,-" << std::endl;
	result = split_strtok(str, ";,-");//分割后是5个："1"、"2"、"3"、"4"、"5"
	std::vector <int> vi = string2int(result);
	for (int i = 0; i<vi.size(); i++)
	{
		std::cout << "int:" << vi[i] << std::endl;
	}
}


int main()
{
	/*
	输入字符串
	*/
	char a[10];
	cin >> a;
	cout << a << endl;

	string b;
	cin >> b;
	cout << b << endl;

	char *c = new char[1];
	cin >> c;
	cout << c << endl;

	/*
	参考：https://jingyan.baidu.com/article/86f4a73ec8a08137d652692f.html
	要有cin是输入流的概念
	符合">>"后面的变量会从流里拿出需要的变量（安装FIFO原则）
	cin会自动切分空格，但不会切分逗号
	如果输入的很多个数，一次没抓取完。
	下次再用cin时就不会让你键入了，直接从历史里面拿。
	*/
	int r[100];
	//方式一：
	//cin: 9 0 1 2 4(90124中间有空格)
	for (int i = 1; i <= 3; i++)
	{
		cin >> r[i];
		//此时r的索引1,2,3位置处就是901
	}

	//方式二：
	//cin: 9 0 1 2 4(90124中间有空格)
	cin >> r[0];
	cin >> r[1];//此时r的索引0,1位置处就是90
	cin >> r[2];
	//可以写个循环验证
	for (int i = 0; i <= 10; i++)
	{
		cout << r[i] << endl;
	}

	/*待增加：字符串切分
	排序算法
	*/

	
	/*暂停*/
	system("pause");
	return 0;
}
