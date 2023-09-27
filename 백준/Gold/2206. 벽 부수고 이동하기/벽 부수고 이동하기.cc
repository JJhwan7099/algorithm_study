#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M;
vector<int> graph[1001];
int visit[1001][1001][2];
bool check = false;
void bfs()
{
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    queue<pair<pair<int,int>,pair<int,bool>>> q;
    q.push({{1,1},{1,false}});
    visit[1][1][false] = 1;
    while(q.size() > 0)
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        bool bk = q.front().second.second;
        if(x==N && y==M)
        {
            cout << cnt;
            return;
        }
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X < 1 || Y < 1 || X > N || Y > M) continue;
            if(graph[X][Y]==1 && bk==false && visit[X][Y][bk]==0)//벽을 만났을때 아직 깬 벽이 없음
            {
                q.push({{X,Y},{cnt+1,true}});
                visit[X][Y][true] = 1;
            }else if(graph[X][Y]==0 && visit[X][Y][bk]==0)//벽이 아님
            {
                q.push({{X,Y},{cnt+1,bk}});
                visit[X][Y][bk] = 1;
            }
        }
        q.pop();
    }
    cout << -1;
}
int main()
{
    cin >> N >> M;
    FOR(i,N)
    {
        string s; cin >> s;
        graph[i].push_back(-1);
        FOR(j,M) graph[i].push_back(s[j-1]-'0');
    } 
    bfs();
}