#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int board[1001][1001];
int visit[1001][1001];
int day;
bool check = false;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void start(const vector<pair<int,int>>& v)
{
    queue<pair<pair<int,int>,int>> q;
    for(auto& a: v) 
    {
        q.push({a,0});
    }
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        day = q.front().second;
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<1||Y<1||X>N||Y>M) continue;
            else if(board[X][Y]==0){
                board[X][Y]=1;
                q.push({{X,Y},q.front().second+1});
            }
        }
        q.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> v;
    cin >> M >> N;
    FOR(i,N)FOR(j,M) 
    {
        cin >> board[i][j];
        if(board[i][j]==1)v.push_back({i,j});
    }
    start(v);
    FOR(i,N)FOR(j,M)
    {
        if(board[i][j]==0)
        {
            cout << -1;
            return 0;
        }
    }
    cout << day;
    return 0;
}