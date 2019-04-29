#include<iostream>
#include<cstdio>
using namespace std;

int need_max(int s,int n)//第一天吃s块，最起码需要多少块才够用
{
	int Sum = s;
	for (int i = 1; i < n; ++i)
	{
		Sum += (s+1) >> 1;//向上取整
		s = (s+1) >> 1;
	}
	return Sum;
}

int main()
{
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		if (n == 1)
		{
			cout << m << endl;
			continue;
		}
		int Low = 1;
		int High = m;

		while (Low <= High)
		{
			if (Low == High)
			{
				cout << Low << endl;
				break;
			}
			int Mid = (Low + High+1) >> 1;//做好措施，避免二分法的死循环的问题。很容易出现Low或者High一直不变的死循环！！//而且手贱总他么写成》》2！！！！！！！！！！！！！
			int need_res = need_max(Mid, n);
			if (need_res == m)
			{
				cout << Mid << endl;
				break;
			}
			else if (need_res < m)
			{
				Low = Mid;//做好措施，避免二分法的死循环的问题
			}
			else
			{
				High = Mid-1;//做好措施，避免二分法的死循环的问题
			}
		}

	}
	return 0;
}