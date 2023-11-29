#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, E;
vector<int> graph[801];
int cost[801][801];
int totcost[4][801];
int v1, v2;
int ans = -1;
void bfs()
{
    queue<pair<int,pair<int,int>>> q;
    if(1!=v1 && 1!=v2) q.push({1,{0,0}});
    else if(1==v1 && 1!=v2) q.push({1,{1,0}});
    else if(1!=v1 && 1==v2) q.push({1,{0,2}});
    else q.push({1,{1,2}});
    while(!q.empty())
    {
        int a = q.front().first;
        int v1c = q.front().second.first;
        int v2c = q.front().second.second;
        if(v1c==1 && v2c==2 && a==N)
        {
            ans = totcost[3][N];
        }
        for(int i=0; i<graph[a].size(); i++)
        {
            int c1c = v1c;
            int c2c = v2c;
            if(graph[a][i]==v1) c1c=1;
            else if(graph[a][i]==v2) c2c=2;
            if(totcost[c1c+c2c][graph[a][i]]==-1 || totcost[c1c+c2c][graph[a][i]] > totcost[v1c+v2c][a]+cost[a][graph[a][i]])
            {
                totcost[c1c+c2c][graph[a][i]] = totcost[v1c+v2c][a]+cost[a][graph[a][i]];
                q.push({graph[a][i],{c1c,c2c}});
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N >> E;
    FOR(i,E)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a][b] = c;
        cost[b][a] = c;
    }
    cin >> v1 >> v2;
    FOR(i,N)for(int j=0;j<4;j++) totcost[j][i] = -1;
    totcost[0][1] = 0;
    if(1!=v1 && 1!=v2) totcost[0][1]=0;
    else if(1==v1 && 1!=v2) totcost[1][1]=0;
    else if(1!=v1 && 1==v2) totcost[2][1]=0;
    else totcost[3][1]=0;
    bfs();
    cout << ans;
}