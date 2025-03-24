#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<pair<int,int>> edges;
int parent[500001];
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M) {
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    FOR(i,N) parent[i] = i;
    int ans = 1;
    for(auto&edge:edges) {
        int u = edge.first;
        int v = edge.second;
        int parentU = find_parent(u);
        int parentV = find_parent(v);
        if(parentU == parentV) {
            break;
        }
        else {
            parent[min(parentU,parentV)] = max(parentU,parentV);
            ans++;
        }
    }
    if(ans-1==M) cout << 0;
    else cout << ans;
    return 0;
}