#include<iostream>
#include<unordered_map>
#include<string>
#include<queue>

using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N, M;
int graph[501][501];
int DP[501][501];
int cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y)
{
    if(x==N&&y==M)
    {
        return 1;
    }else if(DP[x][y]!=-1)
    {
        return DP[x][y];
    }
    else{
        DP[x][y]=0;
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1||X>N||Y<1||Y>M) continue;
            if(graph[X][Y]<graph[x][y])
            {
                DP[x][y] += dfs(X,Y);
            }
        }
    }
    return DP[x][y];
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    FOR(i,N)FOR(j,M) DP[i][j]=-1;
    dfs(1,1);
    cout << DP[1][1];
}