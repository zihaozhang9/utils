/*头文件*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
/*命名空间*/
using namespace std;

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
