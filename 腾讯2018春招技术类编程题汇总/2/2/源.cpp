/*牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<long long int> cards;
		for (int i = 0; i < n; ++i)
		{
			long long int temp = 0;
			cin >> temp;
			cards.push_back(temp);
		}
		sort(cards.begin(), cards.end(), greater<long long int>());
		long long res = 0;
		if (n % 2 == 0)
		{
			for (int i = 0; i < n; i = i + 2)
			{
				res += (cards[i] - cards[i + 1]);
			}
		}
		else
		{
			for (int i = 0; i < n-1; i = i + 2)
			{
				res += (cards[i] - cards[i + 1]);
			}
			res += cards[n - 1];
		}
		cout << res << endl;
	}
	return 0;
}
