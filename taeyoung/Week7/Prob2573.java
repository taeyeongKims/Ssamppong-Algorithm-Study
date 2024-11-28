package taeyoung.Week7;

import java.awt.*;
import java.io.*;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class Prob2573 {
    static int row, col;
    static int[][] map, cp_map;
    static int[] dirX = {1, 0, -1, 0};
    static int[] dirY = {0, 1, 0, -1};
    static boolean[][] visited;
    static Stack<Point> stack = new Stack<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        map = new int[row][col];

        for (int i = 0; i <row; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < col; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int loaf = 0;
        int rst = 0;
        while(loaf < 2){
            loaf = Solution();
            rst++;

            if(loaf == 0) {
                rst = 0;
                break;
            }
        }

        bw.write(rst + "\n");
        bw.flush();
        bw.close();
    }

    static int Solution(){
        visited = new boolean[row][col];
        for (int i = 0; i < row; i++) {
            Arrays.fill(visited[i], false);
        }

        cp_map = Arrays.stream(map)
                .map(row -> Arrays.copyOf(row, row.length))
                .toArray(int[][]::new);

        melting();
        map = Arrays.stream(cp_map)
                .map(row -> Arrays.copyOf(row, row.length))
                .toArray(int[][]::new);


        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(map[i][j] != 0 && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    static void melting(){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(map[i][j] > 0){
                    for (int k = 0; k < 4; k++) {
                        int next_x = j + dirX[k];
                        int next_y = i + dirY[k];

                        if (next_y < 0 || next_y >= row || next_x < 0 || next_x >= col)
                            continue;

                        if (map[next_y][next_x] == 0)
                            cp_map[i][j] = Math.max(0, --cp_map[i][j]);
                    }
                }
            }
        }
    }
    static void dfs(int now_y, int now_x){
        stack.push(new Point(now_x, now_y));

        while(!stack.isEmpty()){
            Point now = stack.pop();
            visited[now.y][now.x] = true;

            for(int k = 0; k < 4; k++){
                int next_x = now.x + dirX[k];
                int next_y = now.y + dirY[k];
                if(next_y < 0 || next_y >= row || next_x < 0 || next_x >= col)
                    continue;
                if(map[next_y][next_x] != 0 && !visited[next_y][next_x])
                    stack.push(new Point(next_x, next_y));
            }
        }
    }
}
