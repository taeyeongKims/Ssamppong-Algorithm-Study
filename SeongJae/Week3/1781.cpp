#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 200001

int rep;
vector<int> problems[MAX];


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> rep;

    for (int i = 0; i < rep; i++) 
    {
        int Deadline, Gotcha;
        cin >> Deadline >> Gotcha;

        problems[Deadline].push_back(Gotcha);
    }

    int result = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int day = rep; day >= 1; day--)
    {
        for (auto p : problems[day])
        {
            pq.push(p);
        }
        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << endl;
    return 0;
}
