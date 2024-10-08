#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

long long int factorial(int num)
{
	long long int res = 1;
	for (int i = 1; i <= num; i++)
	{
		res = (res * i) % 1000000007;
	}
	return res;
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<int>> seats;
	int Row, Col, gap;

	cin >> Row >> Col >> gap;

	seats = vector<vector<int>>(Row, vector<int>(Col, 0));
	for (int j = 0; j < Row; j++)
	{
		for (int i = 0; i < Col; i++)
		{
			int num; cin >> num;
			seats[j][i] = j * gap + num;
		}
	}

	for (int i = 0; i < Row; i++)
	{
		::sort(seats[i].begin(), seats[i].end(), [](int a, int b) {return a < b; });
	}

	long long int Cases = 1;

	long long int SubCases;
	for (int j = 1; j < Row; j++)
	{

		for (int i = 0; i < Col; i++)
		{
			SubCases = 0;
			for (int k = 0; k < Col; k++)
			{
				if (seats[j][i] > seats[j - 1][k])
				{
					SubCases += 1;
				}
			}

			if (SubCases - i > 0)
			{
				SubCases -= i;
			}

			else if (SubCases - i <= 0)
			{
				cout << "0" << endl;
				return 0;
			}

			Cases = (Cases * SubCases) % 1000000007;
		}
	}
	Cases *= factorial(Col);

	cout << Cases % 1000000007 << endl;

	return 0;
}