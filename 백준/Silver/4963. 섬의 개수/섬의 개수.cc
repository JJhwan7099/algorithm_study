#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int graph[52][52];
int visit[52][52];
void dfs(int x, int y)
{
    visit[x][y] = 1;
    for(int i=-1;i<2;i++)for(int j=-1;j<2;j++)
    {
        int dx = x + i;
        int dy = y + j;
        if(i==0&&j==0) continue;
        else{
            if(graph[dx][dy]==1&&visit[dx][dy]==0)
            {
                dfs(dx,dy);
            }
        }
    }
}
int main()
{
    while(true)
    {
    int ans = 0;
        int y, x;
        cin >> y >> x;
        fill(&graph[0][0],&graph[51][51],-1);
        fill(&visit[0][0],&visit[51][51],0);
        if(y==0 && x==0) break;
        else{
            FOR(i,x)FOR(j,y)
            {
                cin >> graph[i][j];
            }
            FOR(i,x)FOR(j,y)
            {
                if(graph[i][j]==1 && visit[i][j]==0)
                {
                    dfs(i,j);
                    ans++;
                }
            }
            cout << ans << '\n';
        }
    }
}