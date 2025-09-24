#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int board[21][21]; // 벽 2, 바깥 0, 길 1
int visited[21][21][21][21];
int xx1,yy1,xx2,yy2;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
queue<pair<pair<int,int>,pair<int,int>>> q;
bool isOutside(int x, int y) {
    if(x<1 || y<1 || x>N || y>M) return true;
    return false;
}
int start() {
    while(!q.empty()) {
        int x1 = q.front().first.first;
        int y1 = q.front().first.second;
        int x2 = q.front().second.first;
        int y2 = q.front().second.second;
        int currentDepth = visited[x1][y1][x2][y2];
        q.pop();
        // cout << "start\n";
        // FOR(i,N){
        //     FOR(j,M) {
        //         if(board[i][j]==2) cout << "#";
        //         else if(board[i][j]==1) {
        //             if((i==x1 && j==y1) || (i==x2 && j==y2)) {
        //                 cout << "o";
        //             }
        //             else cout << ".";
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if(currentDepth==10) continue;
        for(int i=0; i<4; i++) {
            int X1 = x1 + dx[i];
            int Y1 = y1 + dy[i];
            int X2 = x2 + dx[i];
            int Y2 = y2 + dy[i];
            if(board[X1][Y1]==2) {
                X1 -= dx[i];
                Y1 -= dy[i];
            }
            if(board[X2][Y2]==2) {
                X2 -= dx[i];
                Y2 -= dy[i];
            }
            // cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << '\n';
            // cout << isOutside(X1,Y1) << " " << isOutside(X2,Y2) << '\n';
            // cout << visited[X1][Y1][X2][Y2] << ' ' << visited[X2][Y2][X1][Y1] << '\n';
            if(isOutside(X1,Y1) && !isOutside(X2,Y2)) return currentDepth+1;
            else if(!isOutside(X1,Y1) && isOutside(X2,Y2)) return currentDepth+1;
            else if(isOutside(X1,Y1) && isOutside(X2,Y2)) continue;
            else {
                if(visited[X1][Y1][X2][Y2]==-1 && visited[X2][Y2][X1][Y1]==-1) {
                    // cout  << "go1\n";
                    visited[X1][Y1][X2][Y2]=currentDepth+1;
                    visited[X2][Y2][X1][Y1]=currentDepth+1;
                    q.push({{X1,Y1},{X2,Y2}});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(a,N)FOR(b,M)FOR(c,N)FOR(d,M) {
        visited[a][b][c][d] = -1;
        // visited[c][d][a][b] = -1;
    }
    FOR(i,N) {
        FOR(j,M) {
            char a; cin >> a;
            if(a=='.') board[i][j] = 1;
            else if(a=='#') board[i][j] = 2;
            else if(a=='o') {
                board[i][j] = 1;
                if(xx1==0) {
                    xx1 = i;
                    yy1 = j;
                }
                else {
                    xx2 = i;
                    yy2 = j;
                }
            }
        }
    }
    q.push({{xx1,yy1},{xx2,yy2}});
    visited[xx1][yy1][xx2][yy2] = 0;
    visited[xx2][yy2][xx1][yy1] = 0;
    cout << start();
    return 0;
}