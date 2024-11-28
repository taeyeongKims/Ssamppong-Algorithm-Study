package taeyoung.Week7;

import java.io.*;
import java.util.StringTokenizer;

public class Prob10158 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int time = Integer.parseInt(br.readLine());

        int newX = (x + time) % (2 * w);
        int newY = (y + time) % (2 * h);

        if (newX > w) newX = 2 * w - newX;
        if (newY > h) newY = 2 * h - newY;

        bw.write(newX + " " + newY + "\n");
        bw.flush();
        bw.close();
    }
}
