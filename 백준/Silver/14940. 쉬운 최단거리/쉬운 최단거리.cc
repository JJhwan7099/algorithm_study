#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[1001][1001];
int visit[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y, int dis)
{
    visit[x][y] = dis;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>N||Y>M||X<1||Y<1||graph[X][Y]==2||graph[X][Y]==0) continue;
        else if(visit[X][Y]==-1)
        {
            dfs(X,Y,dis+1);
        }
    }
}
void bfs(int x, int y)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visit[x][y]=0;
    while(!q.empty())
    {
        pair<int,int> xy = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X = xy.first + dx[i];
            int Y = xy.second + dy[i];
            if(X<1||Y<1||X>N||Y>M) continue;
            else if(visit[X][Y]==-1 && graph[X][Y]==1)
            {
                q.push({{X,Y},dis+1});
                visit[X][Y] = dis+1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int tx,ty;
    FOR(i,N)FOR(j,M) 
    {
        cin >> graph[i][j];
        visit[i][j]=-1;
        if(graph[i][j]==2)
        {
            tx = i; ty = j;
        }else if(graph[i][j]==0) visit[i][j] = 0;
    }
    // dfs(tx,ty,0);
    bfs(tx, ty);
    FOR(i,N){FOR(j,M) cout << visit[i][j] << " "; cout << '\n';}
    return 0;
}