#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N; i++)
int M,N;
int graph[101][101];
int cost[101][101];
int cnt = -1;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs()
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},0});
    FOR(i,N)FOR(j,M) cost[i][j]=-1;
    cost[1][1] = 0;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if(x==N&&y==M)
        {
            if(cnt==-1||cnt>c) cnt = c;
        }
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if(X<1||X>N||Y<1||Y>M) continue;
            else if(graph[X][Y]==1){
                if(cost[X][Y]==-1||cost[X][Y]>c+1)
                {
                    cost[X][Y] = c+1;
                    q.push({{X,Y},c+1});
                }
            }else{
                if(cost[X][Y]==-1||cost[X][Y]>c)
                {
                    cost[X][Y] = c;
                    q.push({{X,Y},c});
                }
            }
        }
    }
}
int main()
{
    cin >> M >> N;
    FOR(i,N){
        string s; cin >> s;
        FOR(j,M) graph[i][j] = s[j-1] - '0';
    }
    bfs();
    cout << cnt;
}