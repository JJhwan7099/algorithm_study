#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)
vector<int> graph[201];
int cost[201][201];
int d[201];
int dis[201];//s 에서 특정 점 까지의 거리
int Adis[201];//특정 점(인덱스)에서 A 까지의 거리
int Bdis[201];//특정 점(인덱스)에서 B 까지의 거리
int N;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        FOR(i,graph[n].size())
        {
            int g = graph[n][i];
            if(g!=s && (dis[g]==0 || dis[g] > dis[n] + cost[n][g]))
            {
                dis[g] = dis[n] + cost[n][g];
                q.push(g);
            }
        }
    }
}
void abfs(int s)
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        FOR(i,graph[n].size())
        {
            int g = graph[n][i];
            if(g!=s && (Adis[g]==0 || Adis[g] > Adis[n] + cost[n][g]))
            {
                Adis[g] = Adis[n] + cost[n][g];
                q.push(g);
            }
        }
    }
}
void bbfs(int s)
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        FOR(i,graph[n].size())
        {
            int g = graph[n][i];
            if(g!=s && (Bdis[g]==0 || Bdis[g] > Bdis[n] + cost[n][g]))
            {
                Bdis[g] = Bdis[n] + cost[n][g];
                q.push(g);
            }
        }
    }
}
int solution(int n, int s, int AA, int BB, vector<vector<int>> fares) {
    int answer = 0;
    N = n;
    FOR(i,fares.size())
    {
        int a = fares[i][0]; int b = fares[i][1]; int c = fares[i][2];
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a][b] = c;
        cost[b][a] = c;
    }
    bfs(s);
    abfs(AA);
    bbfs(BB);
    // for(int i=1; i<=n; i++)
    // {
    //     abbfs(i,AA,BB);
    // }
    for(int i=1; i<=n; i++)
    {
        int result = dis[i] + Adis[i] + Bdis[i];
        if(result!=0 && (answer==0 || answer > result)) answer = result;
    }
    return answer;
}