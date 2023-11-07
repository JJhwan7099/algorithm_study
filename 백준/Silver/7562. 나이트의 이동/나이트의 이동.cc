#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int T;
int N; 
int visit[302][302];
int bfs(int x, int y, int fx, int fy,int n)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});
    visit[x][y]=1;
    while(q.size()>0)
    {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int cnt = q.front().second;
        if(X==fx && Y==fy)
        {
            return cnt;
        }
        else
        {
            int dx = X+2;
            int dy = Y+1;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X+2;
            dy = Y-1;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X-2;
            dy = Y+1;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X-2;
            dy = Y-1;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X+1;
            dy = Y+2;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X-1;
            dy = Y+2;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X+1;
            dy = Y-2;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
            dx = X-1;
            dy = Y-2;
            if(visit[dx][dy]!=1 && (dx>=0 && dx<n && dy>=0 && dy<n))
            {
                visit[dx][dy]=1;
                q.push({{dx,dy},cnt+1});
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        int x,y; cin >> x >> y;
        int fx,fy; cin >> fx >> fy;
        fill(&visit[0][0],&visit[301][301],0);
        cout << bfs(x,y,fx,fy,N) << '\n';
    }
}