#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int V,E;
vector<pair<int,pair<int,int>>> edges;
int parents[10001];
int find_parent(int n) {
    if(parents[n]==n) return n;
    return parents[n] = find_parent(parents[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    FOR(i,E) {
        int a,b,c; cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    int result = 0;
    sort(edges.begin(), edges.end());
    FOR(i,V) parents[i] = i;
    for(auto&edge: edges) {
        int a = edge.second.first;
        int b = edge.second.second;
        int cost = edge.first;
        int parentA = find_parent(a);
        int parentB = find_parent(b);
        if(parentA!=parentB) {
            parents[min(parentA,parentB)] = max(parentA,parentB);
            result += cost;
        }
    }
    cout << result;
    return 0;
}