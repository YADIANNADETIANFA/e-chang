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