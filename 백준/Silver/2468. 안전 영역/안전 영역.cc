#include<iostream>
#include<vector>
#define FOR(i,N) for(int i=1;i<=N;i++)
using namespace std;
int N;
int visit[101][101];
int graph[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int> v;
void dfs(int x,int y, int h)
{
    visit[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(visit[X][Y]!=1 && graph[X][Y]>h)
        {
            dfs(X,Y,h);
        }
    }
}
int main()
{
    cin >> N;
    int maxrain = 0;
    FOR(i,N)FOR(j,N) 
    {
        cin >> graph[i][j];
        if(graph[i][j]>maxrain) maxrain = graph[i][j];
    }
    for(int i=0; i<=maxrain; i++)
    {
        int cnt=0;
        FOR(x,N)FOR(y,N)
        {
            if(graph[x][y]>i && visit[x][y]!=1)
            {
                dfs(x,y,i);
                cnt++;
            }
        }
        v.push_back(cnt);
        FOR(x,N)FOR(y,N) visit[x][y]=0;
    }
    int result=v[0];
    for(auto &a : v) if(result<a) result=a;
    cout << result;
}