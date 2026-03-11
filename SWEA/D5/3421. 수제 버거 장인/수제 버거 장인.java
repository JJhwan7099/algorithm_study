import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {

    public static int N, M;
    public static int[] combs;
    public static int answer;

    public static Map<Integer, Set<Integer>> check;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());

        for(int tc=1; tc<=TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            combs = new int[N+1];
            check = new HashMap<>();
            for(int i=1; i<=N; i++) check.put(i, new HashSet<>());
            answer = 0;

            for(int i=0; i<M; i++) {
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken());
                int second = Integer.parseInt(st.nextToken());

                Set<Integer> firstSet = check.get(first);
                firstSet.add(second);
                check.put(first, firstSet);

                Set<Integer> secondSet = check.get(second);
                secondSet.add(first);
                check.put(second, secondSet);
            }

            makeComb(1);
            System.out.println("#" + tc + " " + answer);
        }
    }

    public static void makeComb(int n) {
        if(n==N+1) {
            answer++;
            return;
        }
        if(checkFood(n)) {
            combs[n] = 1;
            makeComb(n+1);
        }
        combs[n] = 0;
        makeComb(n+1);
    }

    public static boolean checkFood(int a) {
        Set<Integer> set = check.get(a);
        for(int i=1; i<=N; i++) {
            if(i!=a && combs[i]==1 && set.contains(i)) return false;
        }
        return true;
    }
}