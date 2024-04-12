class Solution {
    public int solution(String s) {
        int answer = 0;
        char c = s.charAt(0);
        int st = 1;
        int e = 0;
        for(int i=1; i<s.length(); i++) {
            if(s.charAt(i)==c) {
                st++;
            }else e++;
            if(st==e||i==s.length()-1) {
                st=0;
                e=0;
                if(i+1<s.length())c = s.charAt(i+1);
                answer++;
            }
        }
        if(answer==0) answer=1;
        return answer;
    }
}