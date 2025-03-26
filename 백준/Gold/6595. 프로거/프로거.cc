#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
vector<pair<int,int>> stones;
vector<pair<double,pair<int,int>>> edges;
int parent[500001];
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count = 0;
    while(++count) {
        int N; cin >> N;
        if(N == 0) break;
        else {
            FOR(i,N) {
                int x, y; cin >> x >> y;
                stones.push_back({x,y});
            }
            for(int i=0; i<stones.size(); i++) {
                for(int j=i+1; j<stones.size(); j++) {
                    int dx = stones[i].first - stones[j].first;
                    int dy = stones[i].second - stones[j].second;
                    edges.push_back({sqrt(dx*dx + dy*dy), {i,j}});
                }   
            }
            double result = 0;
            sort(edges.begin(), edges.end());
            for(int i = 0; i<N; i++) parent[i] = i;
            for(auto& edge : edges) {
                int u = edge.second.first;
                int v = edge.second.second;
                double cost = edge.first;
                // cout << cost << " " << u << " " << v << endl;
                int parentu = find_parent(u);
                int parentv = find_parent(v);
                if(parentu!=parentv) {
                    parent[min(parentu,parentv)] = max(parentu,parentv);
                    result=max(result,cost);
                    // cout << result << " " << find_parent(0) << " " << find_parent(1) << "\n";
                    if(find_parent(0)==find_parent(1))
                        break;
                }
            }
            result *= 1000;
            result = round(result);
            result /= 1000;
            cout << fixed;
            cout.precision(3);
            cout << "Scenario #" << count << '\n' << "Frog Distance = " << result << '\n' << '\n';
            stones.clear();
            edges.clear();
        }
    }
    return 0;
}