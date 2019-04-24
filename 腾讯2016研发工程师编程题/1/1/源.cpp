//����һ���ݹ�
//�ݹ��˼·����nλgray������n-1λgray�����ɣ��ٸ����Ӽ�һЩ��
//������n=3��gray�룬����֪��n=2��gray����(00,01,11,10)
//��ôn=3��gray����ʵ���Ƕ�n=2��gray����λ���0��1���ɵģ����0����(000,001,011,010)
//���1����Ҫ˳����ͱ��(110,111,101,100)
//�����һ�����(000,001,011,010,110,111,101,100)

//������ĵݹ����ɣ���Ҫ����׼�ԳƵ����ʣ�nλ������������У����n-1λ�����ǶԳƵģ����ֻ����˳��������������graycode(n-1)�Ľ�����ɡ�
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class GrayCode {
public:
	vector<string> getGray(int n)//���ã������ǳ�Ա������������������
	{
		// write code here
		vector<string> res;
		if (n == 1) {
			res.push_back("0");//˫����
			res.push_back("1");
			return res;
		}
		vector<string> v = getGray(n - 1);
		int len = pow(2, n - 1);
		for (int i = 0; i < len; i++) {
			res.push_back("0" + v[i]);//�ַ���string�����Ӵ���
		}
		for (int i = len - 1; i >= 0; i--) {
			res.push_back("1" + v[i]);
		}
		return res;
	}
};

int main()//ţ������ʽ����main��ֻ�ύclass��������ݾͿ��ԣ����������Լ�������Ҫ�Լ�дmain
{
	int n;
	while (cin >> n)
	{
		GrayCode A;
		vector<string> result;
		result = A.getGray(n);
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
	}
	return 0;
}