#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
vector<int> graph[100001];//그래프
int visit[100001];
int ans[100001];//각 노드의 부모노드 저장
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visit[n] = 1;
    while(!q.empty())
    {
        int a = q.front();
        for(int i=0; i<graph[a].size(); i++)
        {
            if(visit[graph[a][i]]!=1)
            {
                ans[graph[a][i]] = a;
                q.push(graph[a][i]);
                visit[graph[a][i]] = 1;
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N;
    FOR(i,N-1)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    for(int i=2; i<=N; i++) cout << ans[i] << '\n';
}