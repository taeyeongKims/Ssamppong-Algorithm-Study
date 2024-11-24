#include <iostream>
using namespace std;
#include <deque>
struct Info
{
	int rest = 0;
	int wei;
};

deque<Info> dq;
int N, W, L;

int main()
{
	cin >> N >> W >> L;

	for (int i = 0; i < N; i++)
	{
		int wei; cin >> wei;
		dq.push_back(Info{ W, wei });
	}

	int cnt = 0;
	while (true)
	{
		int onBoard = 0;
		int currPassing = 0;
		for (auto& i : dq)
		{
			if (i.rest == 0)
			{
				dq.pop_front();
			}
		}
		for (auto& i : dq)
		{
			if (currPassing > W)
			{
				break;
			}
			if (onBoard + i.wei <= L)
			{
				onBoard += i.wei;
				i.rest -= 1;
				currPassing += 1;
				if (i.rest == W - 1)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		cnt++;

		if (dq.empty())
			break;
	}
	cout << cnt << endl;
}