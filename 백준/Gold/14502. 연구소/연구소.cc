#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[10][10];
int check[10][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;
void dfs(int x, int y)
{
    check[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1 || Y<1 || X>N || Y>M) continue;
        if(graph[X][Y]==0 && check[X][Y] == 0)
        {
            dfs(X,Y);
        }else if(graph[X][Y]==1 && check[X][Y]!=1) 
        {
            check[X][Y] = 1;
        }
    }
}
int main()
{
    cin >> N >> M;
    fill(&graph[0][0],&graph[9][9],-1);
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    FOR(x1,N)FOR(x2,N)FOR(x3,N)FOR(y1,M)FOR(y2,M)FOR(y3,M)
    {
        if((x1==x2&&y1==y2)||(x1==x3&&y1==y3)||(x2==x3&&y2==y3))
        {
            continue;
        }else if(graph[x1][y1]!=0 || graph[x2][y2]!=0 || graph[x3][y3]!=0){
            continue;
        }
        fill(&check[0][0],&check[9][9],0);
        //바이러스 퍼짐
        check[x1][y1] = 1;
        check[x2][y2] = 1;
        check[x3][y3] = 1;
        FOR(i,N)FOR(j,M)
        {
            if(graph[i][j]==2)
            {
                dfs(i,j);
            }else if(graph[i][j]==1)
            {
                check[i][j] = 1;
            }
        }
        int area = 0;
        FOR(i,N)FOR(j,M)
        {
            if(check[i][j]==0) area++;
        }
        if(area>ans) 
        {
            ans = area;
        }
    }
    cout << ans;
}