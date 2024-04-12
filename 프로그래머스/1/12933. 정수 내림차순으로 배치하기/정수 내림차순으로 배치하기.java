import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        List<Long> list = new ArrayList<>();
        while(n>0) {
            list.add(n%10);
            n/=10;
        }
        Collections.sort(list);
        int cnt = 1;
        for(int i=0; i<list.size(); i++) {
            answer+=list.get(i)*cnt;
            cnt*=10;
        }
        return answer;
    }
}