#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int graph[1001][1001];
int DP[1001][1001];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};
int N,M;
void bfs()
{
    queue<pair<int,int>> q;
    DP[1][1]=graph[1][1];
    q.push({1,1});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<3; i++)
        {
            int X = x+dx[i];
            int Y = y+dy[i];
            if(X<1||Y<1||X>N||Y>M) continue;
            else if(DP[X][Y]==-1||DP[X][Y]<DP[x][y]+graph[X][Y])
            {
                DP[X][Y]=DP[x][y]+graph[X][Y];
                q.push({X,Y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    FOR(i,N)FOR(j,M) DP[i][j]=-1;
    bfs();
    cout << DP[N][M];
    return 0;
}