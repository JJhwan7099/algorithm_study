#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,M;
vector<int> graph[1001];
int visit[1001];
int check[1001];
int result = 0;
void bfs(int n)
{
    queue<int> q1;
    q1.push(n);
    while(!q1.empty())
    {
        int a = q1.front();
        for(int i=0; i<graph[a].size(); i++)
        {
            if(visit[graph[a][i]]!=1)
            {
                visit[graph[a][i]] = 1;
                check[graph[a][i]] = 0;
                q1.push(graph[a][i]);
            }
        }
        q1.pop();
    }
}
int main()
{
    cin >> N >> M;
    fill(&check[1],&check[N+1],1);
    FOR(i,M)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    FOR(i,1001)
    {
        if(check[i] == 1)
        {
            check[i] = 0;
            bfs(i);
            result++;
        }
    }
    cout << result;
}