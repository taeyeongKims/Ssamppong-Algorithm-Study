#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;

int main()
{
	cin >> N >> L;

	vector<pair<int, int>> pools;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;

		pools.emplace_back(start, end);
	}

	::sort(pools.begin(), pools.end());


	int count = 0;
	int curPos = 0;

	for (auto& pool : pools)
	{
		curPos = ::max(pool.first, curPos);

		while (curPos < pool.second)
		{
			count++;
			curPos += L;
		}
	}

	cout << count;
	return 0;
}