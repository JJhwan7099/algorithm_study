#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    multimap<string,string> m1;
    unordered_map<string,int> m2;
    for(auto&a:report)
    {
        string aa=""; string b="";
        int c=0;
        while(a[c]!=' ')
        {
            aa+=a[c];
            c++;
        }
        c++;
        while(c!=a.length())
        {
            b+=a[c];
            c++;
        }
        bool check = false;
        auto it = m1.lower_bound(aa);
        while(it!=m1.upper_bound(aa))
        {
            if(it->second==b) check = true;
            it++;
        }
        if(check==false) 
        {
            m1.insert({aa,b});
            if(m2[b]!=-1) m2[b]++;
            if(m2[b]>=k) m2[b]=-1;
        }
    }
    unordered_map<string,int> ans;
    for(auto&a:m1)
    {
        if(m2[a.second]==-1) ans[a.first]++;
    }
    for(auto&a:id_list) answer.push_back(ans[a]);
    return answer;
}