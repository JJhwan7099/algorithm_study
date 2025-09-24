#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int roomCount[51][51];
int room[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs() {
    queue<pair<int,int>> q;
    q.push({1,1});
    roomCount[1][1]=0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int currentCnt = roomCount[x][y];
        // cout << x << " " << y << " " << currentCnt << endl;
        q.pop();
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1 || Y<1 || X>N || Y>N) continue;
            int haveToBlock = 0;
            if(room[X][Y]==0) haveToBlock = 1;
            if(roomCount[X][Y]==-1 || roomCount[X][Y]>currentCnt + haveToBlock) {
                roomCount[X][Y] = currentCnt + haveToBlock;
                q.push({X,Y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        string s; cin >> s;
        FOR(k,N) {
            room[i][k] = s[k-1]-'0';
            roomCount[i][k]=-1;
        }
    }
    bfs();
    // FOR(i,N) {
    //     FOR(j,N) cout << roomCount[i][j] << " ";
    //     cout << endl;
    // }
    cout << roomCount[N][N];
    return 0;
}