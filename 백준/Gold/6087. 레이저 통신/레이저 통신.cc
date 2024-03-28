#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
char graph[101][101];
int vis[101][101];
pair<int,int> startc;
pair<int,int> endc;
pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
int ans = 100000;
void bfs(int x1, int y1, int d)
{
    FOR(i,N)FOR(j,M) vis[i][j]=100000;
    vis[startc.first][startc.second]=1;
    vis[x1][y1]=1;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{x1,y1},{d,0}});
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dd = q.front().second.first;
        int mir = q.front().second.second;
        q.pop();
        int X,Y;
        X = x+dir[dd].first;
        Y = y+dir[dd].second;
        if(!(X<1||Y<1||X>N||Y>M)&&vis[X][Y]>mir)
        {
            if(graph[X][Y]=='.'){
                q.push({{X,Y},{dd,mir}});
                vis[X][Y]=mir;
            }else if(graph[X][Y]=='C'){
                ans = min(ans,mir);
            }
        }
        X = x+dir[(dd+1)%4].first;
        Y = y+dir[(dd+1)%4].second;
        if(!(X<1||Y<1||X>N||Y>M)&&vis[X][Y]>mir+1)
        {
            if(graph[X][Y]=='.'){
                q.push({{X,Y},{(dd+1)%4,mir+1}});
                vis[X][Y]=mir+1;
            }else if(graph[X][Y]=='C'){
                ans = min(ans,mir+1);
            }
        }
        X = x+dir[(dd+3)%4].first;
        Y = y+dir[(dd+3)%4].second;
        if(!(X<1||Y<1||X>N||Y>M)&&vis[X][Y]>mir+1)
        {
            if(graph[X][Y]=='.'){
                q.push({{X,Y},{(dd+3)%4,mir+1}});
                vis[X][Y]=mir+1;
            }else if(graph[X][Y]=='C'){
                ans = min(ans,mir+1);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    bool b = false;
    FOR(i,N)FOR(j,M) 
    {
        cin >> graph[i][j];
        if(graph[i][j]=='C')
        {
            if(!b){
                startc = {i,j};
                b=true;
            }else{
                endc = {i,j};
            }
        }
    }
    for(int i=0; i<4; i++) 
    {
        if(graph[startc.first+dir[i].first][startc.second+dir[i].second]=='.')
            bfs(startc.first+dir[i].first,startc.second+dir[i].second,i);
        else if(graph[startc.first+dir[i].first][startc.second+dir[i].second]=='C'){
            cout << 0;
            return 0;
        }
    }
    cout << ans;
    return 0;
}