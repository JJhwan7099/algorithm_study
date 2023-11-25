#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, R;
vector<int> v[100001];
int visit[100001];
int ans[100001];
int cnt = 1;
void dfs(int n)
{
    visit[n] = 1;
    ans[n] = cnt++;
    for(int i=0; i<v[n].size(); i++)
    {
        if(visit[v[n][i]]!=1) dfs(v[n][i]);
    }
}
int main()
{
    cin >> N >> M >> R;
    for(int i=0; i<M; i++)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    dfs(R);
    for(int i=1; i<=N; i++)
    {
        cout << ans[i] << '\n';
    }
}