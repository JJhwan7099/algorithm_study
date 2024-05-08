#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int R,C;
char board[10001][501];
int vis[10001][501];
int dx[3] = {-1,0,1};
int cnt = 0;
queue<pair<int,int>> q;
bool dfs(int x, int y) {
    q.push({x,y});
    vis[x][y]=1;
    if(y==C) return true;
    for(int i=0; i<3; i++) {
        int X = x + dx[i];
        int Y = y + 1;
        if(X<1||Y<1||X>R||Y>C) continue;
        else if(vis[X][Y]!=1 && board[X][Y]=='.') {
            if(dfs(X,Y)) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>R >> C;
    int cnt = 0;
    FOR(i,R)FOR(j,C) cin >> board[i][j]; 
    FOR(i,R) if(dfs(i,1)) cnt++;
    cout << cnt;
    return 0;
}