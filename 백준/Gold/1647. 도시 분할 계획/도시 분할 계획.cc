#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<pair<int,pair<int,int>>> edges;
int parent[100001];
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M) {
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(), edges.end());
    int result = 0;
    int maxCost = 0;
    FOR(i,N) parent[i] = i;
    for(auto& edge : edges) {
        int a = edge.second.first;
        int b = edge.second.second;
        int cost = edge.first;
        int parentA = find_parent(a);
        int parentB = find_parent(b);
        if(parentA!=parentB) {
            parent[min(parentA,parentB)] = max(parentA,parentB);
            result += cost;
            maxCost = max(maxCost, cost);
        }
    }
    cout << result-maxCost << '\n';
    return 0;
}