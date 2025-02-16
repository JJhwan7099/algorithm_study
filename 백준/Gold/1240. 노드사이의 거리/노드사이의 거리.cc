#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<pair<int,int>> tree[1001];
int visited[1001];
int bfs(int start, int end) {
    FOR(i,N) visited[i] = -1;
    priority_queue<pair<int,int>> q;
    q.push({start,0});
    visited[start] = 0;
    while(!q.empty()) {
        int s = q.top().first;
        int curDis = q.top().second;
        q.pop();
        if(curDis < visited[s]) continue;
        for(int i=0; i<tree[s].size(); i++) {
            int next = tree[s][i].first;
            int nextDis = curDis + tree[s][i].second;
            if(visited[next]==-1 || visited[next]>nextDis) {
                visited[next] = nextDis;
                q.push({next,nextDis});
            }
        }
    }
    return visited[end];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N-1) {
        int a,b,c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    FOR(i,M) {
        int a,b; cin >> a >> b;
        cout << bfs(a,b) << "\n";
    }
    return 0;
}