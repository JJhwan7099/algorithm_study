#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int N,M;
char grid[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int vis[101][101];
void dfs(int x, int y)
{
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1||Y<1||X>N||Y>M||vis[X][Y]==1) continue;
        else if(grid[X][Y]=='#') dfs(X,Y);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        FOR(i,N)FOR(j,M) {
            cin >> grid[i][j];
            vis[i][j]=0;
        }
        int ans = 0;
        FOR(i,N)FOR(j,M)
        {
            if(vis[i][j]!=1&&grid[i][j]=='#')
            {
                ans++;
                dfs(i,j);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}