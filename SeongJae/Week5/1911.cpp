#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;
vector<pair<int, int>> info;

bool compare(const pair<int, int>& a, const pair<int, int>& b) 
{
    return a.first < b.first;
}

int Set()
{
    int res = 0;
    int curr = 0;

    for (auto& i : info)
    {
        if (i.first > curr)
        {
            curr = i.first;
        }

        while (curr < i.second)
        {
            res++;
            curr += L;
        }
    }
    return res;
}

int main() 
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        info.push_back({ start, end });
    }

    sort(info.begin(), info.end(), compare);

    cout << Set() << endl;
    return 0;
}
