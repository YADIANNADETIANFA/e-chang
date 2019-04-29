#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	long long int n = 0;//数大就用long long
	long long int m = 0;
	while (cin >> n >> m)
	{
		long int res = 0.5*m*n;
		cout << res << endl;
	}
	return 0;
}