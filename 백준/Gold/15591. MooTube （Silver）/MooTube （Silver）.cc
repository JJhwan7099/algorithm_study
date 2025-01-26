#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,Q;
vector<int> graph[5001];
int cost[5001][5001];
int vis[5001];
int ans = 0;
int usado = -1;
int result[5001];
void dfs(int s) {
    result[s] = usado;
    for(int i=0; i<graph[s].size(); i++) {
        if(vis[graph[s][i]] == 0) {
            vis[graph[s][i]] = 1;
            int n = usado;
            if(usado == -1 || usado > cost[s][graph[s][i]]) {
                usado = cost[s][graph[s][i]];
            }
            dfs(graph[s][i]);
            usado = n;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    FOR(i,N-1) {
        int a,b,c; cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[a][b] = c;
        cost[b][a] = c;
    }
    FOR(i,Q) {
        ans = 0;
        usado = -1;
        FOR(j,N) {
            vis[j] = 0;
            result[j] = 0;
        }
        int k, v;
        cin >> k >> v;
        vis[v]=1;
        dfs(v);
        FOR(j,N) if(result[j]>=k) ans++;
        cout << ans << '\n';
    }
    return 0;
}