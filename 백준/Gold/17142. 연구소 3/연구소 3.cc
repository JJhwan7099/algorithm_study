#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int board[51][51];
int vis[51][51];
int vis2[51][51];
vector<pair<int,int>> virus;
vector<pair<int,int>> viruspos;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = -1;
int check() {
    int cnt = 0;
    FOR(i,N)FOR(j,N) {
        if(board[i][j]==0) {
            cnt++;
        }
    }
    return cnt;
}
void spread(queue<pair<int,int>>& ex, int& zerocnt) {
    int s = ex.size();
    while(s--) {
        int x = ex.front().first;
        int y = ex.front().second;
        ex.pop();
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1||Y<1||X>N||Y>N||board[X][Y]==1) continue;
            else if(vis2[X][Y]!=1) {
                ex.push({X,Y});
                vis2[X][Y]=1;
                if(board[X][Y]==0) zerocnt++;
            }
        }
    }
}
int start() {
    int sec = 0;
    queue<pair<int,int>> ex;
    int zerocnt = 0;
    for(auto&a: viruspos) {
        vis2[a.first][a.second]=1;
        ex.push(a);
    }
    int checkcnt = check();
    while(ex.size()>0 && zerocnt<checkcnt) {
        int a = zerocnt;
        spread(ex,zerocnt);  
        if(zerocnt<=checkcnt) {
            sec++;
        }
    }
    if(checkcnt==zerocnt) return sec;
    else return -1;
}
void btk(int n, int cnt) {
    if(cnt==M) {
        FOR(i,N)FOR(j,N) vis2[i][j]=0;
        int cnt = start();
        if(ans==-1 || (cnt!=-1 && ans>cnt)) ans = cnt;
        return;
    }
    else {
        for(int i=n; i<virus.size(); i++) {
            if(vis[virus[i].first][virus[i].second]!=1) {
                vis[virus[i].first][virus[i].second]=1;
                viruspos.push_back(virus[i]);
                btk(i+1, cnt+1);
                viruspos.pop_back();
                vis[virus[i].first][virus[i].second]=0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)FOR(j,N) {
        cin >> board[i][j];
        if(board[i][j]==2) virus.push_back({i,j});
    }
    btk(0, 0);
    cout << ans;
    return 0;
}