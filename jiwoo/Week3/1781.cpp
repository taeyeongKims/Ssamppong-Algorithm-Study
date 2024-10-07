#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Item
{
	int Deadline;
	int RamenCnt;
};

int N;
vector<Item> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		Item item = {  };
		cin >> item.Deadline;
		cin >> item.RamenCnt;

		vec.push_back(item);
	}

	::sort(vec.begin(), vec.end(), [](const Item& left, const Item& right) {return left.Deadline < right.Deadline; });

	for (const Item& item : vec)
	{
		if (pq.size() < item.Deadline)
		{
			pq.push(item.RamenCnt);
		}
		else if(pq.top() < item.RamenCnt)
		{
			pq.pop();
			pq.push(item.RamenCnt);
		}
	}

	int rst = 0;
	while (!pq.empty())
	{
		rst += pq.top();
		pq.pop();
	}

	cout << rst;
}
