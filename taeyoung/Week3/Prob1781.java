package taeyoung.Week3;

import java.io.*;
import java.util.*;

public class Prob1781 {
    static Problem[] problems;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        problems = new Problem[num + 1];

        for (int i = 1; i <= num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int deadline = Integer.parseInt(st.nextToken());
            int reward = Integer.parseInt(st.nextToken());
            problems[i] = new Problem(deadline, reward);
        }

        Arrays.sort(problems, 1, num+1, (o1, o2) -> Integer.compare(o2.deadline, o1.deadline));

        PriorityQueue<Problem> pq = new PriorityQueue<>();

        int index=1;
        int sum=0;
        for(int i=num; i>=1; i--) {
            while(index<problems.length && problems[index].deadline==i) {
                pq.add(problems[index++]);
            }

            if(pq.isEmpty()) continue;

            sum+=pq.poll().reward;
        }

        bw.write(String.valueOf(sum));
        bw.flush();
        bw.close();
    }

    static class Problem implements Comparable<Problem> {
        int deadline;
        int reward;

        public Problem(int deadline, int reward) {
            this.deadline = deadline;
            this.reward = reward;
        }
        @Override
        public int compareTo(Problem problem) {
            if (this.reward < problem.reward)
                return 1;
            else if (this.reward == problem.reward) {
                if (this.deadline > problem.deadline)
                    return 1;
                else if (this.deadline == problem.deadline)
                    return 0;
            }
            return -1;
        }
    }
}