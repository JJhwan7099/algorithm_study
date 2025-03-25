#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M,N;
int totMoney = 0;
int result = 0;
vector<pair<int,pair<int,int>>> edges;
int parent[200001];
vector<int> answers;
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        cin >> M >> N;
        totMoney = 0;
        result = 0;
        edges.clear();
        for(int i=0; i<M; i++) parent[i] = i;
        if(!M&&!N) break;
        else {
            FOR(i,N) {
                int a,b,c; cin >> a >> b >> c;
                totMoney += c;
                edges.push_back({c,{a,b}});
            }
            sort(edges.begin(), edges.end());
            for(auto&edge:edges) {
                int cost = edge.first;
                int u = edge.second.first;
                int v = edge.second.second;
                int parentU = find_parent(u);
                int parentV = find_parent(v);
                if(parentU!=parentV) {
                    parent[min(parentU,parentV)] = max(parentU,parentV);
                    result+=cost;
                }
            }
            answers.push_back(totMoney - result);
        } 
    }
    for(auto&answer:answers) cout << answer << '\n';
    return 0;
}