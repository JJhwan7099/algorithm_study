#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>>v;
    vector<int> vv;
    string ss = "";
    for(int i=1; i<s.length()-1; i++)
    {
        if(s[i]=='{') ss="";
        else if(s[i]=='}') 
        {
            vv.push_back(stoi(ss));
            v.push_back(vv);
            vv.clear();
        }
        else if(s[i-1]!='}'&&s[i]==',')
        {
            vv.push_back(stoi(ss));
            ss="";
        }
        else if(s[i]!=',' && s[i]!='{' && s[i]!='}'){
            ss+=s[i];
        }
    }
    sort(v.begin(), v.end(), cmp);
    unordered_map<int,int> m;
    for(auto&a:v)
    {
        for(auto&b:a)
        {
            if(m[b]!=1)
            {
                m[b]=1;
                answer.push_back(b);
            }
        }
    }
    return answer;
}