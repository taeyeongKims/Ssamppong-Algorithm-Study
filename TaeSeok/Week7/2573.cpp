//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int N, M;
//int grid[301][301];
//int visited[301][301];
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, -1, 1 };
//
//// BFS·Î ºù»êÀÇ µ¢¾î¸® ¼ö °è»ê
//void bfs(int x, int y)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//    visited[x][y] = 1;
//
//    while (!q.empty()) 
//    {
//        auto cur = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++) 
//        {
//            int nx = cur.first + dx[i];
//            int ny = cur.second + dy[i];
//
//            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && grid[nx][ny] > 0) 
//            {
//                visited[nx][ny] = 1;
//                q.push({ nx, ny });
//            }
//        }
//    }
//}
//
//// ¸Å³â ºù»ê ³ìÀÌ±â
//void melt()
//{
//    int temp[301][301];
//    memcpy(temp, grid, sizeof(grid));
//
//    for (int x = 0; x < N; x++) 
//    {
//        for (int y = 0; y < M; y++) 
//        {
//            if (grid[x][y] > 0) 
//            {
//                int seaCount = 0;
//                for (int i = 0; i < 4; i++) 
//                {
//                    int nx = x + dx[i];
//                    int ny = y + dy[i];
//
//                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 0)
//                    {
//                        seaCount++;
//                    }
//                }
//
//                temp[x][y] = max(0, grid[x][y] - seaCount);
//            }
//        }
//    }
//
//    memcpy(grid, temp, sizeof(grid));
//}
//
//int main()
//{
//    cin >> N >> M;
//
//    for (int i = 0; i < N; i++) 
//        for (int j = 0; j < M; j++) 
//            cin >> grid[i][j];
//
//    int years = 0;
//    while (true)
//    {
//        memset(visited, 0, sizeof(visited));
//
//        int components = 0;
//        for (int i = 0; i < N; i++) 
//        {
//            for (int j = 0; j < M; j++) 
//            {
//                if (!visited[i][j] && grid[i][j] > 0) 
//                {
//                    bfs(i, j);
//                    components++;
//                }
//            }
//        }
//
//        if (components >= 2) 
//        {
//            cout << years << endl;
//            return 0;
//        }
//
//        if (components == 0) 
//        {
//            cout << 0 << endl;
//            return 0;
//        }
//
//        melt();
//        years++;
//    }
//}
