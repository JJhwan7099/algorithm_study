#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int M,N;
int graph[1005][1005];
int check = false;
void dfs(int x, int y)
{
    if(x==M)
    {
        check = true;
        return;
    }
    graph[x][y] = 2;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for(int i=0; i<4; i++)
    {
        int X,Y;
        X = x + dx[i];
        Y = y + dy[i];
        if(graph[X][Y] == 1)
        {
            dfs(X,Y);
        }
    }
}
int main()
{
    cin >> M >> N;
    FOR(i,M)FOR(j,N)
    {
        char a; cin >> a;
        graph[i][j] = a - 47;
    }
    FOR(i,N)
    {
        if(graph[1][i]==1)
            dfs(1,i);
    }
    if(check == true)
    {
        cout << "YES";
    }else{
        cout << "NO";
    }
}