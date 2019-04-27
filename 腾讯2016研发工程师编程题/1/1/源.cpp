//在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同， 则称这种编码为格雷码(Gray Code)，请编写一个函数，使用递归的方法生成N位的格雷码。
//给定一个整数n，请返回n位的格雷码，顺序为从0开始。
//测试样例：
//1
//返回：["0","1"]
//方法一：递归
//递归的思路就是n位gray码是由n-1位gray码生成，举个例子简单一些：
//比如求n=3的gray码，首先知道n=2的gray码是(00,01,11,10)
//那么n=3的gray码其实就是对n=2的gray码首位添加0或1生成的，添加0后变成(000,001,011,010)
//添加1后需要顺序反向就变成(110,111,101,100)
//组合在一起就是(000,001,011,010,110,111,101,100)

//格雷码的递归生成，主要是找准对称的性质，n位格雷码的排列中，其低n-1位排列是对称的，因此只需先顺序输出再逆序输出graycode(n-1)的结果即可。
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class GrayCode {
public:
	vector<string> getGray(int n)//看好，这里是成员函数，不是容器定义
	{
		// write code here
		vector<string> res;
		if (n == 1) {
			res.push_back("0");//双引号
			res.push_back("1");
			return res;
		}
		vector<string> v = getGray(n - 1);
		int len = pow(2, n - 1);
		for (int i = 0; i < len; i++) {
			res.push_back("0" + v[i]);//字符串string的连接处理
		}
		for (int i = len - 1; i >= 0; i--) {
			res.push_back("1" + v[i]);
		}
		return res;
	}
};

int main()//牛客网隐式给了main，只提交class里面的内容就可以，但是我们自己测试需要自己写main
{
	int n;
	while (cin >> n)
	{
		GrayCode A;
		vector<string> result;
		result = A.getGray(n);
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}
