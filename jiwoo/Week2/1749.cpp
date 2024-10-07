#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int N, M;
vector<vector<int>> matrix;

int main()
{
	cin >> N >> M;
	matrix = vector<vector<int>>(N, vector<int>(M));
	int rst = -999'999'999;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for (int srcRow = 0; srcRow < N; srcRow++)
	{
		vector<int> colSum = vector<int>(M, 0);

		for (int endRow = srcRow; endRow < N; endRow++)
		{
			for (int i = 0; i < M; i++)
			{
				colSum[i] += matrix[endRow][i];
			}

			vector<int> sumed = vector<int>(M, 0);
			sumed[0] = colSum[0];
			for (int i = 1; i < M; i++)
			{
				sumed[i] = max(colSum[i], sumed[i - 1] + colSum[i]);
			}

			rst = max(rst, *::max_element(sumed.begin(), sumed.end()));
		}
	}

	cout << rst;


	return 0;
}
