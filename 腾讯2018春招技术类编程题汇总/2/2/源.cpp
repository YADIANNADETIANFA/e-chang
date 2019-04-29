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