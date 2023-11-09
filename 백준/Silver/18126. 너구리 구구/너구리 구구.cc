#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> graph[5001];
int cost[5001][5001];
int visit[5001];
long long totcost = 0;
void dfs(int n, long long c)
{
    visit[n] = 1;
    if(c>totcost)
    {
        totcost = c;
    }
    for(int i=0; i<graph[n].size(); i++)
    {
        if(visit[graph[n][i]]!=1)
        {
            visit[graph[n][i]]=1;
            dfs(graph[n][i],c + cost[n][graph[n][i]]);
        }
    }
}
int main()
{
    cin >> N;
    for(int i=0; i<N-1; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a][b] = c; cost[b][a] = c;
    }
    dfs(1,0);
    cout << totcost;
}