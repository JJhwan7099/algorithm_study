#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
struct Robot{
    int u,d;
};
int N,M,T;
Robot robot;
int graph[51][51];
queue<pair<pair<int,int>,int>> dust;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int udx[4] = {0,-1,0,1};
int udy[4] = {1,0,-1,0};
int ddx[4] = {0,1,0,-1};
int ddy[4] = {1,0,-1,0};
void spread()
{
    int sgraph[51][51];
    FOR(i,N)FOR(j,M) sgraph[i][j] = 0;
    FOR(i,N)FOR(j,M)
    {
        if(graph[i][j]>0)
        {
            for(int k=0; k<4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<1||y<1||x>N||y>M||(y==1&&(x==robot.u||x==robot.d))) continue;
                else{
                    sgraph[x][y] += graph[i][j]/5;
                    sgraph[i][j] -= graph[i][j]/5;
                }
            }
        }
    }
    FOR(i,N)FOR(j,M) graph[i][j] += sgraph[i][j];
}
void clean()
{
    int dx1[4] = {-1,0,1,0};
    int dy1[4] = {0,1,0,-1};
    int x = robot.u;
    int y = 1;
    for(int i=0; i<4; i++)
    {
        while(x+dx1[i]>0&&y+dy1[i]>0&&x+dx1[i]<=robot.u&&y+dy1[i]<=M)
        {
            graph[x][y] = graph[x+dx1[i]][y+dy1[i]];
            x+=dx1[i];
            y+=dy1[i];
        }
    }
    x = robot.d;
    y = 1;
    for(int i=0; i<4; i++)
    {
        int save = i;
        if(i==0) i=2;
        else if(i==2) i=0;
        while(x+dx1[i]>=robot.d&&y+dy1[i]>0&&x+dx1[i]<=N&&y+dy1[i]<=M)
        {
            graph[x][y] = graph[x+dx1[i]][y+dy1[i]];
            x+=dx1[i];
            y+=dy1[i];
        }
        i=save;
    }
    graph[robot.u][2]=0;
    graph[robot.d][2]=0;
    graph[robot.u][1]=-1;
    graph[robot.d][1]=-1;
    
}
void start()
{   
    spread();
    clean();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> T;
    bool b = true;
    FOR(i,N)FOR(j,M){
        cin >> graph[i][j];
        if(b&&graph[i][j]==-1){
            robot.u = i; robot.d = i+1;
            b = false;
        }
    }
    while(T--) start();
    int ans = 0;
    FOR(i,N)FOR(j,M) if(graph[i][j]>0) ans+=graph[i][j];
    cout << ans;
    return 0;
}