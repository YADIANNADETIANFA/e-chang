//给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
//如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)）
//自己写质数判断函数即可
#include<cstdio>
#include<iostream>
using namespace std;

bool isPrime(int num)
{
	for (int i = 2; i <= num / 2; ++i)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int res = 0;
		for (int i = 2; i <= n / 2; ++i)
		{
			if (isPrime(i) && isPrime(n - i))
				res++;
		}
		cout << res << endl;
	}
	return 0;
}
