import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static int N,M;
    static int[] parents;
    static String answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            parents = new int[N+1];
            answer = "";
            for(int i=1; i<=N; i++) parents[i] = i;

            for(int i=1; i<=M; i++) {
                int cmd,a,b;
                st = new StringTokenizer(br.readLine());

                cmd = Integer.parseInt(st.nextToken());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());

                if(cmd==1) {
                    int aParent = findParent(a);
                    int bParent = findParent(b);
                    if(aParent==bParent) answer += "1";
                    else answer += "0";
                }
                else union(a,b);
            }

            System.out.println("#"+tc+" "+answer);
        }
    }

    static void union(int a, int b) {
        int aParent = findParent(a);
        int bParent = findParent(b);

        parents[bParent] = aParent;
    }

    static int findParent(int n) {
        if(parents[n] == n) return n;
        int parent = findParent(parents[n]);
        parents[n] = parent;
        return parent;
    }
}
