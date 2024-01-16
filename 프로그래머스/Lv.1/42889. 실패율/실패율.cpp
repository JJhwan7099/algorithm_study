#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<double,int>a,pair<double,int>b)
{
    if(a.first!=b.first) return a.first>b.first;
    else return a.second<b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int,int> m; //스테이지에 도달했으나 클리어하지 못한 플레이어
    unordered_map<int,int> m1; //스테이지에 도달한 플레이어 수
    for(auto&a : stages)
    {
        if(a!=N+1)
        {
            m[a]++;
            for(int i=1; i<=a; i++) m1[i]++;
        }else{
            for(int i=1; i<a; i++) m1[i]++;
        }
    }
    vector<pair<double,int>> v;
    
    for(int i=1; i<=N; i++)
    {
        if(m1[i]==0)v.push_back({0,i});
        else v.push_back({m[i]*1.0/m1[i],i});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto&a:v) answer.push_back(a.second);
    return answer;
}