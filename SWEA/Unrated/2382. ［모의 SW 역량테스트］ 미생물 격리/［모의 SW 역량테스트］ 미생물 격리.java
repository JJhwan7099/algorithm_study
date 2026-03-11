import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {
    static int N;
    static int M;
    static Bug[][] board;
    static Deque<int[]> queue;

    static final int[] dx = {0,-1,1,0,0};
    static final int[] dy = {0,0,0,-1,1};

    static class Bug{
        int dir;
        int amount;

        Bug(int dir, int amount) {
            this.dir = dir;
            this.amount = amount;
        }
        
        Bug(Bug b) {
            this.dir = b.dir;
            this.amount = b.amount;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            board = new Bug[N][N];
            queue = new ArrayDeque<>();

            for(int i=1; i<=K; i++) {
                int x, y, n, d;
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                n = Integer.parseInt(st.nextToken());
                d = Integer.parseInt(st.nextToken());
                board[x][y] = new Bug(d, n);
                queue.addLast(new int[]{x,y});
            }

            start();

            int cnt = 0;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(board[i][j]!=null) cnt += board[i][j].amount;
                }
            }

            System.out.println("#"+tc+" "+cnt);
        }

    }
    
    static void start() {
        for(int i=1; i<=M; i++) {
            Bug[][] tempBoard = new Bug[N][N];
            int[][] maxAmount = new int[N][N];
            int size = queue.size();
            for(int j=1; j<=size; j++) {
                int[] point = queue.removeFirst();
                int x = point[0];
                int y = point[1];
                Bug curBug = board[x][y];

                int nextX = x + dx[curBug.dir];
                int nextY = y + dy[curBug.dir];

                Bug nextBug;

                if(tempBoard[nextX][nextY]!=null) {
                    nextBug = tempBoard[nextX][nextY];
                    if(maxAmount[nextX][nextY] < curBug.amount) {
                        nextBug.dir = curBug.dir;
                    }
                    nextBug.amount += curBug.amount;
                }
                else nextBug = new Bug(curBug);
                
                tempBoard[nextX][nextY] = nextBug;
                maxAmount[nextX][nextY] = Math.max(maxAmount[nextX][nextY], curBug.amount);
            }
            for(int x=0; x<N; x++) {
                for(int y=0; y<N; y++) {
                    if(tempBoard[x][y]!=null) {
                        if((x==0 || x==N-1 || y==0 || y==N-1)) {
                            if(tempBoard[x][y].dir%2==1) tempBoard[x][y].dir++;
                            else tempBoard[x][y].dir--;

                            tempBoard[x][y].amount /= 2;
                            if(tempBoard[x][y].amount <= 0) tempBoard[x][y] = null;
                        }
                        if(tempBoard[x][y] != null) queue.addLast(new int[]{x,y});
                    }
                }
            }
            board = tempBoard;
        }
    }
}
