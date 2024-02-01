#include<iostream>
#include<unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int R,C;
char graph[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int used[26];
int ans = 0;
void backtracking(int x, int y, int cnt)
{
    ans = max(ans,cnt);
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1||Y<1||X>R||Y>C) continue;
        else if(used[graph[X][Y]-65]!=1)
        {
            used[graph[X][Y]-65]=1;
            backtracking(X,Y,cnt+1);
            used[graph[X][Y]-65]=0;
        }
    }
}
int main()
{
    cin >> R >> C;
    FOR(i,R)FOR(j,C) cin >> graph[i][j];
    used[graph[1][1]-65]=1;
    backtracking(1,1,1);
    cout << ans;
}