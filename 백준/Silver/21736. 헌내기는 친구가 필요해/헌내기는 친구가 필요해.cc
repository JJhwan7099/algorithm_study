#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
char graph[601][601];
int N,M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visit[601][601];
int ans=0;
void dfs(int x, int y)
{
    visit[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X<1||Y<1||X>N||Y>M) continue;
        else if(graph[X][Y]!='X'&&visit[X][Y]!=1)
        {
            if(graph[X][Y]=='P') ans++;
            dfs(X,Y);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    pair<int,int> doyeon;
    FOR(i,N)FOR(j,M)
    {
        cin >> graph[i][j];
        if(graph[i][j]=='I') doyeon={i,j};
    }
    dfs(doyeon.first,doyeon.second);
    if(ans!=0) cout << ans;
    else cout << "TT";
    return 0;
}