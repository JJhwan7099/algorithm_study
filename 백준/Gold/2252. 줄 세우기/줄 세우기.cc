#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
// int graph[32001][32001];
map<int,int> frontCheckMap;
vector<int> graph[32001];
int cnt;
queue<int> q;
void topologySort(queue<int>& q) {
    while(q.size() > 0) {
        cout << q.front() << ' ';
        cnt--;
        frontCheckMap[q.front()] = -1;
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size(); i++) {
            frontCheckMap[graph[cur][i]]--;
            if(frontCheckMap[graph[cur][i]] == 0) q.push(graph[cur][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    cnt = N;
    FOR(i,M) {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        frontCheckMap[b]++;
    }
    FOR(i,N) {
        if(frontCheckMap[i] == 0) {
            q.push(i);
        }
    }
    topologySort(q);
    return 0;
}