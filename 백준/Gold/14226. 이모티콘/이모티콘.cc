#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int S;
int visited[10001][10001];
int bfs() {
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,0},0});
    while(!q.empty()) {
        int display = q.front().first.first;
        int clipboard = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        if(display == S) return depth;
        if(clipboard > 0 && display+clipboard<=1000) {
            if(visited[display+clipboard][clipboard]==0) {
                q.push({{display+clipboard,clipboard},depth+1});
                visited[display+clipboard][clipboard]=1;
            }
        }
        if(display<=1000) {
            if(visited[display][display]==0){
                q.push({{display,display},depth+1});
                visited[display][display]=1;
            }
        }
        if(display-1 > 0 && display-1 <= 1000 && clipboard<=1000){
            if(visited[display-1][clipboard]==0) {
                q.push({{display-1,clipboard},depth+1});
                visited[display-1][clipboard]=1;
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    cout << bfs();
    return 0;
}