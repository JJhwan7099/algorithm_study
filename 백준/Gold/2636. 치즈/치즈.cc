#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int board[101][101];
int air[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int tot = 0;
int sec = 0;
void dfs(int x, int y) {
    air[x][y]=1;
    for(int i=0; i<4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1||Y<1||X>N||Y>M) continue;
        else if(air[X][Y]!=1 && board[X][Y]==0) {
            dfs(X,Y);
        }
    }
}
int melting() {
    queue<pair<int,int>> q;
    FOR(i,N)FOR(j,M) {
        if(board[i][j]==1)
        {
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<1||y<1||x>N||y>M) continue;
                else if(air[x][y]==1) {
                    q.push({i,j});
                    break;
                }
            }
        }
    }
    int cnt = q.size();
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if(air[x][y]!=1) dfs(x,y);
        board[x][y]=0;
        q.pop();
    }
    return cnt;
}
void start() {
    int cnt = 0;
    int prevcnt = tot-cnt;
    while(cnt!=tot) {
        prevcnt = tot-cnt;
        cnt+=melting();
        sec++;
    }
    cout << sec << '\n' << prevcnt;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)FOR(j,M) {
        cin >> board[i][j];
        if(board[i][j]==1) tot++;
    }
    dfs(1,1);
    start();
    return 0;
}