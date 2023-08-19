#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
vector<int> graph[1200];
int visit[1200];
int cnt[1200];
vector<int> ans;
void bfs(int n)
{
    queue<int> q1;
    q1.push(n);
    cnt[n] = 0;
    while(!q1.empty())
    {
        int a = q1.front();
        for(int i=0; i<graph[a].size(); i++)
        {
            if(!visit[graph[a][i]]&&graph[a][i]!=0)
            {
                visit[graph[a][i]] = 1;
                cnt[graph[a][i]] = cnt[a]+1;
                q1.push(graph[a][i]);
            }
        }
        q1.pop();
    }
}
int main()
{
    cin >> N;
    FOR(i,N) 
    {
        int a; cin >> a;
        FOR(j,a)
        {
            graph[i].push_back(i+j);
        }
    }
    bfs(1);
    if(N==1)
    {
        cout << "0";
        return 0;
    }
    if(cnt[N]==0) cout << "-1";
    else cout << cnt[N];
}
