#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M,N;
int graph[251][251];
int visited[251][251];
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,-1,0,1,-1,0,1};
int result = 0;
void dfs(int x, int y) {
    visited[x][y] = 1;
    for(int i=0; i<8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1||Y<1||X>M||Y>N||visited[X][Y]==1||graph[X][Y]==0) continue;
        else dfs(X,Y);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    FOR(i,M)FOR(j,N) {
        cin >> graph[i][j];
    }
    FOR(i,M)FOR(j,N) {
        if(visited[i][j]!=1 && graph[i][j]==1) {
            dfs(i,j);
            result++;
        }
    }
    cout << result << '\n';
    return 0;
}