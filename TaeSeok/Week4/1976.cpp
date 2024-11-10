#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int adj[201][201];
int N, M;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) 
			cin >> adj[i][j];

	vector<int> travel(M, 0);

	for (int i = 0; i < M; i++)
		cin >> travel[i];

	vector<int> visited(M + 1, 0);
	
	int startCity = travel[0];

	queue<int> q;
	q.push(startCity);
	visited[startCity] = 1;

	while (!q.empty())
	{
		int curCity = q.front(); q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0 && (adj[i][curCity] || adj[curCity][i]))
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (travel[i] && visited[travel[i]] == 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}