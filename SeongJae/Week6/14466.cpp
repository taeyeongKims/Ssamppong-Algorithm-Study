#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
vector<pair<int, int>> roads[MAX][MAX];
bool visited[MAX][MAX];
int N, K, R;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool isBlocked(int x1, int y1, int x2, int y2)
{
    for (auto road : roads[x1][y1])
    {
        if (road.first == x2 && road.second == y2)
            return true;
    }
    return false;
}

void bfs(int startX, int startY, vector<pair<int, int>>& group)
{
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        group.push_back({ x, y });

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (visited[nx][ny]) continue;
            if (isBlocked(x, y, nx, ny)) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> R;

    for (int i = 0; i < R; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        roads[r1][c1].push_back({ r2, c2 });
        roads[r2][c2].push_back({ r1, c1 });
    }

    vector<pair<int, int>> cows(K);
    for (int i = 0; i < K; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    memset(visited, false, sizeof(visited));
    vector<vector<pair<int, int>>> groups;

    for (int x = 1; x <= N; x++)
    {
        for (int y = 1; y <= N; y++)
        {
            if (!visited[x][y])
            {
                vector<pair<int, int>> group;
                bfs(x, y, group);
                groups.push_back(group);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int cowCount = 0;
        for (auto cell : groups[i])
        {
            for (auto cow : cows)
            {
                if (cell == cow)
                    cowCount++;
            }
        }
        result += cowCount * (K - cowCount);
    }

    cout << result / 2 << endl;
    return 0;
}