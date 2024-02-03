#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[101];
int cost[101][101];
int totcost[101][101];
int N, M;
void bfs(int s)
{
    for(int i=1; i<=N; i++) totcost[s][i]=-100;
    totcost[s][s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        for(int i=0; i<v[n].size(); i++)
        {
            if(totcost[s][v[n][i]]==-100||totcost[s][v[n][i]]>totcost[s][n]+cost[n][v[n][i]])
            {
                totcost[s][v[n][i]] = totcost[s][n] + cost[n][v[n][i]];
                q.push(v[n][i]);
            }
        }
    }
    for(int i=1; i<=N; i++) if(totcost[s][i]==-100) totcost[s][i]=0;
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back(e);
        if(cost[s][e]==0||cost[s][e]>c) cost[s][e] = c;
    }
    for(int i=1; i<=N; i++) bfs(i);
    for(int i=1; i<=N; i++){for(int j=1; j<=N; j++) cout << totcost[i][j] << " "; cout << '\n';}
}