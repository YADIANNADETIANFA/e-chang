#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;
int MaxLen[MAX][MAX];
int maxLen(string s1, string s2)
{
	for (int i = 0; i < MAX; ++i)//不能至于函数外面
		MaxLen[i][0] = 0;
	for (int i = 0; i < MAX; ++i)
		MaxLen[0][i] = 0;
	int length1 = s1.size();
	int length2 = s2.size();

	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (s1[i-1] == s2[j-1])
				MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;////解题思路：设输入的两个串为s1,s2，设MaxLen(i,j)表示：s1的左边i个字符形成的子串，与s2左边的j个字符形成的子串的最长公共子序列的长度(i,j从0开始算），则MaxLen(i,j) 就是本题的“状态” 
			else
				MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
		}
	}

	return MaxLen[length1][length2];
}

int main()
{
	string s;
	while (cin >> s)
	{
		if (s.size() == 1)
		{
			cout << 0 << endl;
			return 0;
		}
		string s2=s;
		reverse(s2.begin(), s2.end());//学会reverse
		int maxNum = maxLen(s, s2);
		cout << s.size()-maxNum << endl;
		
	}
	return 0;
}
