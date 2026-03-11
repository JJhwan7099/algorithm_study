import java.util.Scanner;

class Solution {
    static int N;
    static int[] startPoint;
    static int[] endPoint;
    static int[] currentPoint;
    static int[][] homePoints;
    static int[] comb;
    static int[] visited;
    static int index;
    static int answer;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        for(int tc=1; tc<=TC; tc++) {
            N = sc.nextInt();   
            startPoint = new int[2];
            endPoint = new int[2];
            homePoints = new int[N+1][2];
            comb = new int[N+1];
            visited = new int[N+1];
            index = 1;
            answer = Integer.MAX_VALUE;

            startPoint[0] = sc.nextInt();
            startPoint[1] = sc.nextInt();

            endPoint[0] = sc.nextInt();
            endPoint[1] = sc.nextInt();

            for(int i=1; i<=N; i++) {
                homePoints[i][0] = sc.nextInt();
                homePoints[i][1] = sc.nextInt();
            }

            makeCombs();
            System.out.println("#"+tc+" "+answer);                            
        }
    }

    static void makeCombs() {
        if(index > N) {
            currentPoint = startPoint;
            answer = Math.min(answer, calDistance());
            return;
        }
        for(int i=1; i<=N; i++) {
            if(visited[i]!=1) {
                visited[i] = 1;
                comb[index++] = i;
                makeCombs();
                comb[--index] = 0;
                visited[i] = 0;
            }
        }
    }

    static int calDistance() {
        int totalDistance = 0;
        for(int i=1; i<=N; i++) {
            int[] nextPoint = homePoints[comb[i]];
            int distance = Math.abs(currentPoint[0] - nextPoint[0]) + Math.abs(currentPoint[1] - nextPoint[1]);
            totalDistance += distance;
            currentPoint = nextPoint;
        }
        totalDistance += Math.abs(currentPoint[0] - endPoint[0]) + Math.abs(currentPoint[1] - endPoint[1]);
        return totalDistance;
    }
}