#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int testCase = 1;
	while (true)
	{
		string str;
		cin >> str;

		if (str[0] == '-') break;

		cout << testCase++ << ". ";

		int count = 0;
		stack<char> stk;
		for (auto ch : str)
		{
			if (stk.empty())
			{
				if (ch == '}') count++;
				stk.push('{');
				continue;
			}

			char top = stk.top();

			if (ch == '}')
			{
				if (top == '{')
				{
					stk.pop();
					continue;
				}
				else
				{
					count++;
					stk.push('{');
				}
			}
			stk.push(ch);
		}

		cout << stk.size() / 2 + count  << endl;
	}
}