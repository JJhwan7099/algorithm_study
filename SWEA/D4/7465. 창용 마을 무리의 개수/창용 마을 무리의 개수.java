import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    static int N,M;
    static int[] parents;
    static int[] checked;
    static int answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            parents = new int[N+1];
            checked = new int[N+1];
            answer = 0;

            for(int i=1; i<=N; i++) parents[i] = i;

            for(int i=1; i<=M; i++) {
                int a,b;
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                union(a,b);
            }

            for(int i=1; i<=N; i++) {
                int parent = findParent(i);
                if(checked[parent] != 1) {
                    checked[parent] = 1;
                    answer++;
                }
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
