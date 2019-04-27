//春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
//给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
//若没有金额超过总数的一半，返回0。
//测试样例：
//[1,2,3,2,2],5
//返回：2
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
