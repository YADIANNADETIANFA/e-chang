/*画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。
小Q有他独特的绘画技巧,每次小Q会选择一条斜线, 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的一段格子,都涂画为蓝色,用'B'表示;如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用'G'表示。
小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。*/
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
