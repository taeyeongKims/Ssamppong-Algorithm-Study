package taeyoung.Week4;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Prob18808 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int note_width, note_height, sticker_num, sticker_width, sticker_height;
    static ArrayList<int[][]> stickers = new ArrayList<>();
    static int[][] notebook;

    public static void main(String[] args) throws IOException {
        List<Integer> input = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        note_height = input.get(0);
        note_width = input.get(1);
        sticker_num = input.get(2);

        notebook = new int[note_height][note_width];

        for (int k = 0; k < sticker_num; k++) {
            String[] size = br.readLine().split(" ");
            sticker_height = Integer.parseInt(size[0]);
            sticker_width = Integer.parseInt(size[1]);

            int[][] sticker = new int[sticker_height][sticker_width];
            for (int i = 0; i < sticker_height; i++) {
                sticker[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            }
            stickers.add(sticker);
        }

        Solution();

        int result = 0;
        for (int i = 0; i < note_height; i++) {
            for (int j = 0; j < note_width; j++) {
                if (notebook[i][j] == 1) result++;
            }
        }
        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }

    static void Solution() {
        for (int[][] sticker : stickers) {
            for (int r = 0; r < 4; r++) {
                if (tryPlaceSticker(sticker)) {
                    break;
                }
                sticker = rotate(sticker);
            }
        }
    }

    static boolean tryPlaceSticker(int[][] sticker) {
        int sh = sticker.length;
        int sw = sticker[0].length;

        for (int i = 0; i <= note_height - sh; i++) {
            for (int j = 0; j <= note_width - sw; j++) {
                if (canPlace(i, j, sticker)) {
                    placeSticker(i, j, sticker);
                    return true;
                }
            }
        }
        return false;
    }

    static boolean canPlace(int x, int y, int[][] sticker) {
        int sh = sticker.length;
        int sw = sticker[0].length;

        for (int i = 0; i < sh; i++) {
            for (int j = 0; j < sw; j++) {
                if (sticker[i][j] == 1 && notebook[x + i][y + j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    static void placeSticker(int x, int y, int[][] sticker) {
        int sh = sticker.length;
        int sw = sticker[0].length;

        for (int i = 0; i < sh; i++) {
            for (int j = 0; j < sw; j++) {
                if (sticker[i][j] == 1) {
                    notebook[x + i][y + j] = 1;
                }
            }
        }
    }

    static int[][] rotate(int[][] sticker) {
        int sh = sticker.length;
        int sw = sticker[0].length;
        int[][] rotated = new int[sw][sh];

        for (int i = 0; i < sh; i++) {
            for (int j = 0; j < sw; j++) {
                rotated[j][sh - 1 - i] = sticker[i][j];
            }
        }
        return rotated;
    }
}
