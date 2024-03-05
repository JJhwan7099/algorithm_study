#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
char graph[51][51];
int visit[51][51];
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;
void bfs(int x, int y)
{
    FOR(i,N)FOR(j,M) visit[i][j]=0;
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visit[x][y]=1;
    while(!q.empty())
    {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        if(dis>ans) ans=dis;
        for(int i=0; i<4; i++)
        {
            int x1 = X+dx[i];
            int y1 = Y+dy[i];
            if(x1<1||y1<1||x1>N||y1>M) continue;
            else if(graph[x1][y1]=='L' && visit[x1][y1]==0){
                visit[x1][y1]=1;
                q.push({{x1,y1},dis+1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)FOR(j,M) {
        cin >> graph[i][j];
    }
    FOR(i,N)FOR(j,M) if(graph[i][j]=='L') bfs(i,j);
    cout << ans;
    return 0;
}