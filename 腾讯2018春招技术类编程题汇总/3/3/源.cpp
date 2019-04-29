#include<iostream>
#include<cstdio>
using namespace std;

int need_max(int s,int n)//��һ���s�飬��������Ҫ���ٿ�Ź���
{
	int Sum = s;
	for (int i = 1; i < n; ++i)
	{
		Sum += (s+1) >> 1;//����ȡ��
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
			int Mid = (Low + High+1) >> 1;//���ô�ʩ��������ַ�����ѭ�������⡣�����׳���Low����Highһֱ�������ѭ������//�����ּ�����ôд�ɡ���2��������������������������
			int need_res = need_max(Mid, n);
			if (need_res == m)
			{
				cout << Mid << endl;
				break;
			}
			else if (need_res < m)
			{
				Low = Mid;//���ô�ʩ��������ַ�����ѭ��������
			}
			else
			{
				High = Mid-1;//���ô�ʩ��������ַ�����ѭ��������
			}
		}

	}
	return 0;
}