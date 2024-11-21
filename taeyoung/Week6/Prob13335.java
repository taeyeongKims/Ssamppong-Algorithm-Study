package taeyoung.Week6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Prob13335 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        Queue<Integer> truck = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        for(int i= 0; i< n; i++) {
            truck.offer(Integer.parseInt(st.nextToken()));
        }

        int time = 0;
        int bridgeWeight=0;

        Queue<Integer> q = new LinkedList<>();
        for(int i =0; i<w ; i++) {
            q.add(0);
        }

        while(!q.isEmpty()) {
            time++;
            bridgeWeight -= q.poll();
            if(!truck.isEmpty()) {
                if(truck.peek() + bridgeWeight <= L) {
                    bridgeWeight += truck.peek();
                    q.offer(truck.poll());
                }else {
                    q.offer(0);
                }
            }
        }
        System.out.println(time);
    }
}
