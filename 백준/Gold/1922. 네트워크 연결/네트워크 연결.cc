#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<pair<int,pair<int,int>>> edges;
int parent[1001];
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M) {
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(), edges.end());
    FOR(i,N) parent[i] = i;
    int result = 0;
    for(auto& edge : edges) {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        int parentu = find_parent(u);
        int parentv = find_parent(v);
        if(parentu!=parentv) {
            parent[min(parentu,parentv)] = max(parentu,parentv);
            result += cost;
        }
    }
    cout << result << '\n';
    return 0;
}