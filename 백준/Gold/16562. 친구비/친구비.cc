#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M, K;
int fcost[10001];
vector<int> r[10001];
int visit[10001]={0,};
vector<vector<int> > v;
bool cmp(int a, int b){
    return fcost[a]<fcost[b];
}
void bfs(int a)
{
    vector<int> vv;
    queue<int> q;
    q.push(a);
    visit[a]=1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        vv.push_back(n);
        for(int i=0; i<r[n].size(); i++)
        {
            if(visit[r[n][i]]!=1)
            {
                visit[r[n][i]]=1;
                q.push(r[n][i]);
            }
        }
    }
    v.push_back(vv);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    FOR(i,N) cin >> fcost[i];
    FOR(i,M){
        int a,b; cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    int ans=0;
    FOR(i,N) if(visit[i]!=1) bfs(i);
    for(int i=0; i<v.size(); i++) sort(v[i].begin(), v[i].end(), cmp);
    for(auto&a: v) ans+=fcost[a[0]];
    if(ans<=K) cout << ans;
    else cout << "Oh no";
    return 0;
}