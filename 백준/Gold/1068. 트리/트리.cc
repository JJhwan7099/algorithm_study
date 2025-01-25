#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, removeNode;
vector<int> tree[51];
int vis[51];
vector<int> rootNodes;
int bfs(int start) {
    int childNodeCount = 0;
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        bool isLeaf = true;
        for(int i=0; i<tree[n].size(); i++) {
            if(vis[tree[n][i]]==0) {
                q.push(tree[n][i]);
                vis[tree[n][i]] = 1;
                isLeaf = false;
            }
        }
        if(isLeaf) {
            childNodeCount++;
        }
    }
    return childNodeCount;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int parent; cin >> parent;
        if(parent!=-1) {
            tree[parent+1].push_back(i);
        }
        else rootNodes.push_back(i);
    }
    cin >> removeNode;
    tree[removeNode+1].clear();
    vis[removeNode+1] = 1;
    int ans = 0;
    for(auto&i:rootNodes) {
        if(vis[i]==0) ans+=bfs(i);
    }
    cout << ans;
    return 0;
}