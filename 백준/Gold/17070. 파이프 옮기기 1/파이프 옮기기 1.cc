#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int graph[17][17];
int cnt = 0;
void dfs(int x1, int y1, int x2, int y2)
{
    
    if(x1<1 || x1>N || y1<1 || y1>N || x2<1 || x2>N || y2<1 || y2>N || graph[x1][y1]==1 || graph[x2][y2]==1)
    {
        return;
    }
    else if((x1==N && y1==N)||(x2==N && y2==N))
    {
        cnt++;
        return;
    }
    else{
        if(x1==x2 && y1!=y2)
        {
            int X1 = x1; int Y1 = y1;
            int X2 = x2; int Y2 = y2;
            dfs(X1,Y1+1,X2,Y2+1);
            if(graph[x2+1][y2]!=1&&graph[x2][y2+1]!=1) dfs(X2,Y2,X2+1,Y2+1);
        }
        else if(x1!=x2 && y1==y2)
        {
            dfs(x2,y2,x2+1,y2);
            if(graph[x2+1][y2]!=1&&graph[x2][y2+1]!=1) dfs(x2,y2,x2+1,y2+1);
        }
        else
        {
            dfs(x2,y2,x2,y2+1);
            if(graph[x2+1][y2]!=1&&graph[x2][y2+1]!=1) dfs(x2,y2,x2+1,y2+1);
            dfs(x2,y2,x2+1,y2);
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    dfs(1,1,1,2);
    cout << cnt;
}