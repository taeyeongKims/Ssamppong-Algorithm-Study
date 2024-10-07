#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;
vector<vector<int>> info;
const int MOD = 1'000'000'007;
using int64 = long long int;

int64 Fact(int inNum)
{
	int64 R = 1;
	for (int i = 1; i <= inNum; i++)
	{
		R = (R * i) % MOD;
	}

	return R % MOD;
}

int main()
{
	cin >> N >> M >> D;
	info = vector<vector<int>>(N, vector<int>(M, -1));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> info[i][j];
			info[i][j] += D * (i + 1);
		}

		sort(info[i].begin(), info[i].end());
	}

	int64 rst = Fact(M);

	for (int row = 1; row < N; ++row)
	{
		int64 poss = 1;

		for (int col = 0; col < M; ++col)
		{
			int cnt = ::count_if(info[row - 1].begin(), info[row - 1].end(), [&](int other) { return info[row][col] > other; });

			poss = (poss * (cnt - col)) % MOD;
		}

		if (poss <= 0)
		{
			rst = 0;
			break;
		}

		rst = (rst * poss) % MOD;
	}

	cout << rst;

	return 0;
}
