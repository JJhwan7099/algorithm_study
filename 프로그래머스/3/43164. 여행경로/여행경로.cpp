#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int N;
vector<vector<string>> result;
bool cmp(const vector<string>& a, const vector<string>& b)
{
    string aa = "";
    string bb = "";
    for(int i=0; i<a.size(); i++)
    {
        aa+=a[i];
        bb+=b[i];
    }
    return aa<bb;
}
void dfs(string a, vector<string> route, map<string,int> m,map<string,vector<string>> mm)
{
    route.push_back(a);
    if(route.size()==N+1)
    {
        result.push_back(route);
        return;
    }
    else{
        for(int i=0; i<mm[a].size(); i++)
        {
            if(m[a+mm[a][i]]!=0)
            {
                m[a+mm[a][i]]--;
                dfs(mm[a][i],route,m,mm);
                m[a+mm[a][i]]++;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    map<string,vector<string>> m;
    N = tickets.size();
    vector<string> v;//경로 저장할 벡터
    map<string,int> m1;//사용한 티켓인지 확인할 맵
    for(auto& a: tickets)
    {
        m[a[0]].push_back(a[1]);
        m1[a[0]+a[1]]++;
    }
    dfs("ICN",v,m1,m);
    sort(result.begin(),result.end(),cmp);
    return result[0];
}