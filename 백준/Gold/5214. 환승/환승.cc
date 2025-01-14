#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,K,M;
vector<int> stations[100001];
vector<int> tubes[1001];
int vis[1001];
int bfs(){
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()) {
        int n = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(n==N) {
            return cnt;
        }
        for(auto&station:stations[n]) {
            if(vis[station]!=1) {
                vis[station]=1;
                for(auto&tube:tubes[station]) {
                    q.push({tube,cnt+1});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> M;
    FOR(i,M) {
        vector<int> v;
        FOR(j,K) {
            int n; cin >> n;
            tubes[i].push_back(n);
            stations[n].push_back(i);
        }
    }
    cout << bfs();
    return 0;
}