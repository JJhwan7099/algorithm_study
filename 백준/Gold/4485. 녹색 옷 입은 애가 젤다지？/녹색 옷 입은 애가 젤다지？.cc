#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int graph[126][126];
int visit[126][126];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dijk()
{
    queue<pair<int,int>> q;
    visit[1][1] = graph[1][1];
    q.push({1,1});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X = x+dx[i];
            int Y = y+dy[i];
            if(X<1||Y<1||X>N||Y>N) continue;
            if(visit[X][Y]==-1||visit[X][Y]>visit[x][y]+graph[X][Y])
            {
                visit[X][Y] = visit[x][y]+graph[X][Y];
                q.push({X,Y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
    while(cin>>N)
    {
        if(N==0) break;
        FOR(i,N)FOR(j,N) visit[i][j]=-1;
        FOR(i,N)FOR(j,N) cin >> graph[i][j];
        dijk();
        cout << "Problem " << cnt++ << ": " << visit[N][N] << '\n';
    }
    return 0;
}