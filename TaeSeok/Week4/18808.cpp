#include <iostream>
#include <vector>
using namespace std;

int N, M, K, sum;

vector<vector<int>> RotateSticker(vector<vector<int>>& sticker)
{
	int srcRow = sticker.size();
	int srcCol = sticker[0].size();

	vector<vector<int>> result(srcCol, vector<int>(srcRow, 0));

	for (int i = 0; i < srcRow; i++)
	{
		for (int j = 0; j < srcCol; j++)
		{
			result[j][srcRow - i - 1] = sticker[i][j];
		}
	}
	return result;
}

bool canPlaceSticker(vector<vector<int>>& notebook, vector<vector<int>>& sticker, int startRow, int startCol)
{

	int R = sticker.size();
	int C = sticker[0].size();

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (sticker[y][x] == 1)
			{
				int nr = startRow + y;
				int nc = startCol + x;

				if (nr >= N || nc >= M || notebook[nr][nc] == 1)
					return false;
			}
		}
	}
	return true;
}

void placeSticker(vector<vector<int>>& notebook, vector<vector<int>>& sticker, int startRow, int startCol)
{
	int R = sticker.size();
	int C = sticker[0].size();

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (sticker[y][x] == 1)
			{
				notebook[startRow + y][startCol + x] = 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	vector<vector<int>> notebook(N, vector<int>(M, 0));

	for (int i = 0; i < K; i++)
	{
		int R, C;
		cin >> R >> C;

		vector<vector<int>> sticker(R, vector<int>(C, 0));

		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				cin >> sticker[y][x];
			}
		}


		bool placed = false;

		for (int t = 0; t < 4; t++)
		{
			for (int r = 0; r <= N - R; r++)
			{
				for (int c = 0; c <= M - C; c++)
				{
					if (canPlaceSticker(notebook, sticker, r, c))
					{
						placeSticker(notebook, sticker, r, c);
						placed = true;
						break;
					}
				}
				if (placed) break;
			}
			if (placed) break;

			sticker = RotateSticker(sticker);

			R = sticker.size();
			C = sticker[0].size();
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (notebook[i][j] == 1)
				sum++;

	cout << sum;

	return 0;
}
