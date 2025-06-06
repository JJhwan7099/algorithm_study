#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int board[501][501];
int visited[501][501];
vector<pair<int,pair<int,int>>> v;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
    return a.first < b.first;
}
void dfs(int x, int y) {
    vector<pair<int,pair<int,int>>> vv;
    for(int i=0; i<4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<1||Y<1||X>N||Y>N) continue;
        else if(board[X][Y]>board[x][y]) {
            vv.push_back({board[X][Y],{X,Y}});
        }
    }
    sort(vv.begin(),vv.end(),cmp);
    for(auto& a: vv) {
        int X = a.second.first;
        int Y = a.second.second;
        if(visited[X][Y]<visited[x][y]+1) {
            visited[X][Y] = visited[x][y]+1;
            dfs(X,Y);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N)FOR(j,N) {
        cin >> board[i][j];
        v.push_back({board[i][j],{i,j}});
        visited[i][j]=1;
    }
    sort(v.begin(), v.end(), cmp);
    for(auto& a: v) {
        int x = a.second.first;
        int y = a.second.second;
        if(visited[x][y]==1) {
            dfs(x,y);
        }
    }
    int result = 0;
    FOR(i,N)FOR(j,N) result = max(result,visited[i][j]);
    cout << result;
    return 0;
}