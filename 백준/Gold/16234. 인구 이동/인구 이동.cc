#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,L,R;
int graph[51][51];
int visit[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs(int x, int y, int c)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[x][y]=c;
    while(!q.empty())
    {
        int x1=q.front().first;
        int y1=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X = x1+dx[i];
            int Y = y1+dy[i];
            if(X<1||Y<1||X>N||Y>N) continue;
            else if(abs(graph[x1][y1]-graph[X][Y])<=R&&abs(graph[x1][y1]-graph[X][Y])>=L&&visit[X][Y]==0)
            {
                q.push({X,Y});
                visit[X][Y]=c;
            }
        }
    }
}
void dfs(int x, int y, int c, queue<pair<int,int>>& q)
{
    q.push({x,y});
    visit[x][y]=0;
    for(int i=0; i<4; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X<1||Y<1||X>N||Y>N) continue;
        else if(visit[X][Y]==c){
            visit[X][Y]=0;
            dfs(X,Y,c,q);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R;
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    int cnt=1;
    int day=0;
    while(true)
    {
        queue<queue<pair<int,int>>> Q;
        FOR(i,N)FOR(j,N) visit[i][j]=0;
        FOR(i,N)FOR(j,N) if(visit[i][j]==0) bfs(i,j,cnt++);
        FOR(i,N)FOR(j,N) if(visit[i][j]!=0) {
            queue<pair<int,int>> q;
            dfs(i,j,visit[i][j],q);
            if(q.size()>1)Q.push(q);
        }
        if(Q.empty()) break;
        else 
        {
            while(!Q.empty())
            {
                queue<pair<int,int>> q = Q.front();
                Q.pop();
                int qs = q.size();
                int tot = 0;
                for(int i=0; i<qs; i++)
                {
                    q.push(q.front());
                    tot+=graph[q.front().first][q.front().second];
                    q.pop();
                }
                while(!q.empty())
                {
                    graph[q.front().first][q.front().second]=tot/qs;
                    q.pop();
                }
            }
            day++;
        }
    }
    cout << day;
    return 0;
}