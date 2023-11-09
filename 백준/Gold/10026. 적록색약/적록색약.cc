#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N;
char graph[101][101];
int visit[101][101];
void dfs(int x,int y,char c)
{
    visit[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(visit[X][Y]!=1 && graph[X][Y]==c)
        {
            dfs(X,Y,c);
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N)
    {
        string s; cin >> s;
        FOR(j,s.length()) graph[i][j] = s[j-1]; 
    }
    int r=0;
    int rg=0;
    FOR(i,N)FOR(j,N)
    {
        if(visit[i][j]!=1)
        {
            dfs(i,j,graph[i][j]);
            r++;
        }
    }
    FOR(i,N)FOR(j,N) 
    {
        visit[i][j]=0;
        if(graph[i][j]=='G') graph[i][j]='R';
    }
    FOR(i,N)FOR(j,N)
    {
        if(visit[i][j]!=1)
        {
            dfs(i,j,graph[i][j]);
            rg++;
        }
    }
    cout << r << " " << rg;
}