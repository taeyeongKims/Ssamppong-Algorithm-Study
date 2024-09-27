#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define BUFFER_SIZE 256

int N, M, H;
vector<vector<int>> gBlocks;
int dp[51][1001] = {};

vector<int> Split(string inStr)
{
	vector<int> result = {};

	while (!inStr.empty())
	{
		result.push_back(::stoi(inStr));

		size_t idx = inStr.find(' ');
		if (idx == string::npos) break;

		inStr = string(inStr.begin() + idx + 1, inStr.end());
	}

	return result;
}

int Solution(int studentIdx, int curHeight)
{
	if (studentIdx == N)
	{
		if (curHeight == H)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if (dp[studentIdx][curHeight] != -1)
	{
		return dp[studentIdx][curHeight];
	}

	int result = 0;

	//내것을 넣을 때
	const vector<int>& myBlocks = gBlocks[studentIdx];

	for (size_t i = 0; i < myBlocks.size(); ++i)
	{
		if (curHeight + myBlocks[i] <= H)
		{
			result += Solution(studentIdx + 1, curHeight + myBlocks[i]);
		}
	}

	//내것을 안넣을 때
	result += Solution(studentIdx + 1, curHeight);

	return dp[studentIdx][curHeight] = (result % 10007);
}

int main()
{
	cin >> N >> M >> H;

	gBlocks = vector<vector<int>>(N, vector<int>());

	fill(&dp[0][0],&dp[0][0] + 51 * 1001, -1);

	for (size_t i = 0; i < N; ++i)
	{
		string buffer;
		do {
			getline(cin, buffer);
		} while (buffer.empty());

		vector<int> splited = Split(buffer);
		gBlocks[i] = splited;
	}

	cout << Solution(0, 0);

	return 0;
}