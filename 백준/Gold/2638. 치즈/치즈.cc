#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,M;
int graph[102][102];
int airvisit[102][102];
int visit[102][102];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void dfs(int x, int y)
{
    visit[x][y]=1;
    int cnt = 0;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(airvisit[X][Y]==1) 
        {
            cnt++;
        }
        else if((X>0||Y>0||X<=N||Y<=M) && graph[X][Y]==1 && visit[X][Y]!=1) dfs(X,Y);
    }
    if(cnt>1) graph[x][y] = 0;
    return;
}
void innercheck(int x, int y)
{
    airvisit[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X<0||X>N+1||Y<0||Y>M+1) continue;
        else if(graph[X][Y]==0 && airvisit[X][Y]!=1)
        {
            innercheck(X,Y);
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    int sec = 0;
    while(true)
    {
        bool check = false;
        FOR(i,N)FOR(j,M) 
        {
            visit[i][j] = 0;
            if(graph[i][j]==1) check = true;
        }
        for(int i=0;i<102;i++)for(int j=0;j<102;j++) airvisit[i][j]=0;
        if(check==false){
            cout << sec;
            return 0;
        }
        //외부 인지 판별
        innercheck(0,0);
        FOR(i,N)FOR(j,M)//치즈 제거
        {
            if(graph[i][j]==1&&visit[i][j]!=1) dfs(i,j);
        }
        sec++;
    }
}