#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int t[501];
int beforecnt[501];
vector<int> start;
map<int,vector<int>> m;
int result[501];
int vis[501];
void btk(int n, int now) {
    now+=t[n];
    result[n]=now;
    for(auto&a:m[n]) {
        beforecnt[a]--;
        if(beforecnt[a]==0) btk(a,max(vis[a],now));
        else {
            vis[a]=max(vis[a],now);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int cnt=0;
        while(true){
            cnt++;
            int n; cin >> n;
            if(n==-1){
                if(cnt==2){
                    start.push_back(i);
                }
                break;
            }
            else{
                if(cnt==1) {
                    t[i]=n;
                }
                else {
                    beforecnt[i]++;
                    m[n].push_back(i);
                }
            }
        }
    }
    for(auto&s:start) btk(s,0);
    FOR(i,N) cout << result[i] << '\n';
    return 0;
}