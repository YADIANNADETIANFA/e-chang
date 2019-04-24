//剑指offer，没啥说的
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

class Gift
{
public:
	int getValue(vector<int> gifts, int n)
	{
		sort(gifts.begin(), gifts.end(), less<int>());
		int mid = n / 2;
		int value = gifts[mid];
		int num = 1;
		for (int i = mid+1; i < n; ++i)
		{
			if (gifts[i] != value)
				break;
			num++;
		}
		for (int i = mid - 1; i >= 0; --i)
		{
			if (gifts[i] != value)
				break;
			num++;
		}
		if (num > n / 2)
			return gifts[mid];
		else
			return 0;
	}
};