package taeyoung.Week4;

import java.io.*;
import java.util.Stack;

public class Prob4889 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        char[] openCloseList;
        Stack<Character> stack = new Stack<Character>();
        int count = 0;
        while (true) {
            openCloseList= br.readLine().toCharArray();
            if(openCloseList[0] == '-') break;

            count++;
            int len = openCloseList.length;
            int changeCount = 0;
            stack.clear();

            for(int i = 0; i < len; i++) {
                if(openCloseList[i] == '}') {
                    if(stack.isEmpty()) {
                        changeCount++;
                        stack.push('{');
                    } else {
                        stack.pop();
                    }
                }
                if(openCloseList[i] == '{'){
                    stack.push('{');
                }
            }

            if (!stack.isEmpty()){
                changeCount += (stack.size() / 2);
            }
            bw.write(count+". "+changeCount+"\n");
        }

        bw.flush();
        bw.close();
    }
}
