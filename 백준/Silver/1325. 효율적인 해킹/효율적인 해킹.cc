#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N; i++)
int N,M;
vector<int> graph[10001];
int visit[10001];
int cnt=0;
vector<pair<int,int>> ans;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
void dfs(int n)
{
    visit[n] = 1;
    cnt++;
    for(int i=0; i<graph[n].size(); i++)
    {
        if(visit[graph[n][i]]!=1)
        {
            dfs(graph[n][i]);
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,M)
    {
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }
    FOR(i,N)
    {
        if(visit[i]!=1) 
        {
            dfs(i);
            ans.push_back({i,cnt});
            cnt=0;
            FOR(j,N) visit[j] = 0;
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    int max = ans[0].second;
    for(auto&a:ans)
    {
        if(a.second == max) cout << a.first << " ";
        else break;
    }
}