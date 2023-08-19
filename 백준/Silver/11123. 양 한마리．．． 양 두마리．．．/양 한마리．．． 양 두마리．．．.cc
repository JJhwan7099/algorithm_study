#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int graph[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y)
{
    graph[x][y] = -1;
    int X,Y;
    for(int i=0; i<4; i++)
    {
        X = x + dx[i];
        Y = y + dy[i];
        if(graph[X][Y] == 1) dfs(X,Y);
    }
}
int main()
{
    int T;
    cin >> T;
    vector<int> ans;
    for(int k=0; k<T; k++)
    {
        int result = 0;
        fill(&graph[0][0],&graph[101][101],-1);
        int x,y; cin >> x >> y;
        FOR(i,x)FOR(j,y) // 양이 1 풀숲이 0
        {
            char a; cin >> a;
            if(a=='#') graph[i][j] = 1;
        }
        //dfs
        FOR(i,x)FOR(j,y)
        {
            
            if(graph[i][j]==1)
            {
                dfs(i,j);
                result++;
            }
        }
        ans.push_back(result);
    }
    for(auto&a : ans) cout << a << '\n';
}