#include<iostream>
#define FOR(i,N) for(int i=1; i<=N; i++)
using namespace std;
int n,m;
int graph[501][501];
int visit[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cnt = 0;
int area = 0;
int dfs(int x, int y, int cnt)
{
    visit[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(graph[X][Y]==1 && visit[X][Y]!=1)
        {
            area += dfs(X,Y,cnt+1);
        }
    }
    return 1;
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    FOR(i,n)FOR(j,m) cin >> graph[i][j];
    FOR(i,n)FOR(j,m)
    {
        if(visit[i][j]!=1 && graph[i][j]==1)
        {
            area = 1;
            dfs(i,j,1);
            cnt++;
            if(ans==0 || ans < area) ans = area;
        }
    }
    cout << cnt << '\n';
    cout << ans;
}