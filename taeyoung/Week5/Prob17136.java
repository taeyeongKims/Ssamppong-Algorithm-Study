package taeyoung.Week5;

import java.io.*;

public class Prob17136 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] map = new int[10][10];
    static int[] paperCount = {0, 5, 5, 5, 5, 5};
    static int minPapers = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 10; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 10; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        solve(0, 0, 0);
        System.out.println(minPapers == Integer.MAX_VALUE ? -1 : minPapers);
    }

    static void solve(int row, int col, int usedPapers) {
        if (row == 10) {
            minPapers = Math.min(minPapers, usedPapers);
            return;
        }

        if (col == 10) {
            solve(row + 1, 0, usedPapers);
            return;
        }

        if (map[row][col] == 0) {
            solve(row, col + 1, usedPapers);
            return;
        }

        for (int size = 1; size <= 5; size++) {
            if (canPlace(row, col, size) && paperCount[size] > 0) {
                placePaper(row, col, size, 0);
                paperCount[size]--;

                solve(row, col + 1, usedPapers + 1);

                placePaper(row, col, size, 1);
                paperCount[size]++;
            }
        }
    }

    static boolean canPlace(int row, int col, int size) {
        if (row + size > 10 || col + size > 10) return false;

        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (map[i][j] == 0) return false;
            }
        }
        return true;
    }

    static void placePaper(int row, int col, int size, int value) {
        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                map[i][j] = value;
            }
        }
    }
}
