#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M, R;
vector<int> graph[101];
int items[101];
int dis[101][101];
int cost[101];
int visit[101];
int ans = 0;
void bfs(int n)
{
    queue<pair<int,int>> q;
    q.push({n,0});
    FOR(i,100) cost[i] = -1;
    FOR(i,100) visit[i] = 0;
    cost[n] = 0;
    visit[n] = 1;
    int cnt = items[n];
    while(!q.empty())
    {
        int a = q.front().first;
        int d = q.front().second;
        for(int i=0; i<graph[a].size(); i++)
        {
            if((cost[graph[a][i]]==-1 || cost[graph[a][i]]>d+dis[a][graph[a][i]]) && M >= d+dis[a][graph[a][i]])
            {
                if(cost[graph[a][i]]==-1)
                {
                    cost[graph[a][i]] = d + dis[a][graph[a][i]];
                    q.push({graph[a][i],cost[graph[a][i]]});
                    if(cost[graph[a][i]]<=M) cnt += items[graph[a][i]];
                    continue;
                }else if(cost[graph[a][i]] > d+dis[a][graph[a][i]]) {
                    cost[graph[a][i]] = d + dis[a][graph[a][i]];
                    q.push({graph[a][i],cost[graph[a][i]]});
                    continue;
                }
            }
        }
        q.pop();
    }
    ans = max(ans,cnt);
}
int main()
{
    cin >> N >> M >> R;
    FOR(i,N) cin >> items[i];
    FOR(i,R)
    {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        dis[a][b] = c;
        dis[b][a] = c;
    }
    FOR(i,N) 
    {
        bfs(i);
    }
    cout << ans;
}
