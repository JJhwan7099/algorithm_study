#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int V,E;
int startNode;
vector<pair<int,int>> edges[20001];
int visited[20001];
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};
void dijk(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({start,0});
    visited[start]=0;
    while(!pq.empty()) {
        int cur = pq.top().first;
        int curCost = pq.top().second;
        pq.pop();
        if(visited[cur]<curCost) continue;
        else {
            for(int i = 0; i < edges[cur].size(); i++) {
                int next = edges[cur][i].first;
                int nextCost = curCost + edges[cur][i].second;
                if(visited[next]==-1 || visited[next]>nextCost) {
                    visited[next] = nextCost;
                    pq.push({next,nextCost});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E >> startNode;
    FOR(i,E) {
        int a, b, cost; cin >> a >> b >> cost;
        edges[a].push_back({b,cost});
    }
    FOR(i,V) visited[i] = -1;
    dijk(startNode);
    FOR(i,V) {
        if(visited[i]!=-1) cout << visited[i] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}