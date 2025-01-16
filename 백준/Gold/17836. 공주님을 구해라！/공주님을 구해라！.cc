#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
#define X first 
#define Y second
int N,M,T;
int map[101][101];
pair<int,int> swordPosition;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dis[101][101];
int bfs(pair<int,int> start, pair<int,int> end, bool Sword) {
    FOR(i,N)FOR(j,M) dis[i][j]=-1;
    queue<pair<pair<int,int>,bool>> q;
    dis[start.X][start.Y]=0;
    q.push({start,Sword});
    while(!q.empty()) {
        int x = q.front().X.X;
        int y = q.front().X.Y;
        bool sword = q.front().Y;
        q.pop();
        if(x==end.X && y==end.Y){
            return dis[x][y];
        }
        if(dis[x][y]>=T) continue;
        for(int i=0; i<4; i++) {
            int moveX = x+dx[i];
            int moveY = y+dy[i];
            if(moveX<1||moveY<1||moveX>N||moveY>M) continue;
            else{
                if(map[moveX][moveY]!=1 && (dis[moveX][moveY]==-1 || dis[moveX][moveY]>dis[x][y]+1)){
                    dis[moveX][moveY]=dis[x][y]+1;
                    q.push({{moveX,moveY},sword});
                }
                if(map[moveX][moveY]==1  && sword && (dis[moveX][moveY]==-1 || dis[moveX][moveY]>dis[x][y]+1)) {
                    dis[moveX][moveY]=dis[x][y]+1;
                    q.push({{moveX,moveY},sword});
                }
            }
        }
    }
    return dis[end.X][end.Y];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> T;
    FOR(i,N) FOR(j,M) {
        cin >> map[i][j];
        if(map[i][j]==2) swordPosition={i,j};
    }
    int manToGirl = bfs({1,1},{N,M},false);
    int manToSword = bfs({1,1},swordPosition,false);
    int swordToGirl = bfs(swordPosition,{N,M},true);
    
    int ans=-1;
    if(manToGirl>0 && manToSword>0 && swordToGirl>0) ans = min(manToGirl,manToSword+swordToGirl);
    else if(manToGirl<0 && manToSword>0 && swordToGirl>0) ans=manToSword+swordToGirl;
    else if(manToGirl>0 && (manToSword<0 || swordToGirl<0)) ans=manToGirl;
    
    if(ans>0 && ans<=T) cout << ans;
    else cout << "Fail";
    
    return 0;
}