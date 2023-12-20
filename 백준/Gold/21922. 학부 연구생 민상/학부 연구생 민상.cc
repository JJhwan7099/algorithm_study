#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[2001][2001];
int visit[2001][2001];
vector<pair<int,int>> v;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void bfs(int x, int y)
{
    queue<pair<pair<int,int>,pair<int,int>>> q;
    visit[x][y]=1;
    for(int i=0; i<4; i++)
    {
        q.push({{x+dx[i],y+dy[i]},{dx[i],dy[i]}});
        visit[x+dx[i]][y+dy[i]] = 1;
    }
    while(!q.empty())
    {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int ddx = q.front().second.first;
        int ddy = q.front().second.second;
        q.pop();
        int x1 = X + ddx; int y1 = Y + ddy;
        if(X<1 || X>N || Y<1 || Y>M) continue;
        if(ddx==0 && ddy==0) continue;
        else{
            if(graph[X][Y]==0)
            {
                visit[x1][y1] = 1;
                q.push({{x1,y1},{ddx,ddy}});
            }
            else{
                if(graph[X][Y]==1)
                {
                    if(ddx==0)
                    {
                        continue;
                    }
                    else
                    {
                        q.push({{x1,y1},{ddx,ddy}});
                        visit[x1][y1] = 1;
                    }
                }
                else if(graph[X][Y]==2)
                {
                    if(ddy==0)
                    {
                        continue;
                    }
                    else
                    {
                        q.push({{x1,y1},{ddx,ddy}});
                        visit[x1][y1] = 1;
                    }
                }
                else if(graph[X][Y]==3)
                {
                    if(ddx==0)
                    {
                        q.push({{X-ddy,Y},{0-ddy,0}});
                        visit[X-ddy][Y]=1;
                    }
                    else if(ddy==0)
                    {
                        q.push({{X,Y-ddx},{0,0-ddx}});
                        visit[X][Y-ddx] = 1;
                    }
                }
                else if(graph[X][Y]==4)
                {
                    if(ddx==0)
                    {
                        q.push({{X+ddy,Y},{ddy,0}});
                        visit[X+ddy][Y]=1;
                    }
                    else if(ddy==0)
                    {
                        q.push({{X,Y+ddx},{0,ddx}});
                        visit[X][Y+ddx] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    int cnt = 0;
    cin >> N >> M;
    FOR(i,N) FOR(j,M) 
    {
        cin >> graph[i][j];
        if(graph[i][j]==9) v.push_back({i,j});
    }
    for(auto&a :v) bfs(a.first, a.second);
    FOR(i,N)FOR(j,M) if(visit[i][j]==1) cnt++;
    cout << cnt << "\n";
}