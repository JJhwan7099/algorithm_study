import java.util.*;
class Solution {
    public List<Integer> solution(String today, String[] terms, String[] privacies) {
        List<Integer> answer = new ArrayList<>();
        String[] str = today.split("\\.");
        int ttoday = Integer.parseInt(str[0])*12*28+Integer.parseInt(str[1])*28+Integer.parseInt(str[2]);
        HashMap<String, Integer> policy = new HashMap<String, Integer>();
        for(String a: terms)
        {
            String[] spl = a.split(" ");
            policy.put(spl[0],Integer.parseInt(spl[1])*28);
        }
        int index = 0;
        for(int i=0; i<privacies.length; i++) {
            String[] str1 = privacies[i].split("\\ ");
            String[] str2 = str1[0].split("\\.");
            int date = Integer.parseInt(str2[0])*12*28+Integer.parseInt(str2[1])*28+Integer.parseInt(str2[2])+policy.get(str1[1]);
            if(date<=ttoday) {
                answer.add(i+1);
            }
        }
        return answer;
    }
}