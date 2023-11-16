#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N, M;
int graph[102][72];
int visit[102][72];
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
bool check = true;
int cnt=0;
void dfs(int X, int Y)
{
    visit[X][Y]=1;
    for(int i=0; i<8; i++)
    {
        int x = X + dx[i];
        int y = Y + dy[i];
        if(x>N||y>M||x<1||y<1) continue;
        else if(graph[x][y]==graph[X][Y] && visit[x][y]!=1) dfs(x,y);
        else if(graph[x][y]>graph[X][Y]){
            check = false;
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,M) 
    {
        cin >> graph[i][j];
    }
    FOR(i,N)FOR(j,M) visit[i][j]=0;
    FOR(i,N)FOR(j,M)
    {
        if(visit[i][j]!=1)
        {
            check = true;
            dfs(i,j);
            if(check==true) cnt++;
        }
    }
    cout << cnt;
}