import java.util.*;
public class Main{
    static int N, M;
    static int[] vis = new int[101];
    static List<Integer>[] list = new ArrayList[101];
    static int answer = 0;
    static void dfs(int n) {
        vis[n] = 1;
        answer++;
        for(int i=0; i<list[n].size(); i++) {
            if(vis[list[n].get(i)]!=1) { 
                dfs(list[n].get(i));
            }
        }
    }
    public static void main(String[] args) {
        for(int i=1; i<=100; i++) list[i] = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        for(int i=1; i<=M; i++) {
            int a, b;
            a = scanner.nextInt(); b = scanner.nextInt();
            list[a].add(b); list[b].add(a);
        }
        dfs(1);
        System.out.println(answer-1);
    }
}