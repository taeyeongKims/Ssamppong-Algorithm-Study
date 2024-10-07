package taeyoung.Week3;

import java.io.*;
import java.util.StringTokenizer;

public class Prob1074 {
    static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int size = (int)Math.pow(2, N);

        find(size, r, c);

        bw.write(String.valueOf(cnt));
        bw.flush();
        bw.close();
    }
    static void find(int size, int r, int c){
        if(size == 1)
            return;

        if(r < size/2 && c < size/2){
            find(size/2, r, c);
        }
        if(r < size/2 && c >= size/2){
            cnt += size * size / 4;
            find(size/2, r, c - size/2);
        }
        if(r >= size/2 && c < size/2){
            cnt += (size * size / 4) * 2;
            find(size/2, r - size/2, c);
        }
        if(r >= size/2 && c >= size/2){
            cnt += (size * size / 4) * 3;
            find(size/2, r - size/2, c - size/2);
        }
    }
}
