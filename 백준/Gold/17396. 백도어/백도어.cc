#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int available[100001];
long long dist[100001];
vector<pair<int,int>> graph[100001];
struct cmp{
    bool operator()(pair<int,long long> a,pair<int,long long> b) {
        return a.second > b.second;
    }
};
void search() {
    priority_queue<pair<int,long long>,vector<pair<int,long long>>, cmp> q;
    q.push({0,0});
    dist[0] = 0;
    while(!q.empty()) {
        int cur = q.top().first;
        long long curCost = q.top().second;
        q.pop();
        if(curCost > dist[cur]) continue;
        else {
            for(int i=0; i<graph[cur].size(); i++) {
                int next = graph[cur][i].first;
                long long t = graph[cur][i].second+curCost;
                if(dist[next]==-1 || t < dist[next]) {
                    dist[next] = t;
                    if(next!=N-1) q.push({next,t});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0 ; i<N ; i++) {
        cin >> available[i];
        dist[i] = -1;
    }
    available[N-1] = 0;
    for(int i=0 ; i<M ; i++) {
        int s,e,t; cin >> s >> e >> t;
        if(available[s]!=0 || available[e]!=0) continue;
        graph[s].push_back({e,t});
        graph[e].push_back({s,t});
    }
    search();
    cout << dist[N-1] << "\n";
    return 0;
}