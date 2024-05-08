#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M,G,R;
int board[51][51];
vector<pair<int,int>> can;
map<pair<int,int>,int> m;
stack<pair<int,int>> Gs;
stack<pair<int,int>> Rs;
int ex[51][51];
int exvisit[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;
void bfs(stack<pair<int,int>> Gs, stack<pair<int,int>> Rs) {
    queue<pair<int,int>> q;
    FOR(i,N)FOR(j,M) if(ex[i][j]!=0) q.push({i,j});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(ex[x][y]==3) continue;
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1||Y<1||X>N||Y>M||board[X][Y]==0) continue;
            else if(exvisit[x][y]+1 == exvisit[X][Y] && ex[X][Y]!=3 && ex[x][y]!=ex[X][Y]) {
                exvisit[X][Y] = exvisit[x][y] + 1;
                ex[X][Y]=3;
            }
            else if(exvisit[X][Y]==0 && ex[X][Y]==0) {
                exvisit[X][Y]=exvisit[x][y]+1;
                ex[X][Y]=ex[x][y];
                q.push({X,Y});
            } 
        }
    }   
}
int start(stack<pair<int,int>> Gs, stack<pair<int,int>> Rs) {
    int cnt = 0;
    FOR(i,N)FOR(j,M) {
        ex[i][j]=0; exvisit[i][j]=0;
    }
    while(!Gs.empty()) {
        ex[Gs.top().first][Gs.top().second]=1;
        Gs.pop();
    }
    while(!Rs.empty()) {
        ex[Rs.top().first][Rs.top().second]=2;
        Rs.pop();
    }
    bfs(Gs,Rs);
    FOR(i,N)FOR(j,M) if(ex[i][j]==3) cnt++;
    return cnt;
}
void Rbtk(int n) {
    if(Rs.size()==R) {
        ans = max(ans, start(Gs,Rs));
    }else{
        for(int i=n; i<can.size(); i++) {
            if(m[can[i]]!=1)
            {
                m[can[i]]=1;
                Rs.push(can[i]);
                Rbtk(i+1);
                Rs.pop();
                m[can[i]]=0;
            }
        }
    }
}
void Gbtk(int n) {
    if(Gs.size()==G) {
        Rbtk(0);
    }else{
        for(int i=n; i<can.size(); i++) {
            m[can[i]]=1;
            Gs.push(can[i]);
            Gbtk(i+1);
            Gs.pop();
            m[can[i]]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> G >> R;
    FOR(i,N)FOR(j,M) 
    {
        cin >> board[i][j];
        if(board[i][j]==2) can.push_back({i,j});
    }
    Gbtk(0);
    cout << ans;
    return 0;
}