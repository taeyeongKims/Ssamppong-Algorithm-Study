package taeyoung.Week6;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Prob14466 {
    static int size, K, R;
    static ArrayList<Point>[][] road;
    static Point[] cows;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    static int result = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        size = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        road = new ArrayList[size + 1][size + 1];
        cows = new Point[K];

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                road[i][j] = new ArrayList<>();
            }
        }

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            road[y1][x1].add(new Point(x2, y2));
            road[y2][x2].add(new Point(x1, y1));
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            cows[i] = new Point(x, y);
        }

        for (int i = 0; i < K; i++) {
            bfs(cows[i], i);
        }

        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }

    static void bfs(Point cow, int index) {
        boolean[][] visited = new boolean[size + 1][size + 1];
        Queue<Point> queue = new LinkedList<>();
        queue.add(cow);
        visited[cow.y][cow.x] = true;

        while (!queue.isEmpty()) {
            Point now = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nextX = now.x + dx[i];
                int nextY = now.y + dy[i];
                if (nextX <= 0 || nextX > size || nextY <= 0 || nextY > size) {
                    continue;
                }

                boolean flag = false;
                for (Point roadPoint : road[now.y][now.x]) {
                    if (nextX == roadPoint.x && nextY == roadPoint.y) {
                        flag = true;
                        break;
                    }
                }

                if (flag || visited[nextY][nextX]) continue;

                visited[nextY][nextX] = true;
                queue.add(new Point(nextX, nextY));
            }
        }

        for (int i = index + 1; i < K; i++) {
            if (!visited[cows[i].y][cows[i].x]) {
                result++;
            }
        }
    }

    static class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
