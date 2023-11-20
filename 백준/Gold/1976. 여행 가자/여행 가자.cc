#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M;
vector<int> graph[201];
int answay[1001];
// string answay = "";
string result = "YES";
bool bfs(int s, int e)
{
    int visit[201] = {0,};
    queue<int> q;
    visit[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int n = q.front();
        if(n==e) return true;
        for(int i=0; i<graph[n].size(); i++)
        {
            if(visit[graph[n][i]]!=1)
            {
                visit[graph[n][i]]=1;
                q.push(graph[n][i]);
            }
        }
        q.pop();
    }
    return false;
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,N)
    {
        int a; cin >> a;
        if(a==1) graph[i].push_back(j);
    }
    FOR(i,M) 
    {
        cin >> answay[i];
    }
    FOR(i,M-1)
    {
        if(!bfs(answay[i],answay[i+1]))
        {
            result = "NO";
            break;
        }
    }
    cout << result;
}