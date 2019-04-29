//小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，现在小Q想用这些歌组成一个总长度正好为K的歌单，每首歌最多只能在歌单中出现一次，
//在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。
/*#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


int main()
{
	int k;//歌单总长度
	while (cin >> k)
	{
		int A, x, B, y;//长为A有x首；长为B有y首
		cin >> A >> x >> B >> y;

		vector<unsigned long long> res;

		for (int select_x = 0; select_x <= x; ++select_x)
		{
			for (int select_y = 0; select_y <= y; ++select_y)
			{
				if (select_x*A + select_y * B == k)
				{
					unsigned long long one_res = 0;//unsigned long long都他么超界了,要使用数字转字符串么。。。
					unsigned long long res_A_up = 1;
					unsigned long long res_A_down = 1;
					for (int i = x; i > x - select_x; i--)
					{
						res_A_up *= i;
						res_A_up = res_A_up ;
					}
					for (int i = select_x; i > 1; i--)
					{
						res_A_down *= i;
						res_A_down = res_A_down ;
					}
					unsigned long long res_B_up = 1;
					unsigned long long res_B_down = 1;
					for (int i = y; i > y - select_y; i--)
					{
						res_B_up *= i;
						res_B_up = res_B_up ;
					}
					for (int i = select_y; i > 1; i--)
					{
						res_B_down *= i;
						res_B_down = res_B_down ;
					}
					if (res_A_down == 0)
						res_A_down = 1;
					if (res_B_down == 0)
						res_B_down == 1;
					one_res = res_A_up * res_B_up / res_A_down / res_B_down % 1000000007;
					res.push_back(one_res);
				}
			}
		}
		int result = 0;
		for (int j = 0; j < res.size(); ++j)
		{
			result += res[j];
		}
		cout << result << endl;
	}
	return 0;
}*/
#include<cstdio>//学习C组合的解法：利用数学归纳法：由C(n, k) = C(n - 1, k) + C(n - 1, k - 1）；
#include<iostream>        
using namespace std;

long long c[105][105];
const int mod = 1000000007;
void init()
{
	c[0][0] = 1;  
	for (int i = 1; i <= 100; i++)
	{ 
		c[i][0] = 1;   
	    for (int j = 1; j <= 100; j++)
	    {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	    }
	}
}

int main()
{
	int k, i, j, x, y, a, b;  
	long long sum;  
	init(); 
	while (cin >> k >> a >> x >> b >> y)
	{ sum = 0;        
	if (a != b)
	{ 
		for (i = 0; i <= x; i++)
		{ 
			for (j = 0; j <= y; j++) 
			{
				if ((i*a + j * b) > k)    
					break;                
				if ((i*a + j * b) == k) 
				{
					sum += c[x][i] * c[y][j]; 
				}
			}
		}
	}
	printf("%ld\n", sum % 1000000007); 
	}
	return 0;
}
