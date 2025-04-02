#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int board[4][4];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
unordered_map<string,int> board_map;
void printBoard(int board[][4]) {
    FOR(i,3) {
        FOR(j,3) cout << board[i][j] << " ";
        cout << endl;
    }
}
string boardToString(int board[][4]) {
    string str = "";
    FOR(i,3)FOR(j,3) str += to_string(board[i][j]);
    return str;
}
int bfs() {
    queue<pair<string,int>> q;
    q.push({boardToString(board),0});
    board_map[boardToString(board)] = 1;
    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == "123456780") return cnt;
        int tempBoard[4][4];
        FOR(i,3)FOR(j,3) tempBoard[i][j] = cur[(i-1)*3+j-1]-'0';
        FOR(i,3)FOR(j,3) {
            if(tempBoard[i][j] == 0) {
                for(int k=0; k<4; k++){
                    int X = i + dx[k];
                    int Y = j + dy[k];
                    if(X<1||Y<1||X>3||Y>3) continue;
                    else {
                        // cout << "before swap" << endl;
                        // printBoard(tempBoard);
                        swap(tempBoard[i][j], tempBoard[X][Y]);
                        string next = boardToString(tempBoard);
                        if(board_map.find(next)==board_map.end()) {
                            board_map[next] = 1;
                            q.push({next,cnt+1});
                        }
                        // cout << "after swap" << endl;
                        // printBoard(tempBoard);
                        swap(tempBoard[i][j], tempBoard[X][Y]);
                    }
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i,3)FOR(j,3) cin >> board[i][j];
    cout << bfs();
    return 0;
}