/*#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		int start = -90;
		int last = 90;
		int mid = (start + last) / 2;
		bool jixu = true;
		while (jixu)
		{
			if (n >= mid)
			{
				start = mid;
				mid = (start + last) / 2;
				s.push_back('1');
				if (last - start + 1 >= 6)
					jixu = true;
				else
					jixu = false;
			}
			else
			{
				last = mid;
				mid = (start + last) / 2;
				s.push_back('0');
				if (last - start >= 6)//���ǵ���⣬�������ǲ�������[45,50)����5���������Ǵ𰸲���ô�룬����Ϊ��6����
					jixu = true;
				else
					jixu = false;
			}
		}
		cout << s << endl;
	}
	return 0;
}*/
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		int start = -90;
		int last = 90;
		int mid = (start + last) / 2;
		while (last - start + 1 >= 6)//��Ҫ�������
		{
			if (n >= mid)
			{
				start = mid;
				mid = (start + last) / 2;
				s.push_back('1');
			}
			else
			{
				last = mid;
				mid = (start + last) / 2;
				s.push_back('0');
			}
		}
		cout << s << endl;
	}
	return 0;
}