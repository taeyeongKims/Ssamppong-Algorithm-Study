package taeyoung.Week5;

import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Prob1911 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static PriorityQueue<Pool> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        String[] split = br.readLine().split(" ");
        int pool = Integer.parseInt(split[0]);
        int board_size = Integer.parseInt(split[1]);

        for(int i = 0; i < pool; i++) {
            String[] input = br.readLine().split(" ");
            int start = Integer.parseInt(input[0]);
            int end = Integer.parseInt(input[1]) - 1;

            pq.add(new Pool(start, end));
        }

        int board_pos = 0;
        int board_num = 0;
        for (int i = 0; i < pool; i++) {
            Pool cur_pool = pq.poll();
            if(board_pos < cur_pool.start-1)
                board_pos = cur_pool.start-1;

            while(board_pos < cur_pool.end){
                board_pos += board_size;
                board_num++;
            }
        }

        bw.write(board_num + "\n");
        bw.flush();
        bw.close();
    }
    static class Pool implements Comparable<Pool>{
        int start;
        int end;

        public Pool(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Pool o) {
            return this.start - o.start;
        }
    }
}
