package taeyoung.Week4;

import java.io.*;

public class Prob16918 {
    static int[][] map;
    static int R, C, N;
    static BufferedReader br;
    static BufferedWriter bw;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        R = Integer.parseInt(s[0]);
        C = Integer.parseInt(s[1]);
        N = Integer.parseInt(s[2]);

        map = new int[R+1][C+1];

        for (int i = 1; i <= R; i++) {
            char[] split = br.readLine().toCharArray();
            for (int k = 1; k <= C; k++) {
                if(split[k-1] == 'O')
                    map[i][k] = 3;
                else
                    map[i][k] = -1;
            }
        }

        for(int i = 1; i <= N; i++) {
            for (int row = 1; row <= R; row++) {
                for (int col = 1; col <= C; col++) {
                    if (map[row][col] > 0)
                        map[row][col]--;
                }
            }
            for (int row = 1; row <= R; row++) {
                for (int col = 1; col <= C; col++) {
                    if (map[row][col] == 0)
                        bomb(row, col);
                }
            }
            if (i % 2 == 0) {
                addBomb();
            }
        }

        printMap();
    }
    private enum Point {
        UP(0, 1),
        DOWN(0, -1),
        RIGHT(1, 0),
        LEFT(-1, 0);

        private final int x;
        private final int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    static void bomb(int row, int col) {
        Point[] points = Point.values();
        map[row][col] = -1;
        for (Point point : points) {
            int y = row + point.getY();
            int x = col + point.getX();
            if (y > R || x > C || y <= 0 || x <= 0 || map[y][x] == 0)
                continue;
            map[y][x] = -1;
        }
    }

    static void addBomb(){
        for(int row = 1; row <= R; row++) {
            for (int col = 1; col <= C; col++) {
                if(map[row][col] < 0){
                    map[row][col] = 3;
                }
            }
        }
    }

    static void printMap() throws IOException {
        for (int row = 1; row <= R; row++) {
            for (int col = 1; col <= C; col++) {
                if (map[row][col] >= 0){
                    bw.write('O');
                }else bw.write('.');
            }
            bw.write('\n');
        }
        bw.flush();
        bw.close();
    }
}
