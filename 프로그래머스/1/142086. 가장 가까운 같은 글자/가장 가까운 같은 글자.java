import java.util.*;
class Solution {
    public List<Integer> solution(String s) {
        List<Integer> answer = new ArrayList<>();
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        for(int i=0; i<s.length(); i++) {
            if(map.containsKey(s.charAt(i))) {
                answer.add(i - map.get(s.charAt(i)));
                map.put(s.charAt(i), i);
            }else {
                answer.add(-1);
                map.put(s.charAt(i), i);
            }
        }
        return answer;
    }
}