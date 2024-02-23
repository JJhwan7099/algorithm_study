#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M,N,H;
int board[101][101][101];
int visit[101][101][101];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int day=0;
void start(queue<pair<pair<int,int>,pair<int,int>>>& q)
{
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int h = q.front().second.first;
        int d = q.front().second.second;
        day = d;
        q.pop();
        for(int i=0; i<6; i++)
        {
            int X = x+dx[i];
            int Y = y+dy[i];
            int HH = h+dz[i];
            if(X<1||Y<1||HH<1||X>N||Y>M||HH>H) continue;
            if(board[X][Y][HH]==0) 
            {
                board[X][Y][HH]=1;
                q.push({{X,Y},{HH,d+1}});
            }
        }
    }
}
bool check()
{
    FOR(k,H)FOR(i,N)FOR(j,M) if(board[i][j][k]==0) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> H;
    map<pair<pair<int,int>,int>,int> m;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    FOR(k,H) FOR(i,N)FOR(j,M)
    {
        cin >> board[i][j][k];
        if(board[i][j][k]==1) q.push({{i,j},{k,0}});
    }
    start(q);
    if(check()){
        cout << -1;
        return 0;
    }
    cout << day;
    return 0;
}