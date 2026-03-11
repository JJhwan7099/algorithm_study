import java.util.*;

public class Solution {

    static Map<Long, Integer> memo = new HashMap<>();

    static int solve(long n) {
        if (n < 10) return 0;
        if (memo.containsKey(n)) return memo.get(n);

        String s = Long.toString(n);
        int len = s.length();
        int positions = len - 1;
        int maxTurn = 0;

        for (int mask = 1; mask < (1 << positions); mask++) {
            List<Long> parts = new ArrayList<>();
            int start = 0;
            for (int i = 0; i < positions; i++) {
                if ((mask & (1 << i)) != 0) {
                    parts.add(Long.parseLong(s.substring(start, i + 1)));
                    start = i + 1;
                }
            }
            parts.add(Long.parseLong(s.substring(start)));

            long product = 1;
            for (long p : parts) product *= p;

            int turns = 1 + solve(product);
            if (turns > maxTurn) maxTurn = turns;
        }

        memo.put(n, maxTurn);
        return maxTurn;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            long n = sc.nextLong();
            System.out.println("#" + t + " " + solve(n));
        }
        sc.close();
    }
}