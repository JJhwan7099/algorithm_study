import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {
    
    static int N,W,H;
    static int[][] board;
    static int[][] tempBoard;
    static int[] comb;
    static int index;
    static int answer;

    static int[] dx = {0,0,1,-1};
    static int[] dy = {1,-1,0,0};
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            board = new int[H+1][W+1];
            tempBoard = new int[H+1][W+1];
            comb = new int[N+1];
            index  = 1;
            answer = Integer.MAX_VALUE;

            for(int i=1; i<=H; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=1; j<=W; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
            makeComb(1);
            System.out.println("#"+tc+" "+answer);
        }
    }

    static void makeComb(int n) {
        if(index>N) {
            start();
            return;
        }
        for(int i=1; i<=W; i++) {
            comb[index++] = i;
            makeComb(i);
            comb[--index] = 0;
        }
    }

    static void start() {
        for(int i=1; i<=H; i++) tempBoard[i] = board[i].clone();
        
        for(int i=1; i<=N; i++) {
            shoot(comb[i]);
            gravity();
        }
        int count = 0;
        for(int i=1; i<=H; i++) {
            for(int j=1; j<=W; j++) {
                if(tempBoard[i][j]!=0) count++;
            }
        }
        answer = Math.min(answer, count);
    }

    static void gravity() {
        for(int i=H; i>=1; i--) {
            for(int j=W; j>=1; j--) {
                if(tempBoard[i][j]==0) continue;
                int x = i;
                while(x+1 <= H && tempBoard[x+1][j]==0

                ) {
                    tempBoard[x+1][j] = tempBoard[x][j];
                    tempBoard[x][j] = 0;
                    x++;
                }
            }
        }
    }

    static void shoot(int y) {
        Deque<int[]> queue = new ArrayDeque<>();
        for(int i=1; i<=H; i++) {
            if(tempBoard[i][y]!=0) {
                queue.addLast(new int[]{i,y});
                break;
            }
        }
        while(!queue.isEmpty()) {
            int[] point = queue.removeFirst();
            int curX = point[0];
            int curY = point[1];
            int power = tempBoard[curX][curY];
            
            
            tempBoard[curX][curY] = 0;

            for(int i=0; i<4; i++) {
                for(int j=1; j<power; j++) {
                    int nextX = curX + (j*dx[i]);
                    int nextY = curY + (j*dy[i]);

                    if(nextX<1 || nextY<1 || nextX>H || nextY>W) continue;
                    if(tempBoard[nextX][nextY]!=0) {
                        queue.addLast(new int[]{nextX, nextY});
                    }
                }    
            }
        }
    }
}