#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<int> budget;
int M=0;
int total_budget;
int ans = 0;
bool check(int n) {
    int cnt = 0;
    for(auto&a: budget) if(a>n) cnt+=n; else cnt+=a;
    if(cnt<=total_budget) return true;
    else return false;
}
void binary_search() {
    int s = 1;
    int e = M;
    while(s<=e) {
        int mid = (s+e)/2;
        if(check(mid)) {
            if(ans==0) ans = mid;
            else ans = max(ans,mid);
            s = mid+1;
        }else e = mid-1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int a; cin >> a; budget.push_back(a);
        M = max(a,M);
    }
    cin >> total_budget;
    binary_search();
    cout << ans;
    return 0;
}