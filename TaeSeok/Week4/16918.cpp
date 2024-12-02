#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int R, C, N;

char grid[201][201];

int main()
{
	cin >> R >> C >> N;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> grid[i][j];

	if (N == 1)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cout << grid[i][j];
			cout << '\n';
		}
		return 0;
	}
	else if (N % 2 == 0)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				cout << 'O';
			cout << '\n';
		}
		return 0;
	}

	int curTime = 1;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	while (curTime < N)
	{
		queue<pair<int, int>> bombs;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (grid[i][j] == 'O')
				{
					bombs.push({ i, j });
				}
			}
		}

		memset(grid, 'O', sizeof(grid));

		while (!bombs.empty())
		{
			auto cur = bombs.front(); bombs.pop();

			grid[cur.first][cur.second] = '.';
			for (int i = 0; i < 4; i++)
			{
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
				grid[ny][nx] = '.';
			}
		}
		curTime += 2;
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << grid[i][j];
		cout << '\n';
	}


	return 0;
}