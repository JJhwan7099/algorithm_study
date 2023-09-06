#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
int graph[66][66];
int visit[66][66];
bool check;
void dfs(int x, int y)
{
    visit[x][y] = 1;
    if(graph[x][y] == -1)
    {
        check = true;
        return;
    }else if(graph[x][y] != 0){
        int n = graph[x][y];
        if(n != 0)
        {
            if(y+n <= N && visit[x][y+n] == 0)
                dfs(x,y+n);
            if(x+n <= N && visit[x+n][y] == 0)
                dfs(x+n,y);
        }
    }
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({1,1});
    while(q.size() > 0)
    {
        int x = q.front().first; int y = q.front().second;
        int n = graph[x][y];
        if(n == -1)
        {
            check = true;
            break;
        }
        if(y + n <= N && visit[x][y+n] == 0)
        {
            q.push({x,y+n});
            visit[x][y+n] = 1;
        }
        if(x + n <= N && visit[x+n][y] == 0) 
        {
            q.push({x+n,y});
            visit[x+n][y] = 1;
        }
        q.pop();
    }
}
int main()
{
    cin >> N;
    // fill(&graph[0][0],&graph[66][66],-10);
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    // dfs(1,1);
    bfs();
    if(!check) cout << "Hing";
    else cout << "HaruHaru";
    return 0;
}