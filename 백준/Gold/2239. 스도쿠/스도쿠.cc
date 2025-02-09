#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int board[10][10];
int zeroCnt = 0;
vector<pair<int,int>> zeroPoint;
map<int,int> width[10];
map<int,int> height[10];
map<int,int> box[10];
bool endCheck = false;
vector<int> findNumber(int x, int y) {
    vector<int> usableNumbers;
    FOR(i,9) if(width[x][i]!=1 && height[y][i]!=1 && box[(x-1)/3*3+(y-1)/3+1][i]!=1) usableNumbers.push_back(i);
    return usableNumbers;
}
void start(int n) {
    if(endCheck) return;
    if(n==zeroPoint.size()) {
        FOR(i,9) {
            FOR(j,9) cout << board[i][j];
            cout << '\n';
        }
        endCheck = true;
        return;
    }
    for(int i=n; i<zeroPoint.size(); i++) {
        int x = zeroPoint[i].first;
        int y = zeroPoint[i].second;
        vector<int> usableNumbers = findNumber(x,y);
        for(auto&num: usableNumbers) {
            board[x][y] = num;
            width[x][num] = 1;
            height[y][num] = 1;
            box[(x-1)/3*3+(y-1)/3+1][num] = 1;
            start(i+1);
            board[x][y] = 0;
            width[x][num] = 0;
            height[y][num] = 0;
            box[(x-1)/3*3+(y-1)/3+1][num] = 0;
        }
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i,9) {
        string line; cin >> line;
        FOR(j,9) {
            board[i][j] = line[j-1]-'0';
            if(board[i][j]==0) {
                zeroPoint.push_back({i,j});
                zeroCnt++;
            }
            width[i][board[i][j]] = 1;
            height[j][board[i][j]] = 1;
            box[(i-1)/3*3+(j-1)/3+1][board[i][j]] = 1;
            // cout << (i-1)/3*3+(j-1)/3+1 << endl;
        }
    }
    start(0);
    return 0;
}