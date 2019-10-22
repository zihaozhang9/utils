// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <numeric>
#include <limits>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include<vector>
#include<map>
#include <malloc.h>
#include<queue>
#include<functional>
#include<stack>
#include <unordered_map>
#include<set>
//#include <bits/stdc++.h>
//万能头文件
using namespace std;

/* ctrl+M+O收起所有结点，ctrl+M+L展开所有节点 */
/*
#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int n, m, t;
int a[1005][1005], l[1005][1005];
int len[1005], ty[1005][1005], num[1005][1005];
ll sum[1005];
ll ans;
void add(int x, int y)
{
	ll tot = 1;
	while (len[x]>0 && y <= ty[x][len[x]])
	{
		tot = tot + num[x][len[x]];
		sum[x] = sum[x] - (ll)(num[x][len[x]] * ty[x][len[x]]);
		len[x]--;
	}
	len[x]++;
	ty[x][len[x]] = y;
	num[x][len[x]] = tot;
	sum[x] = sum[x] + tot*y;
}
void reset(int x, int y)
{
	len[x] = 1;
	sum[x] = y;
	ty[x][1] = y;
	num[x][1] = 1;
}
int main()
{
	    cin>>n>>m;
	for (int i = 1; i <= n; i++)
		    for(int j=1;j<=m;j++) scanf_s("%d",&a[i][j]);
		for (int i = 1; i <= n; i++)
		{
			l[i][1] = 1;
			for (int j = 2; j <= m; j++)
				if (a[i][j] == a[i][j - 1]) l[i][j] = l[i][j - 1] + 1; else l[i][j] = 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == a[i - 1][j]) add(j, l[i][j]); else reset(j, l[i][j]);
			ans = ans + sum[j];
		}
	cout << ans;
	return 0;
}


#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod = 998244353;
char s[25];
int n, m, x, y;
int cnt[15], base[15], p[15], now[15];
int f[120005][105];
int main()
{
	scanf_s("%s", s + 1);
	cin >> m;
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) cnt[s[i] - 48]++;
	base[0] = 1;
	p[0] = base[0] * cnt[0];
	for (int i = 1; i <= 10; i++)
	{
		base[i] = p[i - 1] + 1;
		p[i] = p[i - 1] + base[i] * cnt[i];
	}
	for (int i = 1; i <= 9; i++)
		if (cnt[i]>0) f[base[i]][i%m] = 1; //第一位为最高位，直接避免前导0，也方便了余数的运算
	for (int i = 1; i<base[10] - 1; i++)
	{
		x = i;
		for (int j = 9; j >= 0; j--)
			if (cnt[j]>0)
			{
				now[j] = cnt[j] - (x / base[j]); //now表示某数还有几个 
				x = x%base[j];
			}
		for (int j = 0; j <= 9; j++)
			if (now[j]>0)
			{
				for (int k = 0; k<m; k++)
				{
					y = ((k * 10) % m + j) % m;
					f[i + base[j]][y] = (f[i + base[j]][y] + f[i][k]) % mod;
				}
			}
	}
	cout << f[base[10] - 1][0];
	return 0;
}
*/ 

/*打印一数组的所有子集*/
/*
int main()
{
	char a[5] = { 'a', 'b', 'v', 'c' ,'d'};
	int i, j, k;
	int t = 1 << 5;
	for (i = 0; i < t; i++)
	{
		j = i;
		k = 0;
		printf("{");
		while (j)
		{
			if (j & 1)
			{
				printf("%c", a[k]);
			}
			j >>= 1;
			++k;
		}
		printf("}\n");
	}
	return 0;
}
*/

/*正数在右负数在左,保持原有顺序*/
/*
int main()
{
	int a[] = { 1,-2,3,-4,4,-4,6,5,-9,-3 };
	int length=sizeof(a)/sizeof(int);
	int i,j=0;
	int b[100];
	for (i = 0; i < length; i++)
	{
		if (a[i] < 0)
		{
			b[j++] = a[i];
		}
	}
	for (i = 0; i < length; i++)
	{
		if (a[i] > 0)
		{
			b[j++] = a[i];
		}
	}
	for (i = 0; i < length; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}
//*/

/*O(1)复杂度解法*/
/*
#include <iostream>
using namespace std;

void sort(int *a, int len)
{
	int i;
	int dataLen = 1;
	for (int j = len - 1; j >= 0; j--)
		if (a[j] < 0)
		{
			i = j;
			break;
		}

	while (i > 0)
	{
		while (i>0 && a[i - 1] < 0)
		{
			i--;
			dataLen++;
		}
		if (i == 0)
			break; //如果到最前面都是负数，那么已经排好了，直接返回
		int temp = a[i - 1];
		memcpy(&a[i - 1], &a[i], dataLen * sizeof(int));//这里注意memcpy的操作单位为字节
		a[i + dataLen - 1] = temp;
		i--;
	}
}
int main()
{
	int a[] = { -3, 4, 2, -1, 7, 3, -5 };
	int len = 7;
	sort(a, len);
	for (int i = 0; i<len; i++)
		cout << a[i] << endl;
	return 0;
}
*/

/*字符串反转*/
/*
int main()
{
	char str[] = "abcdefgh";
	int length,i;
	char tmp;
	length = sizeof(str) / sizeof(char);
	for (i = 0; i < length / 2; i++)
	{
		tmp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = tmp;
	}
	for (i = 0; i < length; i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}
//*/
/*求1-100之间的质数*/

/*
int zhishu(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i;
	for (i = 2; i <= 100; i++)
	{
		if (zhishu(i))
			cout << i << " ";
	}
	cout << endl;
}
//*/

/*斐波那契数列*/
/*
int main()
{
	int a[1000];
	int n;
	cin >> n;
	a[0] = 1;
	a[1] = 1;
	int i;
	for (i = 2; i < n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl;
}
//*/

/*二分法查找*/
/*
int erfen(int a[],int length,int res)
{
	int max, min, mid;
	max = length - 1;
	min = 0;
	while (max >= min)
	{
		mid = (max + min) / 2;
		if (a[mid] == res)
		{
			return mid;
		}
		if (res > a[mid])
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	return -1;


}

int main()
{
	int res = 8;
	int a[] = { 1,3,5,6,7,8,9,12,14,15,16 };
	int length;
	int aa;
	length = sizeof(a) / sizeof(int);
	aa=erfen(a, length, res);
	cout << aa << endl;
}
*/

/*冒泡法排序*/
/*
void bubbleSort(int a[], int length)
{
	int flag = 1;
	int i, j;
	int tmp;
	for (i = 0; i < length - 1 && flag==1; i++)
	{
		flag = 0;
		for (j = 0; j < length  - i-1; j++)
		{
			if (a[j] < a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
				flag = 1;
			}
		}
	}
	for (i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//*/

/*简单选择排序*/
/*
void SelectSort(int a[], int length)
{
	int index;
	int tmp;
	int i,j;
	for (i = 0; i < length-1; i++)
	{
		index = i;
		for (j = i + 1; j < length; j++)
		{
			if (a[j] > a[index])
				index = j;
		}
		tmp = a[index];
		a[index] = a[i];
		a[i] = tmp;
	}
	for (i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//*/

/*插入排序*/
/*
void InsertionSort(int a[], int length)
{
	int i;
	int InsertValue, InsertIndex;
	for (i = 0; i < length; i++)
	{
		InsertValue = a[i];
		InsertIndex = i - 1;
		while (InsertIndex > 0 && InsertValue < a[InsertIndex])
		{
			a[InsertIndex + 1] = a[InsertIndex];
			InsertIndex--;
		}
		a[InsertIndex + 1] = InsertValue;
	}
	for (i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//*/

/*希尔排序*/

/*排序主函数*/
/*
int main()
{
	int a[] = { 1,3,2,6,4,7,8,44,9,10,17 };
	int length = sizeof(a) / sizeof(int);
	//bubbleSort(a, length);
	//SelectSort(a, length);
	//InsertionSort(a, length);
}
//*/

/*京东笔试*/
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string str;
	cin >> n;
	cin >> str;
	int count = 0;
	int sum = 0;
	int i,j=0;
	while (j < n)
	{
		for (i = j; i < n; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				count++;
			}
			else
				break;
		}
		if (count >= 2)
		{
			sum += (count + 2);
		}
		if(count==1)
		{
			sum += (count + 1);
		}
		count = 0;
		j = i;
		for (i = j; i < n; i++)
		{
			if (str[i] >= 'a'&&str[i] <= 'z')
			{
				sum++;
			}
			else
				break;
		}
		j = i;	
	}
	if (str[n - 1] >= 'A'&&str[n - 1] <= 'Z'&&str[n - 2] >= 'A'&&str[n - 2] <= 'Z')
	{
		sum--;
	}

	cout << sum << endl;
}
//*/

/*
#include<iostream>
using namespace std;
int main()
{
	int n, i;
	int a[100][2];
	int ltime;
	int b[1][2];
	int max = 24 * 60;
	int j;
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> a[i][0];
		cin >> a[i][1];
	}
	cin >> ltime;
	cin >> b[0][0];
	cin >> b[0][1];
	int aa[100];
	int res = b[0][0] * 60 + b[0][1] - ltime;

	for (i = 0; i<n; i++)
	{
		aa[i] = a[i][0] * 60 + a[i][1] - res;
		if (aa[i] >= 0 && aa[i]<max)
		{
			max = aa[i];
			j = i;
		}
	}
	cout << a[j][0] << " " << a[j][1] << endl;
}
//*/

/*
#include<iostream>
using namespace std;
int main()
{
	int n, i,j,g;
	int maxx = -1;
	int a[20000];
	int max[1000] = { 0 };
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> a[i];
	}

	int bian = n / 2;
	int yu = n % 2;

	if (yu == 0 )
	{
		j = 0;
		g = 0;
		while (g < bian)
		{
			for (i = 0 + g; i < n; i += 2)
			{
				max[j] += a[i];
				j++;
			}
			g++;
		}
	}
	for (i = 0; i < j; i++)
	{
		if (maxx < max[i])
			maxx = max[i];
	}
	cout << maxx << endl;
	
}
*/

/*
#include<iostream>
using namespace std;
int main()
{
	int n, m, i;
	cin >> n;
	cin >> m;
	int c[1000];
	int res = 10000000;
	for (i = 0; i<m; i++)
	{
		cin >> c[i];//c[i]是小于n的
	}
	int a[1000] = { 0 };
	for (i = 0; i<m; i++)
	{
		a[c[i]]++;
	}
	for (i = 1; i<=n; i++)
	{
		cout << i << "  " << a[i] << endl;
		if (a[i] < res)
			res = a[i];
	}
	cout << res << endl;
}
*/

/*
int main()
{
	string a="abcde";
//	cin >> a;
	int i, j, k, m=0;
	int length;
//	length= a.length();
	string b[100000];
	int t = 1 << 5;
	for (i = 0; i < t; i++)
	{
		j = i;
		k = 0;
		while (j)
		{
			if (j & 1)
			{
				b[m]+=a[k];
			}
			j >>= 1;
			++k;
		}
		m++;
	}
	for (i = 0; i < m; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
*/

/*
int main()
{
	string a;
	cin >> a;
	int count , max = 1;
	int i, j, k, m = 0;
	string b[1000] = {};
	int t = 1 << a.size();
	for (i = 0; i < t; i++)
	{
		j = i;
		k = 0;
		while (j)
		{
			if (j & 1)
			{
				b[m] += a[k];
			}
			j >>= 1;
			++k;
		}
		m++;
	}
	for (i = 0; i < m-1; i++)
	{
		count = 1;
		for (int j = i + 1; j < m; j++)
		{
			if (b[i]==b[j])
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}

//*/

/*薯队长写了一篇笔记草稿，请你帮忙输出最后内容。*/
/*
1.输入字符包括英文字符，"(" , ")" 和 "<"。

2.英文字符表示笔记内容。

3. (  ) 之间表示注释内容，任何字符都无效。 括号保证成对出现。

4. "<" 表示退格, 删去前面一个笔记内容字符。 括号不受 "<" 影响 。

*/

/*
void Output(char val)
{
	cout << val;
}

int main()
{
	string str;
	vector<char> res;
	int length;
	cin >> str;
	length = str.size();
	int i = 0, flag = 0;
	while(i<length)
	{
		if ((str[i] >= 'a'&&str[i] <= 'z' || str[i] >= 'A'&&str[i] <= 'Z')&&flag==0)
		{
			res.push_back(str[i]);
		}
		if (str[i] == '<'&&flag == 0 && !res.empty())
		{
			res.pop_back();
		}
		if (str[i] == '(')
		{
			flag++;
		}
		if (str[i] == ')')
		{
			flag--;
		}
		i++;
	}
	for_each(res.begin(), res.end(), Output);
	cout << endl;
}
*/

/*小红书笔试3*/
/*
int main()
{
	int N, i;
	int X[10000];
	int H[10000];
	int a[10000];
	int b[10000];
	multimap<int, int>cMap,dMap;
	cin >> N;
	int count1 = 1, count2 =1, res;
	for (i = 0; i< N; i++)
	{
		cin >> X[i] >> H[i];
	}
	for (i = 0; i < N; i++)
	{
		cMap.insert(multimap<int, int>::value_type(X[i], H[i]));
		dMap.insert(multimap<int, int>::value_type(H[i], X[i]));
	}
	multimap<int, int>::iterator it;
	i = 0;
	for (it = cMap.begin(); it != cMap.end(); it++)
	{
	//	cout << (*it).first << "->";
	//	cout << (*it).second << endl;
		if(it->first== (++it)->first)
			if (it->second < (++it)->second)
			{
				int tmp = it->second;
				it->second = (++it)->second;
				(++it)->second = tmp;
			}
		a[i++] = (it)->second;
	}
	cout << endl;
	for (it = dMap.begin(); it != dMap.end(); it++)
	{

		if (it->first == (++it)->first)
			if (it->second < (++it)->second)
			{
				int tmp = it->second;
				it->second = (++it)->second;
				(++it)->second = tmp;
			}
		b[i++] = (*it).second;
			cout << (*it).first << "->";
			cout << (*it).second << endl;
	}
	/*
	for (i = 0; i < N; i++)
	{
		if (a[i + 1] > a[i])
		{
			count1++;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (b[i + 1] > b[i])
		{
			count2++;
		}
		else
		{
			break;
		}
	}
	if (count1 > count2)
		res = count1;
	else
	{
		res = count2;
	}
//	cout << res << endl;
	//

	for (i = 0; i < N; i++)
	{
//		cout << a[i] << " ";
	}
}

*/

/* 将字符串中的空格替换为%20 */
/*
int main()
{
	string str;
	string res;
	getline(cin, str);
	int length = str.length();
	int i=0;
	while(i<length)
	{
		if (str[i] != ' ')
		{
			res += str[i];
			i++;
		}
		if (str[i] == ' ')
		{
			if (str[i + 1] != ' ')
			{
				res += "%20";
				i++;
			}
			else
				i++;
		}
	}
	cout << res << endl;
}
//*/

/*
  请完成下面这个函数，实现题目要求的功能
//当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^

string resolve(string str,int length)
{
	string res1[100], res2[100], res;
	int flag = 0;
	int i,j=0,k=0;
	for (i = 0; i < length; i++)
	{
		if (str[i] == '(')
		{
			flag++;
		}
		if (str[i] == ')')
		{
			flag--;
		}
		if (flag %2 == 1 && str[i] != ')' && str[i] != '(')
		{
			res1[j] += str[i];
		}
		if (flag %2 == 0 && str[i] != ')' && str[i] != '(')
		{
			res2[k] += str[i];
		}
		j++; k++;
	}
	for(i=j;i>=0;i--)
		reverse(res1[i].begin(), res1[i].end());
	i = j ? k : j > k;
	
	for (i; i >= 0; i--)
	{
		res += res1[i];
		res += res2[i];
	}
	return res;

}

int main() {
	string res;
	string _expr;
	getline(cin, _expr);
	int length = _expr.size();
	res = resolve(_expr,length);
	cout << res << endl;

	return 0;

}
//*/

/*
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	vector<int> arr, res;
	while (head)
	{
		arr.push_back(head->val);
		head = head->next;
	}
	int length = arr.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (arr[i] <= m)
		{
			res.push_back(arr[i]);
		}
	}
	for (i = 0; i < length; i++)
	{
		if (arr[i] > m)
		{
			res.push_back(arr[i]);
		}
	}
	int tt = res.size();
	for (i = 0; i < tt-1; i++)
	{
		cout << res[i] << ",";
	}
	cout << res[tt-1] << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

const int MAX_COUNT = 100;
int state[MAX_COUNT][MAX_COUNT];
int a[MAX_COUNT];

int main()
{
	
	int n;
	int m;
	int i = 0, j = 0, k = 0, temp = 0, MaxInt;
	cin >> m >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i <= n; ++i)
	{
		state[i][1] = state[i - 1][1] + a[i];
	}
	for (j = 2; j <= m; ++j)
	{
		for (i = j; i <= n; ++i)
		{
			temp = 10000000;
			for (k = j; k < i; ++k)
			{
				MaxInt = max(state[i][1] - state[k][1], state[k][j - 1]);
				if (temp > MaxInt)
				{
					temp = MaxInt;
				}
			}
			state[i][j] = temp;
		}
	}
	cout<< state[n][m];
}
*/

/*链表原地逆序*/

/*
class Solution {
public:
	vector<int> printListFromTailToHead(struct ListNode* head) {
		vector<int> vec;
		ListNode *buf = head;
		ListNode *pre = buf;
		if (head == NULL)
			return vec;
		while (head->next != NULL) {
			//vec.push_back(head->next->val);

			buf = head->next;
			head->next = buf->next;
			buf->next = pre;
			pre = buf;
		}
		while (buf) {
			vec.push_back(buf->val);
			buf = buf->next;
		}
		return vec;

	}
};
//*/

/*小米笔试题1*/
/*
string removeKdigits(string num, int k)
{
	int N = num.size();
	if (k == 0)
	{
		return num;
	}
	if (N <= k)
	{
		return "0";
	}
	vector<char> storage;
	for (int i = 0; i < N; i++)
	{
		while (storage.size() != 0 && storage.back() > num[i] && k != 0)
		{
			storage.pop_back();
			k--;
		}
		storage.push_back(num[i]);
	}
	while (k != 0)
	{
		storage.pop_back();
		k--;
	}
	int i = 0;
	for (; i < storage.size(); i++)
	{
		if (storage[i] != '0')
		{
			break;
		}
	}
	string res = "";
	for (int j = i; j < storage.size(); j++)
	{
		res += storage[j];
	}
	return res == "" ? "0" : res;
}
int main()
{
	int n;
	string str;
	string res;
//	scanf_s("%s,%d\n", &str, &n);
	cin >>  str >> n ;
	res= removeKdigits(str,n);
	cout << res << endl;
}
//*/

/*小米笔试题2*/
/*
int maxProfit(vector<int>& a) {
	if (a.size() < 2) return 0;

	int res = 0;
	int left = 0, right = 1;

	while (right < a.size()) {

		if (a[left] > a[right]) {
			left = right;
		}
		else if (a[left] < a[right]) {
			res = (a[right] - a[left]) > res ? (a[right] - a[left]) : res;
		}
		right++;
	}

	return res;
}
int main()
{
	vector<int> a;
	int c,res;
	while (cin >> c)
	{
		a.push_back(c);
	}
	res = maxProfit(a);
	cout << res << endl;
}
*/

/*string 转int */
/*
int main()
{
	string s = "121234";
	int a = atoi(s.c_str());
	a += 1;
	cout << a << endl;
}
//*/

/*二叉树相关*/
/*
typedef struct BiTNode
{
	char data;   //结点的数据域
	struct BiTNode *lchild, *rchild;  //指向左孩子和右孩子
} BiTNode, *BiTree;

//*创建一棵二叉树
void CreatBiTree(BiTree *T) {
	char c;
	scanf_s("%c", &c);
	if (c == ' ') *T = NULL;
	else 
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));  //*创建根结点
		(*T)->data = c;    //*向根结点中输入数据
		CreatBiTree(&((*T)->lchild));  //*递归地创建左子树
		CreatBiTree(&((*T)->rchild));  //*递归地创建右子树
	}
}

//递归法前序遍历二叉树
void PreOrderTraverse(BiTree T) 
{
	if (T) 
	{   //*递归结束条件，T为空
		printf("%3c", T->data);  //*访问根结点,将根结点内容输出
		PreOrderTraverse(T->lchild);  //*先序遍历T的左子树
		PreOrderTraverse(T->rchild);  //*先序遍历T的右子数
	}
}

//非递归前序遍历
void UPreOrderTraverse(BiTree T)
{
	int res;
	if (T != NULL)
	{
	stack<int> stack1;
	stack1.push(T->data);
	while (!stack1.empty())
	{
		res = stack1.top();
		stack1.pop();
		cout << res << " ";
		if (T->rchild != NULL)
		{
			stack1.push(T->rchild->data);
		}
		if (T->lchild != NULL)
		{
			stack1.push(T->lchild->data);
		}
	}
	}

}


void InOrderTraverse(BiTree T) {
if (T) {   //如果二叉树为空，递归遍历结束
InOrderTraverse(T->lchild);  //*中序遍历T的左子树
printf("%3c", T->data);      //*访问根结点
InOrderTraverse(T->rchild);  //*中序遍历T的右子数
}
}

void PosOrderTraverse(BiTree T) {
if (T) {   //*如果二叉树为空，递归遍历结束
PosOrderTraverse(T->lchild);  //*后序遍历T的左子树
PosOrderTraverse(T->rchild);  //*后序遍历T的右子数
printf("%3c", T->data);       //*访问根结点
}
}


int main()
{
BiTree T = NULL;  //最开始T指向空
printf("输入一些字符以创建二叉树:\n");
CreatBiTree(&T);  //创建二叉树
printf("The squence of preorder traversaling binary tree\n");
PreOrderTraverse(T); //*先序遍历二叉树
printf("\nThe squence of inorder traversaling binary tree\n");
InOrderTraverse(T);  //中序遍历二叉树
printf("\nThe squence of posorder traversaling binary tree\n");
PosOrderTraverse(T); //后序遍历二叉树
getchar();
getchar();
}

//*/

/*求无需数组的中位数*/
/*
void FindMid(vector<int> a, int size)
{
	if (a.empty() || size<1)
		return;
	priority_queue<int> q;   //创建一个大堆
	for (int i = 0; i<size / 2 + 1; ++i)    //将前size/2的元素放入堆中
		q.push(a[i]);
	int top = q.top();
	for (int i = size / 2 + 1; i<size; ++i)   //将后半部分的元素一一与堆顶比较
	{
		if (a[i]<top)
		{
			q.pop();
			q.push(a[i]);
		}
		top = q.top();
	}
	if (0 == size % 2)     //判断奇偶，从而判断是几个中位数
	{
		q.pop();
		int top1 = q.top();
		cout << "中位数是" << top << "和" << top1 << endl;
	}
	else
	{
		cout << "中位数是" << top << endl;
	}
}

int main()
{
	//int a[] = { 2,5,4,9,3,6,8,7,1 };//中位数是5
	//int b[] = { 2,5,4,9,3,6,8,7,1,0 };//中位数是4和5
	//int len = sizeof(a) / sizeof(a[0]);
	//int lenb = sizeof(b) / sizeof(b[0]);
	vector<int> a;
	int c;
	while (cin >> c)
	{
		a.push_back(c);
	}
	int len = a.size();
	FindMid(a, len);
	//FindMid(b, lenb);
}
//*/


/*构建堆*/
/*
void  useCmpGreater() {
	cout << "=========useCmpGreater(small heap)========" << endl;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < 10; i++) {
		q.push(rand() % 20);
	}

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	cout << "=========defaultCmpLess(big heap)========" << endl;
	priority_queue<int> q;
	for (int i = 0; i < 10; i++) {
		q.push(rand() % 20);
	}

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	useCmpGreater();
}
//*/

/*判断一句话是否为回文*/
/*
int main()
{
	string str;
	string res[1000];
	int length;
	int i, j=0;
	getline(cin, str);
	length = str.size();
	for (i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			res[j] += str[i];
		}
		else
			j++;
	}
	int count = j;
	if (count == 1)
	{
		if (res[0] == res[1])
		{
			cout << "yes" << endl;
			return 0;
		}
		else
		{
			cout << "no" << endl;
			return 0;
		}
	}
	int tmp = count / 2;
	for (j = 0; j < tmp; j++)
	{
		for (i = 0; i < res[j].size(); i++)
		{
			if (res[j][i] != res[count - j][i])
			{
				cout << "no" << endl;
				return 0;
			}
		}
	}
	cout << "yes" << endl;
}
//*/

/*
int qiujie(string s, int n) {
	if (n <= 0)
	{
		return 0;
	}
	unordered_map<int, int> count;
	int i = 0, j = 0;
	int max_length = -1;
	while (j<s.size())
	{
		if (count.size() <= n)
		{
			max_length = max(max_length, j - i);
			count[s[j]]++;
			j++;
		}
		while (count.size()>n)
		{
			count[s[i]]--;
			if (count[s[i]] == 0) count.erase(s[i]);
			i++;
		}
	}
	if (count.size() <= n) max_length = max(max_length, j - i);
	return max_length;
}

int main()
{
	int n,res;
	string str;
	cin >> n;
	cin >> str;
	res= qiujie(str, n);
	cout << res << endl;
}
//*/

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/
/*
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int length = sequence.size();
		if (length == 0)
			return false;
		if (length == 1)
			return true;
		return judge(sequence, 0, length - 1);
	}
	bool judge(vector<int> a, int start, int end)
	{
		if (start >= end)
		{
			return true;
		}
		int i = start;
		while (a[i] < a[end])
		{
			i++;
		}
		for (int j = i; j<end; j++)
		{
			if (a[j]<a[end])
				return false;
		}
		return judge(a, start, i - 1) && judge(a, i, end - 1);
	}
};
*/

/*
#include <iostream>  
using namespace std;
class A
{
private:
	int a;
public:
	A(int i) { a = i; }  //内联的构造函数  
	A(A &aa);
	int geta() { return a; }
};

A::A(A &aa)     //拷贝构造函数  
{
	a = aa.a;
	cout << "拷贝构造函数执行！" << endl;
}

int get_a(A aa)     //参数是对象，是值传递，会调用拷贝构造函数  
{
	return aa.geta();
}

int get_a_1(A &aa)  //如果参数是引用类型，本身就是引用传递，所以不会调用拷贝构造函数  
{
	return aa.geta();
}

A get_A()           //返回值是对象类型，会调用拷贝构造函数。会调用拷贝构造函数，因为函数体内生成的对象aa是临时的，离开这个函数就消失了。所有会调用拷贝构造函数复制一份。  
{
	A aa(1);
	return aa;
}

A& get_A_1()    //会调用拷贝构造函数，因为函数体内生成的对象aa是临时的，离开这个函数就消失了。所有会调用拷贝构造函数复制一份。  
{
	A aa(1);
	return aa;
}

int _tmain(int argc, _TCHAR* argv[])
{
	A a1(1);
	A b1(a1);           //用a1初始化b1，调用拷贝构造函数  
	A c1 = a1;            //用a1初始化c1，调用拷贝构造函数  

	int i = get_a(a1);        //函数形参是类的对象，调用拷贝构造函数  
	int j = get_a_1(a1);      //函数形参类型是引用，不调用拷贝构造函数  

	A d1 = get_A();       //调用拷贝构造函数  
	A e1 = get_A_1();     //调用拷贝构造函数  

	return 0;
}
*/

/*
#include <numeric>
#include <limits>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include<vector>
#include<map>
#include <malloc.h>
#include<queue>
#include<functional>
#include<stack>
#include <unordered_map>
using namespace std;
int main()
{
	int n, i, c;
	cin >> n;
	int a[100000];
	for (i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	priority_queue<int> q;
	for (int i = 0; i<n; ++i)
		q.push(a[i]);
	int aa;
	aa = n / 100;
	if (n % 100 != 0)
		aa++;
	for (i = 0; i < aa; i++)
	{
		int flag;
		flag = q.top();
		cout << flag << endl;
		q.pop();
	}

}
//*/

/*
int main()
{
	//int a[] = { 1,4,5,26,5,2,3,1,5,4,8,5 };
//	vector<string> a;
	string a;
	getline(cin, a);
//	a.push_back(str);
	//int count = sizeof(a) / sizeof(a[0]);
	int count = a.size();
	int n = 0;
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (a[i] == a[j]) { //改 if ( p[i] == p[j]) {
				n++;
				break;//加
			}
		}
		//移 printf("%d", count - n);
	}
	printf("%d\n", count - n-1);
	return 0;
}
*/


/*
int minpathsum(int grid[100][100],int m,int n)
{
	int rows = m;
	int cols = n;
	vector<vector<int>> data(rows, vector<int>(cols, grid[0][0]));

	for (int i = 1; i < rows; ++i)
	{
		data[i][0] = data[i - 1][0] + grid[i][0];
	}

	for (int i = 1; i < cols; ++i)
	{
		data[0][i] = data[0][i - 1] + grid[0][i];
	}

	for (int i = 1; i < rows; ++i)
	{
		for (int j = 1; j < cols; ++j)
		{
			data[i][j] = min(data[i][j - 1], data[i - 1][j]) + grid[i][j];
		}
	}
	return data[rows - 1][cols - 1];
}
int main()
{
	int m, n;
	int i, j;
	cin >> m;
	cin >> n;
	int grid[100][100];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}
	cout << minpathsum(grid,m,n) << endl;
}
//*/


/*
int candy(vector<int>&rating) {

	int res = 0;
	int n = rating.size();
	vector<int> candy(n, 1);
	for (int i = 0; i < n - 1; i++) {
		if (rating[i + 1] > rating[i])candy[i + 1] = candy[i] + 1;
	}
	for (int i = n - 1; i > 0; i--) {
		if (rating[i - 1] > rating[i] && candy[i - 1] <= candy[i])candy[i - 1] = candy[i] + 1;
	}

	for (auto a : candy) {
		res += a;
	}

	return res;
}

int main() {

	vector<int> rating;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		rating.push_back(t);
	}
	cout << candy(rating) << endl;
	return 0;
}
*/

/*
int main()
{
//	int a[] = { 1,4,5,26,5,2,3,1,5,4,8,5 };
	vector<int> a;
	int c;
	while (cin >> c)
	{
		a.push_back(c);
	}
	int count = a.size();// = sizeof(a) / sizeof(a[0]);
	int n = 0;
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (a[i] == a[j]) 
			{ 
				n++;
				break;
			}
		}
	}
	printf("%d\n", count - n);
	return 0;
}
*/

/*招商银行信用卡中心笔试1*/
/*
int main()
{
	string str;
	int a[10000];
	long long b = 3;// pow(10, 100);
	getline(cin, str);
	int length = str.size();
	int i;
	for (i = 0; i < length; i++)
	{
		a[i] = 1;//初始化每个值均为1；
	}
	while (b--)
	{
		for (i = 0; i < length; i++)
		{
			if (str[i] == 'R')
			{
				if (a[i] > 0)
				{
					a[i]--;
					a[i + 1]++;
				}
			}
			if (str[i] == 'L')
			{
				if (a[i] > 0)
				{
					a[i]--;
					a[i - 1]++;
				}
			}
		}
	}
	for (i = 0; i < length; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//*/

/*招商银行信用卡中心笔试2*/
/*
bool panduan(int x)
{
	if (x % 13 == 5)
	{
		return true;
	}
	else
		return false;
}
int main()
{
	int length;
	string str;
	string res1, res2;
	getline(cin, str);
	length = str.size();
	int i;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (str[i] == '?')
		{
			res1 += '0';
			res2 += '9';
		}
	}
	int a = atoi(res1.c_str());//字符串转数字
	int b = atoi(res2.c_str());
	for (i = a; i < b; i++)
	{
		if (panduan(i))
		{
			count++;
		}
	}
	cout << count << endl;
}
*/

/*
int main()
{
	int a[150000] = { 0 };
	int M, N;
	int L[1000];
	int R[1000];
	cin >> N >> M;
	int i, j;
	int sum = 0;
	for (i = 0; i < M; i++)
	{
		cin >> L[i];
		cin >> R[i];
	}
	for (j = 0; j < M; j++)
	{
		for (i = L[j]; i <= R[j]; i++)
		{
			a[i] = j+1;
		}
	}
	for (i = 0; i < N; i++)
	{
		sum += (i*a[i]);
//		cout << a[i] << " ";
	}
	sum = sum % 100000009;
	cout << sum << endl;
}
//*/

/*
bool panduan(string str1, string str2)
{
	int i,j;
	i = 0, j = 0;
	while (1)
	{
		if (str1[0] == '*')
		{
			i = str1.size() - 1;
			j = str2.size() - 1;
			while (i > 1)
			{
				if (str1[i] == str2[j])
				{
					i--;
					j--;
				}
				else
					return false;
			}
			return true;
		}
		if (str1[0] != '*')
		{
			i = 0, j = 0;
			while (str1[i] != '*')
			{
				if (str1[i] == str2[j])
				{
					i++;
					j++;
				}
				else
					return false;
			}
			return true;
		}
	}
}

int main()
{
	int m, n;
	cin >> n;
	cin >> m;
	string str1[1000],str2[1000];
	int i,j;
	for (i = 0; i < n; i++)
	{
		cin >> str1[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> str2[i];
	}
	///////////
	j = 0;
	while (j < m )
	{
		int flag = 0;
		for (i = 0; i < n; i++)
		{
			if (panduan(str1[i], str2[j]))
			{
				cout << 1 << " ";
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << 0 << " ";
		}
		j++;
	}
}
*/

/*
int length(vector<int> &num)
{
	if (num.size() == 0)
	{
		return 0;
	}
	map<int, int>m;
	vector<int>::iterator i = num.begin();
	vector<int>::iterator j = num.end();

	for (; i != j; i++)
	{
		if (m.find(*i) == m.end())
		{
			m.insert(pair<int, int>(*i, 1));
		}
	}
	int maxlen = 0;
	int len = 0;
	for (i = num.begin(); i != j; i++)
	{
		if (m[*i] > 0)
		{
			int index = *i;
			len = 0;
			for (; m.find(index) != m.end(); ++len, m[index++] = -1);
			for (index = *i - 1; m.find(index) != m.end(); ++len, m[index--] = -1);
			if (len > maxlen)
			{
				maxlen = len;
			}
		}
	}
	return maxlen;
}

int main()
{
	int n,a;
	vector<int> res;
	cin >> n;
	while (n--)
	{
		cin >> a;
		res.push_back(a);
	}
	cout << length(res) << endl;
	return 0;
}
*/

/*ipv4和ipv6匹配问题*/
/*
bool IsIpv6(char*str)
{
	char* ptr;
	int count = 0;
	const char *p = str;

	while (*p != '\0')
	{
		if (*p == ':')
			return true;
	}
	return false;
}


bool IsIpv4(char*str)
{
	char* ptr;
	int count = 0;
	const char *p = str;

	while (*p != '\0')
	{
		if (*p == '.')
			count++;
		p++;
	}

	if (count != 3)  return false;
	count = 0;
	ptr = strtok(str, ".");
	while (ptr != NULL)
	{
		count++;
		if (ptr[0] == '0' && isdigit(ptr[1])) return false;
		int a = atoi(ptr);
		if (count == 1 && a == 0) return false;
		if (a<0 || a>255) return false;
		ptr = strtok(NULL, ".");

	}
	if (count == 4)  return true;
	else  return false;
}

int main()
{
	char buf[100];
	while (cin >> buf)
	{
		if (IsIpv4(buf))
		{
			cout << "IPv4" << endl;
		}
		if (IsIpv6(buf))
		{
			cout << "IPv6" << endl;
		}
		else
		{
			cout << "Neither" << endl;
		}

	}
	return 0;
}
*/

/*电话号码里边的字符排序*/
/*
void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k)
{
	if (str.size() == digits.size()) {
		res.push_back(str);
		return;
	}
	string tmp = m[digits[k]];
	for (char w : tmp) {
		str += w;
		func(res, str, digits, m, k + 1);
		str.pop_back();
	}
	return ;
}

vector<string> letterCombinations(string digits)
{
	unordered_map<char, string> table{
		{ '0', " " },{ '1',"*" },{ '2', "abc" },
		{ '3',"def" },{ '4',"ghi" },{ '5',"jkl" },
		{ '6',"mno" },{ '7',"pqrs" },{ '8',"tuv" },
		{ '9',"wxyz" } 
	};
	vector<string> res;
	if (digits == "") return res;
	func(res, "", digits, table, 0);
	return res;
}

int main()
{
	string str;
	vector<string> res;
	getline(cin, str);
	res=letterCombinations(str);
	int i;
	cout << "[";
	for (i = 0; i < res.size()-1; i++)
	{
		cout << res[i] << ", " ;
	}
	cout << res[i] << "]";
	return 0;
}


//*/


/*求等差数列最长子序列*/
/*
int main()
{
	int n, a;
	vector<int> res;
	cin >> n;
	while (n--)
	{
		cin >> a;
		res.push_back(a);
	}
	int length = res.size();

	sort(res.begin(), res.end());
	int max = 0,count;
	int i, j;
	for (i = 0; i < length - 1; i++)
	{
		count = 1;
		for (j = i + 1; j < length; j++)
		{
			if (res[j] - res[i] == (j - i)*(res[i + 1] - res[i]))
			{
				count++;
				if (count > max)
				{
					max = count;
				}
			}
			else
				break;
		}
	}
	if (length <= 2)
	{
		max = length;
	}
	cout << max << endl;
}
//*/


/*找出第三小的数字*/
/*
int main()
{
	int n,c;
	vector<int> ss;
	set<int>res;
	set<int>::iterator it;
	cin >> n;
	while (n--)
	{
		cin >> c;
		res.insert(c);
	}
	int length = res.size();
	for (it = res.begin(); it != res.end(); it++)
	{
		ss.push_back(*it);
	}
	if (ss.size() < 3)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << ss[2] << endl;
}
//*/

/*
度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作：任取数组中的一个数然后将它放置在数组的最后一个位置。问最少操作多少次可以使得数组从小到大有序？*/
/*
int main()
{
	int n;
	cin >> n;
	vector<int>res1,res2;
	for(int i=0;i<n;i++)
	{
		int c;
		cin >> c;
		res1.push_back(c);
		res2.push_back(c);
	}
	sort(res1.begin(), res1.end());//res1默认升序
	int i=0,j=0;
	int count = 0;
	while (i <n-1 && j < n )
	{
		if (res2[i] != res1[j])
		{
			i++;
		}
		if(res2[i]==res1[j])
		{
			i++;
			j++;
			count++;
		}
	}
	cout << n - count << endl;
}
//*/

/*链表合并*/
struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x):
		val(x), next(NULL) {}
};

/*括号匹配*/
/*
int main()
{
	string s;
	cin >> s;
	stack<char>st;
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			if (st.top() == '(')
				st.pop();
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if (s[i] == ']')
		{
			if (st.top() == '[')
				st.pop();
			else
			{
				cout << "false";
				return 0;
			}
		}
		else
			continue;
	}
	if (st.empty())
		cout << "true";
	else
		cout << "false";
	return 0;
}
//*/
/*二进制加法*/
/*
int main() {
	string a, b, s = "";
	cin >> a >> b;
	int m = a.length(), n = b.length();
	int c = 0;
	if (m>n)
		b = string(m - n, '0') + b;
	else
		a = string(n - m, '0') + a;
	for (int i = max(m, n) - 1; i >= 0; i--) {
		c += a[i] - '0' + b[i] - '0';
		s = char((c & 1) + '0') + s;
		c >>= 1;
	}
	if (c == 1)
		s = '1' + s;
	cout << s << endl;
	return 0;
}
//*/

/*小猪划拳问题*/
/*
int main()
{
	int n, m;
	cin >> n >> m;
	int c = 2*m-n;//quanjiandan
	int d = n - m;//quanshitou
	if (d > c)
	{
		cout << d << endl;
		return 0;
	}
	else
	{
		cout << c << endl;
		return 0;
	}
}
*/

/*改错题*/
/*
int func1(int a=1, int b)//默认实参必须在形参列表的最后
{
	return a + b;
}
int sum()
{
	int sum;
	int* const point1;//指针常量必须要在定义的时候初始化
	int const* point2;
	point1 = &sum;
	point2 = func1(3, 4);//不能将int变量值分配到const int 中去
	int i = 1, j = 2;
	for (i, j; i < 10, j < 10; i++, j++)
	{
		sum += func1(i, j);
	}
	return *point1;
}
int main()
{
	int ret = sum();
	cout << ret;
	return 0;
}
//*/

/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现偶数次。找出那个只出现了一次的元素。*/
/*
int main()
{
	int n;
	cin >> n;

	vector<int>res;
	int i, c;
	int t=0;
	for (i = 0; i < n; i++)
	{
		cin >> c;
		res.push_back(c);
		t ^= c;
	}
	cout << t << endl;
}
//*/

/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现偶数次。找出那个只出现了一次的元素。*/
/*
int singleNumber(vector<int>& nums) {
	int a = 0, b = 0;
	for (auto x : nums) {
		b = (b ^ x) & ~a;
		a = (a ^ x) & ~b;
	}
	return b;
}

//用map存下所有数字的出现次数，然后找出出现次数为1的数，时间复杂度O(N),空间复杂度O(N)//
int main()
{
	int n;
	cin >> n;
	map<int,int>res;
	map<int, int>::iterator it;
	int i, c;
	int t = 0;
	for (i = 0; i < n; i++)
	{
		cin >> c;
		if (res.find(c) != res.end())
		{
			res[c] = 3;
		}
		else
		{
			res[c] = 1;
		}
	}
	for (it = res.begin(); it != res.end(); it++)
	{
//		cout << (*it).first << "->" << (*it).second << endl;
		if ((*it).second == 1)
		{
			cout << (*it).first << endl;
		}
	}
}
//*/

/*找出数组中只出现1次的两个数*/
/*
vector<int> FindTwoOnce(vector<int> num) {
	if (num.size() <= 2)               //对符合要求的num数组，只有两个元素则直接返回
		return num;
	int res = 0;                      //存储数组所有元素异或的结果
	for (int i = 0; i<num.size(); i++) {
		res ^= num[i];
	}
	int index = 0;                    //存储异或结果二进制表示中，从右往左第一个为1的下标
	for (int i = 0; i<32; i++) {
		int temp = res;
		if ((temp >> i) & 1 == 1) {     //第i位为1
			index = i;
			break;
		}
	}
	vector<int> result;             //存储问题结果的数组
	result.push_back(0);
	result.push_back(0);
	for (int i = 0; i<num.size(); i++) {
		if ((num[i] >> index) & 1 == 1)//第i位是1的一类
			result[0] ^= num[i];
		else                        //第i位是0的一类
			result[1] ^= num[i];
	}
	return result;
}

int main() {
	vector<int> num;
	num.push_back(2);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	num.push_back(5);
	vector<int> result = FindTwoOnce(num);
	cout << result[0] << ' ' << result[1] << endl;
	return 0;
}
*/

/*手写sqrt*/
/*
double mySqrt(int x) {
	double mid = (double)x / 2;
	double right = x;
	double left = 0;
	while ((int)left<(int)right)
	{
		if (mid*mid > x)
		{
			right = mid;
			mid = (double)(right + left) / 2;
		}
		else
		{
			left = mid;
			mid = (double)(right + left) / 2;
		}
	}
	return mid;
}
int main()
{
	double res;
	int x = 8;
	res=mySqrt(x);
	cout << res << endl;
}
*/

/* string转int */
/*
int myAtoi(string str) {
	if (isalpha(str[0])) return 0;
	long long  ans = 0;
	int flag = 0;// 出现 '-' 置1 
	int len = 0;//记录数字的长度   
	int temp = 0;//记录 "+-" 出现的次数 
	for (char c : str) {
		//判断 正负号   且数字长度为0  防止 "0-1" 这样的情况 
		if ((c == '+' || c == '-') && len == 0) {
			temp++;			//记录符号出现次数 
			flag = (c == '-') ? 1 : 0;
		}
		else if (0 <= (c - '0') && (c - '0') <= 9 && temp<2) { 		//temp<2 表示 正负号 只出现过一次 
			ans = ans * 10 + (c - '0');
			len++;
			// INT_MAX=2147483647 	INT_MIN=-2147483648   
			if (ans - 1>INT_MAX) break;		// 如果 数字的绝对值 大于 INT_MAX +1 那么直接跳出 一定溢出 
		}
		else if (c == ' ' && len == 0 && temp == 0)		//如果是空格则继续 但前提是 之前没有出现过 正负号 和 数字 
			continue;
		else		//其他情况：英文和其他字符 
			break;
	}
	if (flag == 1)			//flag==1 表示数字为负 
		return -ans<INT_MIN ? INT_MIN : -ans;
	return ans>INT_MAX ? INT_MAX : ans;
}

int main()
{
	string str;
	cin >> str;
	int a;
	a = myAtoi(str);
	cout << a << endl;
}

//*/

/*连续最大子序列的和*/
/*
int maxSubArray(vector<int>& sum) 
{
	if (sum.size() == 0) return NULL;
	int res = INT_MIN;
	int f_n = -1;
	for (int i = 0; i < sum.size(); i++) 
	{
		f_n = max(sum[i], f_n + sum[i]);
		res = max(f_n, res);
	}
	return res;
}

int main()
{
	vector<int>res;
	int n;
	int i,c;
	cin >> n;
	for(i=0;i<n;i++)
	{ 
		cin >> c;
		res.push_back(c);
	}
	int sum = maxSubArray(res);
	cout << sum << endl;
}
*/

/*数字转罗马and罗马转数字*/
/*
string intToRoman(int num)
{
	if (num <= 0) return "";
	string ret = "";
	static int number[13] = { 1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1 };
	static string flags[13] = { "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	for (int i = 0; i < 13 && num > 0; i++) {
		if (num < number[i]) continue;
		// cout<< i << " " << number[i] << " - " <<flags[i] << endl;
		while (num >= number[i]) {
			num -= number[i];
			ret += flags[i];
		}

	}
	return ret;
}
//罗马转数字
int romanToInt(string s) {
	int tagVal[256];
	tagVal['I'] = 1;
	tagVal['V'] = 5;
	tagVal['X'] = 10;
	tagVal['C'] = 100;
	tagVal['M'] = 1000;
	tagVal['L'] = 50;
	tagVal['D'] = 500;
	int val = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i + 1 >= s.length() || tagVal[s[i + 1]] <= tagVal[s[i]])
			val += tagVal[s[i]];
		else
			val -= tagVal[s[i]];
	}
	return val;
}

int main()
{
	string str;
	int n;
	cin >> str;
	str=intToRoman(n);
	n = romanToInt(str);
	cout << n << endl;
}
//*/

/*控制数组输入的问题[1,2,3,4]*/
/*
int max(vector<int>& sum)
{
	if (sum.size() == 0) return NULL;
	int res = -1;
	int f_n = -1;
	for (int i = 0; i < sum.size(); i++)
	{
		f_n = max(sum[i], f_n + sum[i]);
		res = max(f_n, res);
	}
	return res;
}

int main()
{
	vector<int>res;
	int c;
	char ch;
	cin >> ch;
	while(scanf_s("%d", &c))
	{
		cin >> ch;
		res.push_back(c);
		if (ch == ']')
			break;
	}
	int sum = max(res);
	cout << sum << endl;
}
//*/

/*判断字符串a和b是否为同类*/
/*
bool panduan(string s, string t) {
	if (s.size() != t.size())
		return false;
	int snum[128], tnum[128];
	for (int i = 0; i < 128; ++i) {
		snum[i] = 0;
		tnum[i] = 0;
	}
	int index[128];
	for (int i = 0; i < s.length(); ++i) {
		if (snum[s[i]] != tnum[t[i]])
			return false;
		if (snum[s[i]] == 0)
			index[s[i]] = t[i];
		++snum[s[i]];
		++tnum[t[i]];
		if (snum[s[i]] != tnum[index[s[i]]])
			return false;
	}
	return true;
}
int main()
{
	string str, str1, str2;
	cin >> str;
	int i=0;
	while (str[i] != ';')
	{
		str1 += str[i];
		i++;
	}
	i++;
	while (i < str.size())
	{
		str2 += str[i];
		i++;
	}
	if (panduan(str1, str2))
	{
		cout << "True" << endl;
		return 0;
	}
	else
	{
		cout << "False" << endl;
		return 0;
	}

}
*/

/*单例模式*/
/*
class Single
{
public:
	static Single* getInstance()
	{
		return personhungry;
	}
private:
	Single() {}
	static Single* personhungry;
};
Single*Single::personhungry = new Single;

*/

/*map,set用法*/
/*
int main()
{
	multiset<int> str;
	str.insert(multiset<int>::value_type(1));
	str.insert(multiset<int>::value_type(1));
	str.insert(multiset<int>::value_type(1));
	multiset<int>::iterator it;
	for (it = str.begin(); it != str.end(); *it++)
	{
		cout << *it<< endl;
	}
	if (str.count(1))
	{
		cout << str.count(1) << endl;
	}
}
//*/

/*strcpy用法*/
/*
int main(void)
{
    char *src = "hel";
	char aa[] = { 'h','e','l','l','o','\0' };
	char dest[50] = {'a','e','e','i','o','o'};
	char *ss = "liang xiao";
    char *p = NULL;
    strcpy_s(dest, src);
    printf("src:%s \ndest:%s\n", src, dest);
    return 0;
}
//*/
//memcpy.c的三种用法
/*
int main()
{
    char* s = "GoldenGlobalView";
    char d[20];
	memcpy(d, s, (strlen(s) + 1));        //+1 是为了将字符串后面的'\0'字符结尾符放进来，去掉+1可能出现乱码
    printf("%s", d);
    getchar();
    return 0;
}
//*/
/*
int main()
{
	char* s = "GoldenGlobalView";
    char d[20];
    memcpy(d, s + 12, 4);//从第13个字符(V)开始复制，连续复制4个字符(View)
    d[4] = '\0';//memcpy(d,s+12*sizeof(char),4*sizeof(char));也可
    printf("%s", d);
    getchar();
    return 0;
}
//*/
/*
int main()
{
    char *src = "*********************************";
    char dest[] = "abcdefghijlkmnopqrstuvwxyz0123as6";
    printf("destination before memcpy:%s\n", dest);
    memcpy(dest, src, strlen(src));
    printf("destination after memcpy:%s\n", dest);
    return 0;
}
//*/

/*统计单词个数*/
/*
int main()
{
	int i, j = 0;
	string str, tmp[10000];
	getline(cin, str);
	for (i = 0; i<str.length(); i++)
	{
		if (str[i] != ' ')
		{
			tmp[j] += str[i];
		}
		if (str[i] == ' ')
		{
			j++;
		}
	}
	map<string, int> sum;
	for (i = 0; i <=j; i++)
	{
		
		if (sum.find(tmp[i])!=sum.end())
		{
			sum[tmp[i]]++;
		}
		else
		{
			sum.insert(map<string, int>::value_type(tmp[i], 1));
		}

	}
	//打印结果
	map<string, int>::iterator it;
	for (it = sum.begin(); it != sum.end(); ++it)
		cout << it->first << "=" << it->second << endl;
	cout << endl;
	return 0;
}
*/

/*
int main()
{
	int n,k,i;
	int a[10000];
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int tmp;
	while (k--)
	{
		i = 0;
		while (1)
		{
			if (a[i] > 0) 
			{
				cout << a[i] << endl;
				tmp = a[i];
				break;
			}
			else
				i++;
			if (a[n - 1] <= 0)
			{
				cout << 0 << endl;
				break;
			}
		}
		for (i = 0; i < n; i++)
		{
			a[i] -= tmp;
		}

	}
}
*/

/*
int main()
{
	int n, i, j, tmp;

	long long  a[90000], b[90000];
	int res[400000];
	int k = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			tmp = a[i] + b[j];
			res[k++]=tmp;
		}
	}
	long long length = k;
	int ss = res[0];
	for (i = 1; i < length; i++)
	{
		ss ^= res[i];
	}
	cout << ss << endl;
}
//*/

/*
bool panduan(string str, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] != '8')
		{
			count++;
		}
		else
			break;
	}
	if (length - count >= 11)
		return true;
	else
		return false;
}
int main()
{
	int t,i;
	int a[101];
	string str[100];
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> a[i];
		cin >> str[i];
	}
	i = 0;
	while (i!=t)
	{
		if (a[i] < 11)
		{
			cout << "NO" << endl;
			i++;
			continue;
		}
		else
		{
			if (panduan(str[i], a[i]))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		i++;
	}
}
*/

/*快速排序*/
/*
int Partition(int a[], int left, int right)
{
	int temp = a[left];
	while (right>left)
	{
		while (left<right && a[right]>temp)
		{
			right--;
		}
		a[left] = a[right];
		while (left<right && a[left]<temp)
		{
			left++;
		}

		a[right] = a[left];
	}
	a[right] = temp;
	return left;
}
void quickSort(int a[], int left, int right)
{
	if (left<right)
	{
		int pos = Partition(a, left, right);
		quickSort(a, left, pos - 1);
		quickSort(a, pos + 1, right);
	}
}
int main()
{
	int a[8] = { 1,8,4,5,7,3,18,6 };
	int len = sizeof(a) / sizeof(a[0]);
	int left = 0;
	int right = len - 1;
	quickSort(a, left, right);
	for (int i = 0; i<len; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
//*/

/*归并排序*/
/**
* 合并的方法
*
* @param arr   待排序的数组
* @param left  左边有序序列的初始索引
* @param right 中间索引
* @param mid   右边有序序列的初始索引
* @param temp  做中转的数组

void merge1(int arr[], int left, int right, int mid, int temp[]) {
	int i = left; // 初始化i，左边有序序列的初始索引
	int j = mid + 1;// 初始化j，右边有序序列的初始索引(右边有序序列的初始位置即为中间位置的后一个位置)
	int t = 0;// 指向temp数组的当前索引，初始为0
			  // 先把左右两边的数据(已经有序)按规则填充到temp数组
			  // 直到左右两边的有序序列，有一边处理完成为止
	while (i <= mid && j <= right) {
		// 如果左边有序序列的当前元素小于或等于右边有序序列的当前元素，就将左边的元素填充到temp数组中
		if (arr[i] <= arr[j]) {
			temp[t] = arr[i];
			t++;// 索引后移
			i++;// i后移
		}
		else {
			// 反之，将右边有序序列的当前元素填充到temp数组中
			temp[t] = arr[j];
			t++;// 索引后移
			j++;// j后移
		}
	}
	// 把有剩余数据的一边的元素填充到temp中
	while (i <= mid) {
		// 此时说明左边序列还有剩余元素
		// 全部填充到temp数组
		temp[t] = arr[i];
		t++;
		i++;
	}
	while (j <= right) {
		// 此时说明左边序列还有剩余元素
		// 全部填充到temp数组
		temp[t] = arr[j];
		t++;
		j++;
	}
	// 将temp数组的元素复制到原数组
	t = 0;
	int tempLeft = left;
	while (tempLeft <= right) {
		arr[tempLeft] = temp[t];
		t++;
		tempLeft++;
	}
}
void mergeSort(int arr[], int left, int right, int temp[]) {
	// 分解
	if (left < right) {
		int mid = (left + right) / 2;// 中间索引
									 // 向左递归进行分解
		mergeSort(arr, left, mid, temp);
		// 向右递归进行分解
		mergeSort(arr, mid + 1, right, temp);// mid + 1，中间位置的后一个位置才是右边序列的开始位置
											 // 每分解一轮便合并一轮
		merge1(arr, left, right, mid, temp);
	}
}
int main() 
{
	int arr[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int temp[15];// = new int[arr.length];
	mergeSort(arr, 0, 15 - 1, temp);
	for (int i = 0; i < 15; i++)
	{
		cout << arr[i] << " ";
	}
}
*/
/*主函数*/
/*
int main()
{
	int n, m,ss;
	map<int ,int>a;
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> ss;
		if (a.find(ss) != a.end())
		{
			a[ss]++;
		}
		else
		{
			a.insert(map<int, int>::value_type(ss, 1));
		}
	}
	map<int, int>::iterator it;
	vector<int>res1, res2;
	for (it = a.begin(); it != a.end(); ++it)
	{
		res1.push_back(it->first);
		res2.push_back(it->second);
	}
	while (m--)
	{
		int ss;
		cin >> ss;
		for (i = 0; i < res1.size(); i++)
		{
			if (res1[i] == ss)
			{
				cout << res2[i] << endl;
				break;
			}
			if (i == res1.size() - 1)
			{
				cout << 0 << endl;
			}
		}
	}
}
//*/

/*网易笔试1*/
/*
int main()
{
	int T;
	int m, n;
	int a[10000];
	cin >> T;
	int i;
	while (T--)
	{
		cin >> n >> m;
		int sum = 0;
		int ss = 0;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
			ss += i;
		}
		sum += m;
		if (sum >= ss)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}
*/

/*网易笔试2*/
/*
int main()
{
	int T;
	int n;
	int a[100000];
	cin >> T;
	while (T--)
	{
		cin >> n;
		int i,j,count=0;
		int sum;
		int max=-1;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < n; i++)
		{
			count = 0;
			sum = 0;
			for (j = i; j < n; j++)
			{
				
				if (a[j] > sum)
				{
					count++;
					if (max < count)
					{
						max = count;
					}
					sum += a[j];
				}
				else
					break;
			}
		}
		cout << max << endl;
	}
}
*/

/*网易笔试3*/
/*
int main()
{
	int num;
	cin >> num;
	int a = num / 3;
	int b = num % 3;
	if (b != 0)
	{
		a++;
	}
	if (num == 2)
	{
		cout << 3 << endl;
		return 0;
	}
	if (num == 3)
	{
		cout << 4 << endl;
	}
	int res = 1;
	while (num > 4)
	{
		res *= 3;
		num -= 3;
	}
	res = res*num;
	res += a;
	cout << res << endl;
}
*/


/*智能指针*/
/*
#include <iostream>
#include <memory>
int main() {
	{
		int a = 10;
		std::shared_ptr<int> ptra = std::make_shared<int>(a);
		std::shared_ptr<int> ptra2(ptra); //copy
		std::cout << ptra.use_count() << std::endl;

		int b = 20;
		int *pb = &a;
		//std::shared_ptr<int> ptrb = pb;  //error
		std::shared_ptr<int> ptrb = std::make_shared<int>(b);
		ptra2 = ptrb; //assign
		pb = ptrb.get(); //获取原始指针

		std::cout << ptra.use_count() << std::endl;
		std::cout << ptrb.use_count() << std::endl;
	}
}
//*/

/*0-1背包问题*/
/*
#define V 500
#define N 20
int weight[N + 1];
int value[N + 1];

int main()
{
	int n,m;
	int dp[N+1][V+1];
	cin >> n;
	int i,j;
	for (i = 1; i <= n; i++)
	{
		cin >> weight[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin >> value[i];
	}
	cin >> m;
	for (i = 1; i <= n; i++)
	{
		for ( j = 1; j <= m; j++)
		{
			if (value[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - value[i]] + weight[i]);
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
//*/

/*
bool fun(int a[], int length)
{
	int i = 0, j = length - 1;//i指向前边子数组尾，j指向后边子数组的头。i,j初始时分别指向原数组首尾
	int h = a[i], r = a[j];
	while (i <= j) 
	{
		//若前边的和等于后边，还应判断前后子数组是否间隔一个元素
		if (h == r) {
			//h=r时，若间隔一个元素，即i+2==j,则分割成功
			if ((i+2) == j || i==j) 
			{
				return true; 
			}

			//h=r时，若间隔两个元素以上或没有间隔，i后移，j前移  （注意：没有间隔时下次跳出while循环）
			else {
				i++;
				j--;
			}
		}
		//前边的和小，则i后移
		else if (h < r)
		{
			h += a[i];
			i++;
		}
		//后边的和小，则j前移
		else
		{
			r += a[j];
			j--;
		}
	}

	//若跳出while循环，说明没有找到分界点，返回false
	return false;
}

int main()
{
	int a[] = { 1,2,2,1,3,1};
	int length = sizeof(a) / sizeof(int);
	if (fun(a, length))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

*/

