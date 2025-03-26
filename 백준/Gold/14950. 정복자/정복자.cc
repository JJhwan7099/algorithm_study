#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M,t;
int add = 0;
vector<pair<int,pair<int,int>>> edges;
int parent[10001];
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> t;
    FOR(i,M) {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(), edges.end());
    FOR(i,N) parent[i] = i;
    int result = 0;
    for(auto&edge:edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        int parentU = find_parent(u);
        int parentV = find_parent(v);
        if(parentU!=parentV) {
            parent[min(parentU,parentV)] = max(parentU,parentV);
            result += add + cost;
            add += t;
        }
    }
    cout << result << '\n';
    return 0;
}