#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		vector<vector<int>> A(N, vector<int>(M, 0));//正常数组无法使用非常量初始大小，这个很美妙
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				char c;
				cin >> c;
				if (c == 'X')
					A[i][j] = 0;
				else if (c == 'B')
					A[i][j] = 1;
				else if (c == 'Y')
					A[i][j] = 2;
				else
					A[i][j] = 3;
			}
		}

		int step = 0;
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (A[i][j] == 2 || A[i][j] == 3)
				{
					int m = i;
					int n = j;
					while (m <= N-1 && n <= M-1 && A[m][n] != 0 && A[m][n] != 1)//光是附加A[m][n] != 0是不够的！！因为下面解释
					{
						if (A[m][n] == 2)
						{
							A[m][n] = 0;
						}
						if (A[m][n] == 3)
						{
							A[m][n] = 1;
						}
						++m;
						++n;
					}
					step++;
				}
				if (A[i][j] == 1)
				{
					int m = i;
					int n = j;
					while (m <= N-1 && n >= 0 && A[m][n] != 0 && A[m][n] !=2)//同上
					{
						if (A[m][n] == 1)
						{
							A[m][n] = 0;
						}
						if (A[m][n] == 3)
						{
							A[m][n] = 2;
						}
						++m;
						--n;
					}
					step++;
				}
				
			}
		}
		cout << step << endl;
	}
	return 0;
}

//Y
// Y
//  X
//   Y
//    Y需要两笔才能画出来

//同样！！！很难发现这个
//Y
// Y
//  B
//   Y
//    Y需要两笔才能画出来