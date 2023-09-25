#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int graph[51][51];
void print(int x,int y)
{
    cout << "start\n";
    FOR(i,x) {FOR(j,y) cout << graph[i][j]; cout << endl;}
    cout << "end\n";
}
void dfs(int x, int y)
{
    graph[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(graph[X][Y]==1)
        {
            dfs(X,Y);
        }
    }
}
int main()
{
    vector<int> ans;
    cin >> T;
    FOR(i,T)
    {
        fill(&graph[0][0],&graph[50][50],0);
        int x,y,n; cin >> y >> x >> n;
        int cnt = 0;
        FOR(j,n)
        {
            int a, b; cin >> a >> b;
            graph[b+1][a+1] = 1;
        }
        FOR(j,x) FOR(k,y)
        {
            if(graph[j][k]==1)
            {
                dfs(j,k);
                cnt++;
            }
        }
        ans.push_back(cnt);
    }
    for(auto&a : ans) cout << a << '\n';
}