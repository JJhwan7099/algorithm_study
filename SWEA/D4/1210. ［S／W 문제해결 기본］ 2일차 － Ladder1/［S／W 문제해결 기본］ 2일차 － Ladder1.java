import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
 
class Solution {

    public static int dy[] = {0,0,-1};
    public static int dx[] = {-1,1,0};
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        for(int tc = 1; tc <= 10; tc++) {
            br.readLine();
            List<List<Integer>> board = new ArrayList<>();
            Boolean isLastLine = false;
            int startX = 0;
            while(!isLastLine) {
                String[] tokens = br.readLine().split(" ");
                List<Integer> line = new ArrayList<>();
                for(int i=0; i<tokens.length; i++) {
                    int num = Integer.parseInt(tokens[i]);
                    if(num==2) {
                        startX = i;
                        isLastLine = true;
                    }
                    line.add(num);
                }
                board.add(line);
            }

            int x = startX;
            int y = board.size()-1;
            int direction = 2;
            boolean isGoUp = true;
            while(y!=0) {
                if(isGoUp) {
                    boolean isDirectionChanged = false;
                    for(int i=0; i<2; i++) {
                        int X = x + dx[i];
                        int Y = y + dy[i];
                        if(X<0 || Y<0 || X>=board.get(0).size() || Y>=board.size()) continue;
                        if(board.get(Y).get(X)==1) {
                            direction = i;
                            isGoUp = false;
                            isDirectionChanged = true;
                            break;
                        }
                    }
                    if(!isDirectionChanged) {
                        x += dx[direction];
                        y += dy[direction];
                    }
                } else {
                    int X = x + dx[direction];
                    int Y = y + dy[direction];
                    if((X<0 || Y<0 || X>=board.get(0).size() || Y>=board.size()) || board.get(Y).get(X)==0) {
                        direction = 2;
                        isGoUp = true;
                        x = x + dx[direction];
                        y = y + dy[direction];
                    }
                    else {
                        x = X;
                        y = Y;
                    }
                }
            }
            System.out.println("#"+tc+" "+x);
        }
    }
}