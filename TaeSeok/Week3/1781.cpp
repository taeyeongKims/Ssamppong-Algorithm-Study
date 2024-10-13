#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;

struct Problem
{
	int deadline;
	int count;

	Problem(int deadline, int count) : deadline(deadline), count(count) {}

	bool operator<(const Problem& other) const
	{
		return deadline < other.deadline;
	}
};

int main()
{
	cin >> N;

	vector<Problem> problems;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		int deadline;
		int count;

		cin >> deadline >> count;

		problems.push_back({ deadline, count });
	}

	::sort(problems.begin(), problems.end());

	for (auto& problem : problems)
	{
		if (pq.size() < problem.deadline)
		{
			pq.push(problem.count);
		}
		else if (pq.top() < problem.count)
		{
			pq.pop();
			pq.push(problem.count);
		}
	}

	int sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}