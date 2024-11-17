package taeyoung.Week5;

import java.io.*;

public class Prob1522 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int a_num, b_num, len;
    static char[] input;
    public static void main(String[] args) throws IOException {
        input = br.readLine().toCharArray();
        len = input.length;

        a_num = 0;

        for (char c : input) {
            if (c == 'a')
                a_num++;
        }
        b_num = len - a_num;

        int result = len;
        for (int i = 0; i < len; i++) {
            int cntB = countB(i);
            if (cntB < result)
                result = cntB;
        }

        bw.write(result + "\n");
        bw.flush();
        bw.close();
    }

    static int countB(int start){
        int cnt = 0;
        for (int i = start; i < start + a_num; i++) {
            if(input[i % len] == 'b')
                cnt++;
        }
        return cnt;
    }
}
