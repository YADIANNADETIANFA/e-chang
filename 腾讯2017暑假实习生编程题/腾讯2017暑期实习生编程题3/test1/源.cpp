//小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Num;
void GetNum(int n)
{
	Num.clear();//如果不清空，下一次会接着之前的输入
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		Num.push_back(temp);
	}
	sort(Num.begin(), Num.end(), less<int>());
}

int NumOfSmallest(vector<int> Num)
{
	int num_of_smallest = 0;
	int min_value = Num[1]-Num[0];
	int difference_value = 0;
	for (int i = 2; i < Num.size(); ++i)
	{
		difference_value = Num[i] - Num[i - 1];
		if (difference_value < min_value)
			min_value = difference_value;
	}

	if (min_value == 0)
	{
		/*int i = 1;
		while (i < Num.size())
		{
			if (Num[i] == Num[i - 1])
			{
				int NumOfSame = 2;
				int Index = i + 1;
				while (Index < Num.size() && Num[Index] == Num[Index - 1])
				{
					++Index;
					++NumOfSame;
				}
				int NumOfSame_for_jiechengfenmu = NumOfSame - 2;
				int jiecheng1 = NumOfSame;
				while (NumOfSame != 1)
				{
					jiecheng1 *= (--NumOfSame);
				}
				int jiecheng2 = NumOfSame_for_jiechengfenmu;
				while (NumOfSame_for_jiechengfenmu != 1)
				{
					jiecheng2 *= (--NumOfSame_for_jiechengfenmu);
				}
				num_of_smallest += jiecheng1 / (2*jiecheng2);

				i = Index;
			}
			else
				++i;
		}*/
		for (int i = 1; i < Num.size(); ++i)//不要用阶乘，老是超时
		{
			int j = i - 1;
			while (j >= 0 && Num[i] == Num[j])
			{
				++num_of_smallest;
				--j;
			}
		}
	}
	else
	{
		for (int i = 1; i < Num.size(); ++i)
		{
			if (Num[i] - Num[i - 1] == min_value)
				++num_of_smallest;
		}
	}
	return num_of_smallest;
}

int NumOfBiggest(vector<int> Num)
{
	int num_of_biggest = 0;
	if (*(Num.end() - 1) == *(Num.begin()))
	{
		/*int len = Num.size();
		int len_forjiecheng = len - 2;
		int jiecheng1 = len;
		int jiecheng2 = len_forjiecheng;
		while (len != 1)
		{
			jiecheng1 *= (--len);
		}
		while (len_forjiecheng != 1)
		{
			jiecheng2 *= (--len_forjiecheng);
		}
		num_of_biggest = jiecheng1 / (2* jiecheng2);*/


		/*for (int i = 1; i < Num.size(); ++i)
		{
			int j = i - 1;
			while (j >= 0 && Num[i] == Num[j])
			{
				++num_of_biggest;
				--j;
			}
		}*/

		num_of_biggest = Num.size()*(Num.size() - 1) / 2;
	}
	else
	{
		/*int small_num = 1;
		int big_num = 1;
		int i = 1;
		int j = Num.size()-2;
		while (Num[i++] == Num[0])
		{
			small_num++;
		}
		while (Num[j--] == *(Num.end() - 1))
		{
			big_num++;
		}*/


		int a, b;
		a = b = 0;
		for (int i = 0; i < Num.size(); ++i)
		{
			if (Num[i] == Num[0])
				++a;
		}
		for (int i = Num.size() - 1; i >= 0; --i)
		{
			if (Num[i] == Num[Num.size() - 1])
				++b;
		}
		num_of_biggest = a * b;
	}
	return num_of_biggest;
}

int main()
{
	int n;
while (cin >> n)//这里是OJ多case连续的打印输出，所以要while循环
	{    //另外都写在class/main里面是有道理的，因为OJ
		if (n < 2) {
			cout << 0 << ' ' << 0 << endl;
			return 0;
		}
		if (n == 2) {
			cout << 1 << ' ' << 1 << endl;
			return 0;
		}
		GetNum(n);
		cout << NumOfSmallest(Num) << ' ' << NumOfBiggest(Num) << endl;
	}
	return 0;
}


