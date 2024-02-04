#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> graph[101];
int visit[101];
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}
void bfs(int n)
{
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty())
    {
        int n1 = q.front().first;
        int cnt = q.front().second;
        visit[n1] = cnt;
        q.pop();
        for(int i=0; i<graph[n1].size(); i++)
        {
            if(graph[n1][i]!=n && (visit[graph[n1][i]]==0 || visit[graph[n1][i]]>visit[n1]+1))
            {
                visit[graph[n1][i]]=visit[n1]+1;
                q.push({graph[n1][i],cnt+1});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M)
    {
        int s,e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    vector<pair<int,int>> ans;
    FOR(i,N)
    {
        FOR(i,N) visit[i] = 0;
        bfs(i);
        int sum = 0;
        FOR(i,N) sum+=visit[i];
        ans.push_back({i,sum});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].first;
    return 0;
}