#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> parent;
vector<int>travel;
bool res = true;

int GetParent(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = GetParent(parent[x]);
	}

}

void Union(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);
	if (a > b)
	{
		parent[a] = b;
	}
	else
	{
		parent[b] = a;
	}
}

void Find(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);
	if (a != b)
	{
		res = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	parent = vector<int>(201, 0);
	travel = vector<int>(1001, 0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	int num;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> num;
			if (num == 1)
			{
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> travel[i];
	}
	for (int i = 0; i < M - 1; i++)
	{
		Find(travel[i], travel[i + 1]);
	}
	if (res == true)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}