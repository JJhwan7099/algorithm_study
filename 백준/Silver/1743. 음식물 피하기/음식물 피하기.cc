#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M, K;
int graph[101][101];
int visit[101][101];
int cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y)
{
    visit[x][y]=1;
    cnt++;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(visit[X][Y]!=1 && graph[X][Y]==1)
        {
            dfs(X,Y);
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    FOR(i,K)
    {
        int a,b; cin >> a >> b;
        graph[a][b] = 1;
    }
    int ans = 0;
    FOR(i,N)FOR(j,M)
    {
        if(visit[i][j]!=1 && graph[i][j]==1)
        {
            dfs(i,j);
            if(cnt > ans) ans = cnt;
            cnt = 0;
        }
    }
    cout << ans;
}