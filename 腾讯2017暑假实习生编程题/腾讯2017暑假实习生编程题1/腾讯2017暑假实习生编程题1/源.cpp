#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAX = 1001;
int MaxLen[MAX][MAX];
int maxLen(string s1, string s2)
{
	for (int i = 0; i < MAX; ++i)//�������ں�������
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
				MaxLen[i][j] = MaxLen[i - 1][j - 1] + 1;////����˼·���������������Ϊs1,s2����MaxLen(i,j)��ʾ��s1�����i���ַ��γɵ��Ӵ�����s2��ߵ�j���ַ��γɵ��Ӵ�������������еĳ���(i,j��0��ʼ�㣩����MaxLen(i,j) ���Ǳ���ġ�״̬�� 
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
		reverse(s2.begin(), s2.end());//ѧ��reverse
		int maxNum = maxLen(s, s2);
		cout << s.size()-maxNum << endl;
		
	}
	return 0;
}
