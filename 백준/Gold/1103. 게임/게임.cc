#include<iostream>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[51][51];
int DP[51][51];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
map<pair<int,int>,int> visited;
int ans=0;
void dfs(int x, int y, int cnt)
{
    if(ans==-1) return;
    for(int i=0; i<4; i++)
    {
        int X = x+(graph[x][y]*dx[i]);
        int Y = y+(graph[x][y]*dy[i]);
        if(X<1||Y<1||X>N||Y>M||graph[X][Y]==-1) continue;
        else if(visited[{X,Y}]==1){
            ans=-1;
            return;
        }
        else
        {
            if(DP[X][Y]<DP[x][y]+1)
            {
                visited[{X,Y}]=1;
                DP[X][Y]=DP[x][y]+1;
                dfs(X,Y,cnt+1);
                visited[{X,Y}]=0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)FOR(j,M)
    {
        char a; cin >> a;
        if(a!='H') graph[i][j] = a-'0';
        else graph[i][j]=-1;
    }
    DP[1][1]=1;
    visited[{1,1}]=1;
    dfs(1,1,0);
    if(ans!=-1)
    {
        FOR(i,N)FOR(j,M) ans = max(ans,DP[i][j]);
    }
    cout << ans;
    return 0;
}