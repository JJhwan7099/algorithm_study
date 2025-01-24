#include <iostream>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int R,C,N;
char board[201][201];
map<pair<int,int>,int> Bomb;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int nowTime = 0;
void setBomb() {
    FOR(i,R) FOR(j,C) {
        if(board[i][j] == '.') {
            Bomb[{i,j}] = nowTime;
            board[i][j] = 'O';
        }
    }
}
void startBomb() {
    for(auto&bomb:Bomb) {
        if(bomb.second == nowTime - 3) {
            board[bomb.first.first][bomb.first.second] = '.';
            for(int i=0; i<4; i++) {
                int X = bomb.first.first + dx[i];
                int Y = bomb.first.second + dy[i];
                if(X<1||Y<1||X>R||Y>C) continue;
                else if(board[X][Y] == 'O') {
                    board[X][Y] = '.';
                }
            }
        }
    }
}

void start() {
    while(1) {
        if(nowTime == N) break;
        nowTime++;
        setBomb();
        if(nowTime == N) break;
        nowTime++;
        startBomb();
        if(nowTime == N) break;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> N;
    FOR(i,R) FOR(j,C) {
        cin >> board[i][j];
        if(board[i][j] == 'O') {
            Bomb[{i,j}] = nowTime;
        }
    }
    nowTime++;
    start();
    FOR(i,R){
        FOR(j,C) cout << board[i][j];
        cout << '\n';
    }
    return 0;
}