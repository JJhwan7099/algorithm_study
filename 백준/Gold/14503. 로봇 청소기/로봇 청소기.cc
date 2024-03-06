#include<iostream>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int x1, y1, DIR;
int graph[51][51];
int visit[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
map<int,pair<int,int>> m;
void start(int x, int y, int dir);
bool check(int x, int y)
{
    if(graph[x][y]==1) return false;
    else if(visit[x][y]==0) return true;
}
void goback(int x, int y, int dir)
{
    int X = x+m[(dir+2)%4].first;
    int Y = y+m[(dir+2)%4].second;
    if(X<1||Y<1||X>N||Y>M) return;
    if(graph[X][Y]==0){
        start(X,Y,dir);
    }
}
void gofront(int x, int y, int dir, bool& b)
{
    int X = x+m[dir].first;
    int Y = y+m[dir].second;
    if(X<1||Y<1||X>N||Y>M) return;
    if(graph[X][Y]==0&&visit[X][Y]==0){
        b=true;
        start(X,Y,dir);
    }
}
void rotate(int& dir)
{
    dir=(dir+3)%4;
}
void start(int x, int y, int dir)
{
    if(check(x,y)) visit[x][y]=1;
    bool b = false;
    for(int i=0; i<4; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X<1||Y<1||X>N||Y>M) continue;
        if(graph[X][Y]==0&&visit[X][Y]==0)
        {
            b=true;
            break;
        }
    }
    if(!b){
        goback(x,y,dir);
    }else{
        for(int i=0; i<4; i++)
        {
            bool bb = false;
            rotate(dir);
            gofront(x,y,dir,bb);
            if(bb) break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cin >> x1 >> y1 >> DIR;
    for(int i=0; i<4; i++) m[i] = {dx[i],dy[i]};
    int ans=0;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    start(x1+1,y1+1, DIR);
    FOR(i,N)FOR(j,M) if(visit[i][j]==1) ans++;
    cout << ans;
    return 0;
}