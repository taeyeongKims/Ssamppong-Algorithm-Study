#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

deque<int> repo;
string buffer;
int T, N;

void processCommands(const string& commands, bool& isReversed, bool& errorBlob)
{
    isReversed = false;
    errorBlob = false;

    for (char cmd : commands)
    {
        if (cmd == 'R')
        {
            isReversed = !isReversed;
        }
        else if (cmd == 'D')
        {
            if (repo.empty())
            {
                errorBlob = true;
                return;
            }
            if (isReversed)
            {
                repo.pop_back();
            }
            else
            {
                repo.pop_front();
            }
        }
    }
}

deque<int> SplitArray(const string& inString)
{
    deque<int> result;
    if (inString.size() <= 2)
    {
        return result;
    }

    string buffer = inString.substr(1, inString.size() - 2);
    size_t start = 0;
    size_t end = buffer.find(',');

    while (end != string::npos)
    {
        string numStr = buffer.substr(start, end - start);
        result.push_back(stoi(numStr));
        start = end + 1;
        end = buffer.find(',', start);
    }

    if (start < buffer.size())
    {
        result.push_back(stoi(buffer.substr(start)));
    }

    return result;
}

void PrintArray(bool isReversed)
{
    stringstream ss;
    ss << "[";

    if (isReversed)
    {
        for (int i = repo.size() - 1; i >= 0; i--)
        {
            ss << repo[i];
            if (i != 0)
                ss << ",";
        }
    }
    else
    {
        for (int i = 0; i < repo.size(); i++)
        {
            ss << repo[i];
            if (i != repo.size() - 1)
                ss << ",";
        }
    }

    ss << "]";
    cout << ss.str() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        repo.clear();
        cin >> buffer;
        string commands = buffer;

        cin >> N;
        cin >> buffer; 
        repo = SplitArray(buffer);

        bool isReversed = false;
        bool errorBlob = false;

        processCommands(commands, isReversed, errorBlob);

        if (errorBlob)
        {
            cout << "error\n";
        }
        else
        {
            PrintArray(isReversed);
        }
    }

    return 0;
}
