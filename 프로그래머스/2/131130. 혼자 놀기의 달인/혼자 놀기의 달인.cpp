#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int visit[101];
int cnt=0;
void dfs(int n,const vector<int>& v)
{
    visit[n]=1;
    cnt++;
    if(visit[v[n-1]]!=1) dfs(v[n-1],v);
}
int solution(vector<int> cards) {
    vector<int> v;
    for(auto&a:cards)
    {
        if(visit[a]!=1) dfs(a,cards);
        if(cnt!=0)v.push_back(cnt);
        cnt=0;
    }
    sort(v.begin(),v.end());
    if(v.size()>1) return v[v.size()-1]*v[v.size()-2];
    else return 0;
}