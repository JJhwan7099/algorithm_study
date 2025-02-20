#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,S;
int sum[100001];
int result = 2000000000;
void go(int start, int end) {
    // if(sum[end]-sum[start]>=S) {
    //     result = end-start;
    //     go(start+1,end);
    //     go(start,end-1);
    // }
    while(end<=N) {
        // cout << start << " " << end << endl;
        if(sum[end]-sum[start]>=S) {
            result = min(result,end-start);
            start++;
        } else end++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    FOR(i,N) {
        int n; cin >> n;
        sum[i] = sum[i-1]+n;
    }
    go(0,0);
    if(result!=2000000000) cout << result;
    else cout << 0;
    return 0;
}