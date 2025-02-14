#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<int> friends[51];
map<int,vector<int>> captains;
int bfs(int n) {
    int visited[51] = {0,};
    queue<pair<int,int>> q;
    q.push({n,0});
    visited[n] = 1;
    int maxDepth = 0;
    while(!q.empty()) {
        int person = q.front().first;
        int depth = q.front().second;
        q.pop();
        maxDepth = max(maxDepth, depth);
        for(int i=0; i<friends[person].size(); i++) {
            int f = friends[person][i];
            if(visited[f]==0) {
                visited[f] = 1;
                q.push({f, depth+1});
            }
        }
    }
    return maxDepth;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while(true) {
        int a,b; cin >> a >> b;
        if(a==-1 && b==-1) break;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    FOR(i,N) {
        int c = bfs(i);
        captains[c].push_back(i);
    }
    auto it = captains.begin();
    cout << it->first << " " << it->second.size() << '\n';
    for(auto&f: it->second) cout << f << " ";
    return 0;
}