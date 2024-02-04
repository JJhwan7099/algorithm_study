#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M,V;
vector<int> graph[1001];
int visit[1001];
void dfs(int n)
{
    visit[n] = 1;
    cout << n << ' ';
    for(int i=0; i<graph[n].size(); i++)
    {
        if(visit[graph[n][i]]!=1) dfs(graph[n][i]);
    }
}
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visit[n] = 1;
    while(!q.empty())
    {
        int s = q.front();
        cout << s << ' ';
        q.pop();
        for(int i=0; i<graph[s].size(); i++)
        {
            if(visit[graph[s][i]]!=1)
            {
                visit[graph[s][i]]=1;
                q.push(graph[s][i]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V;
    FOR(i,M)
    {
        int s,e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    FOR(i,N) sort(graph[i].begin(),graph[i].end());
    dfs(V);
    cout << '\n';
    FOR(i,N) visit[i] = 0;
    bfs(V);
    return 0;
}