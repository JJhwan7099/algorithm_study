#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M,X;
int dis[1001][1001];
vector<int> route[1001];
int vis[1001];
int results[1001];
#define FOR(i,N) for(int i=1; i<=N; i++)
int findDistance(int n, int e) {
    queue<int> q;
    FOR(i,N) vis[i]=-1;
    vis[n]=0;
    q.push(n);
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        if(s==e) continue;
        for(int i=1; i<=route[s].size(); i++) {
            if(dis[s][route[s][i-1]]==0) continue;
            else if( route[s][i-1]!=n && (vis[s]+dis[s][route[s][i-1]])<vis[route[s][i-1]] || vis[route[s][i-1]]==-1) {
                q.push(route[s][i-1]);
                vis[route[s][i-1]] = vis[s]+dis[s][route[s][i-1]];
            }
        }
    }
    return vis[e];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> X;
    FOR(i,M) {
        int x, y;
        cin >> x >> y;
        cin >> dis[x][y];
        route[x].push_back(y);
    }
    int ans = 0;
    FOR(i,N) {
        results[i] = findDistance(i,X);
        results[i] += findDistance(X,i);
        ans = max(ans, results[i]);
    }
    cout << ans;
    return 0;
}