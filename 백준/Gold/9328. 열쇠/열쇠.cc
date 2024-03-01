#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T,N,M;
char graph[101][101];
int visit[101][101];
int doc = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
map<char,int> key;
map<pair<int,int>,int> docget;
map<char,queue<pair<int,int>>> yet;
map<pair<int,int>, int> keyyet;
int stx, sty;
bool check()
{
    for(auto&a:yet)
    {
        if(key[a.first]==1 && a.second.size()>0) return false;
    }
    return true;
}
void go(int x, int y)
{
    visit[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X<1||Y<1||X>N||Y>M) continue;
        else{
            if(visit[X][Y]!=1&&graph[X][Y]!='*')
            {
                if(isupper(graph[X][Y]))
                {
                    if(key[graph[X][Y]]!=1)yet[graph[X][Y]].push({X,Y});
                    else go(X,Y);
                }
                else if(islower(graph[X][Y]))
                {
                    key[graph[X][Y]-32]=1;
                    go(X,Y);
                }else if(graph[X][Y]=='$')
                {
                    if(docget[{X,Y}]!=1)
                    {
                        docget[{X,Y}]=1;
                        doc++;
                    }
                    go(X,Y);
                }else{
                    go(X,Y);
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        key.clear();
        docget.clear();
        yet.clear();
        keyyet.clear();
        FOR(i,N)FOR(j,M) visit[i][j]=0;
        doc=0;
        cin >> N >> M;
        FOR(i,N)FOR(j,M) cin >> graph[i][j];
        string key_have; cin >> key_have;
        for(int i=0; i<key_have.length(); i++)
        {
            if(key_have[i]!='0') key[key_have[i]-32]=1;
        }
        FOR(i,N)FOR(j,M)
        {
            if((i==1||j==1||i==N||j==M)&&graph[i][j]!='*'){
                if(isupper(graph[i][j]))
                {
                    if(key[graph[i][j]]!=1) yet[graph[i][j]].push({i,j});
                    else go(i,j);
                }
                else if(islower(graph[i][j])){
                    key[graph[i][j]-32]=1;
                    go(i,j);
                }
                else if(graph[i][j]=='$'&&visit[i][j]!=1) 
                {
                    if(docget[{i,j}]!=1)
                    {
                        doc++;
                        docget[{i,j}]=1;
                    }
                    go(i,j);
                }
                else go(i,j);
            }
        }
        while(!check())
        {
            for(auto&a:yet)
            {
                if(key[a.first]==1)
                {
                    while(!a.second.empty())
                    {
                        int x = a.second.front().first;
                        int y = a.second.front().second;
                        a.second.pop();
                        go(x,y);
                    }
                }
            }
        }
        cout << doc << '\n';
    }
    return 0;
}