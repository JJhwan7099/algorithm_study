#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i=1; i<=s.length(); i++)
    {
        vector<string> v;
        string result="";
        // string ss="";
        for(int j=0; j<s.length(); j++)
        {
            int c = i;
            string sss="";
            while(c--)
            {
                if(j<s.length()) sss+=s[j];
                j++;
            }
            j--;
            v.push_back(sss);
            // if(ss==sss) 
            // {
            //     cnt++;
            // }
            // if(ss!=sss)
            // {
            //     if(cnt!=1)result+=to_string(cnt);
            //     result+=ss;
            //     ss = sss;
            //     cnt=1;
            // }
            // if(sss.length()<i) result+=sss;
        }
        v.push_back(" ");
        string ss = v[0];
        int cnt=1;
        for(int k=1; k<v.size(); k++)
        {
            if(ss==v[k])
            {
                cnt++;
            }else if(ss!=v[k])
            {
                if(cnt!=1)result+=to_string(cnt);
                result+=ss;
                ss = v[k];
                cnt = 1;
            }
        }
        if(answer==0||answer>result.length()) answer = result.length();
    }
    return answer;
}