#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
#define endl '\n'
char graph[13][7];
int cnt = 0;
int result = 0;
int visit[13][7];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int>> v;
void drop()
{
    for(int i=12; i>0; i--)FOR(j,6)
    {
        if(graph[i][j]!='.')
        {
            int X = i;
            while(true)
            {
                if(X==12 || graph[X+1][j]!='.') break;
                else if(graph[X+1][j] == '.'){
                    graph[X+1][j] = graph[X][j];
                    graph[X][j] = '.';
                    X++;
                }
            }
        }
    }
}
void dfs(int x,int y, char c)
{
    visit[x][y] = 1;
    v.push_back({x,y});
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>12 || X<1 || Y>12 || Y<1) continue;
        else if(graph[X][Y]==c && visit[X][Y]!=1)
        {
            dfs(X,Y,c);
        }
    }
}
int main()
{
    FOR(i,12)FOR(j,6) cin >> graph[i][j];
    while(true)
    {
        bool check = false; // 터트린 뿌요가 있는지, 있다면 뿌요 다시 떨어뜨리기
        FOR(i,12)FOR(j,6)
        {
            if(graph[i][j]!='.')
            {
                cnt = 0;
                FOR(k,12)FOR(m,6) visit[k][m] = 0;
                v.clear();
                dfs(i,j,graph[i][j]);
                if(v.size()>=4)
                {
                    for(auto&a : v) graph[a.first][a.second] = '.';
                    check = true;
                }
            }
        }
        if(check==true)//터트린 뿌요가 있다면
        {
            result++;
            drop();
            check = false;
        }else break;//터트린 뿌요가 없다면 끝
    }
    cout << result;
}