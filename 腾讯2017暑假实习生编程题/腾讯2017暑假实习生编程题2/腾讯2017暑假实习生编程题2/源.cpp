#include<iostream>
#include<string>
using namespace std;

void Swap(string& s, int i, int j)//这里也一样同下！！！！！
{
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
/*void Swap(char& str1, char& str2)
{
	char temp = str1;
	str1 = str2;
	str2 = temp;
}*/
void GetBack(string& s)//!!!!!!数组是传递的指针，但是没人说容器传递的是指针！！！！！！！不用引用则永远都是AkleBiCeilD！！！！1
{
	int length = s.size();
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - 1 - i; ++j)
		{
			if (s[j] >= 'A' && s[j] <= 'Z' && s[j + 1] >= 'a')
				//Swap(s[j], s[j + 1]);
				Swap(s,j,j+1);
		}
	}
}

int main()
{
	string s;
	while (cin >> s)
	{
		GetBack(s);
		cout << s << endl;
	}

	return 0;
}