import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

    static final int[] dx = {0,0,1,-1};
    static final int[] dy = {1,-1,0,0};

    static int TC;
    static int N,M;
    static char[][] board;

    static int[] startPoint;
    static int[] endPoint;

    static int[][] spreadTimeBoard;
    static int[][] visitedDis;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TC = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            board = new char[N+1][M+1];
            spreadTimeBoard = new int[N+1][M+1];
            visitedDis = new int[N+1][M+1];

            for(int i=1; i<=N; i++) {
                String line = br.readLine();
                for(int j=1; j<=M; j++) {
                    board[i][j] = line.charAt(j-1);
                    spreadTimeBoard[i][j] = -1;
                    visitedDis[i][j] = -1;
                    if(board[i][j]=='S') startPoint = new int[] {i,j};
                    else if(board[i][j]=='D') endPoint = new int[] {i,j};
                    else if(board[i][j]=='*') spreadTimeBoard[i][j] = 0;
                }
            }

            setSpreadBoard();
            int result = start();
            if(result != -1) System.out.println("#" + tc + " " + result);
            else System.out.println("#" + tc + " GAME OVER");
        }
    }

    private static int start() {
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{startPoint[0], startPoint[1], 0});
        visitedDis[startPoint[0]][startPoint[1]] = 0;
        
        while(!queue.isEmpty()) {
            int[] curInfo = queue.poll();
            int x = curInfo[0];
            int y = curInfo[1];
            int time = curInfo[2];
            if(board[x][y]=='D') return time;

            for(int i=0; i<4; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X<1 || Y<1 || X>N || Y>M || board[X][Y]=='X') continue;
                else if((visitedDis[X][Y]==-1 || visitedDis[X][Y] > time+1) && (spreadTimeBoard[X][Y] > time+1 || spreadTimeBoard[X][Y]==-1)) {
                    queue.offer(new int[] {X,Y,time+1});
                    visitedDis[X][Y] = time+1;
                }
            }
        }

        return -1;
    }

    private static void setSpreadBoard() {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(board[i][j]=='*') spread(i,j,0);
            }
        }
    }

    private static void spread(int x, int y, int time) {
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1 || Y<1 || X>N || Y>M) continue;
            else if(board[X][Y]!='X' && board[X][Y]!='D' && (time+1 < spreadTimeBoard[X][Y] || spreadTimeBoard[X][Y]==-1)) {
                spreadTimeBoard[X][Y] = time+1;
                spread(X, Y, time+1);
            }
        }
    }
}