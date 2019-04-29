/*假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下：
a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 
其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int base[4];
	base[3] = 1;
	base[2] = base[3]*25+1;
	base[1] = base[2]*25+1;
	base[0] = base[1] * 25 + 1;
	while (cin >> s)
	{
		int len = s.size();//别用strlen，用容器该用的东西
		unsigned int index = 0;
		for (int i = 0; i < len; ++i)
		{
			index += (s[i] - 'a')*base[i]+1;
		}
		cout << index - 1 << endl;
	}
	return 0;
}
