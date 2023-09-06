#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,M;
int graph[301][301];
int save[301][301];
vector<int> result;
void print()
{
    FOR(i,N){FOR(j,M) cout << graph[i][j]  << " "; cout << endl;}
}
struct location{
    int X, Y, count;
};
void dfs(int x, int y, int cnt)
{
    if(x==N && y==M)
    {
        result.push_back(cnt);
    }else if(x>N || y>M)
    {
        return;
    }
    int n = graph[x][y];
    for(int i=1; i<=n; i++)
    {
        if(y+i != -1)
            dfs(x,y+i,cnt+1);
        if(x+i != -1)
            dfs(x+i,y,cnt+1);
    }
}
void bfs()
{
    queue<location> q;
    location loc; loc.X = 1; loc.Y = 1; loc.count = 0;
    q.push(loc);
    while(q.size() > 0)
    {
        location l = q.front();
        int n = graph[l.X][l.Y];
        if(l.X == N && l.Y == M)
        {
            cout << l.count;
            break;
            return;
        }
        for(int i=n; i>=1; i--)
        {
            location l1; l1.X = l.X; l1.Y = l.Y+i; l1.count = l.count + 1;
            location l2; l2.X = l.X+i; l2.Y = l.Y; l2.count = l.count + 1;
            if(l1.X <= N && l1.Y <= M && (save[l1.X][l1.Y] > l1.count || save[l1.X][l1.Y] == 0))
            { 
                q.push(l1);
                save[l1.X][l1.Y] = l1.count;
            }
            if(l2.X <= N && l2.Y <= M && (save[l2.X][l2.Y] > l2.count || save[l2.X][l2.Y] == 0))
            {
                q.push(l2);
                save[l2.X][l2.Y] = l2.count;
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N >> M;
    fill(&graph[0][0],&graph[300][300],-1);
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    // dfs 이용
    // dfs(1,1,0);
    // int min = result[0];
    // for(auto&a : result)
    // {
    //     if(a < min) min = a;
    // }
    // cout << min;

    //bfs 이용
    bfs();
}