import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {

    static int N;
    static int cheese[][];
    static final int[] dx = {0,0,1,-1};
    static final int[] dy = {1,-1,0,0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= TC; tc++) {
            N = Integer.parseInt(br.readLine());
            cheese = new int[N+1][N+1];
            for(int i=1; i<=N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=1; j<=N; j++) {
                    cheese[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            System.out.println("#"+tc+" "+solve());
        }
    }

    static int solve() {
        int maxCheeseCount = 0;
        for(int i=0; i<=100; i++) {
            eatCheese(i);
            maxCheeseCount = Math.max(maxCheeseCount,getCheeseCount());
        }
        return maxCheeseCount;
    }

    static void eatCheese(int day) {
        for(int i=1; i<=N; i++)for(int j=1; j<=N; j++) if(cheese[i][j]==day) cheese[i][j]=-1;
    }

    static int getCheeseCount() {
        Deque<int[]> queue = new ArrayDeque<>();
        int[][] visited = new int[N+1][N+1];
        int result = 0;
        for(int i=1; i<=N; i++)for(int j=1; j<=N; j++) {
            if(cheese[i][j]!=-1 && visited[i][j]!=1) {
                queue.addLast(new int[]{i,j});
                visited[i][j]=1;
                while(!queue.isEmpty()) {
                    int point[] = queue.removeFirst();
                    int x = point[0];
                    int y = point[1];
                    for(int k=0; k<4; k++) {
                        int X = x + dx[k];
                        int Y = y + dy[k];
                        if(X<1||Y<1||X>N||Y>N) continue;
                        else if(cheese[X][Y]!=-1 && visited[X][Y]!=1) {
                            visited[X][Y]=1;
                            queue.addLast(new int[]{X,Y});
                        }
                    }
                }
                result++;
            }
        }

        return result;
    }
}