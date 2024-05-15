#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,K;
int arr[10001];
int ans = 0;
void binary_search() {
    long long s = 1;
    long long e = arr[N];
    while(s<=e) {
        long long mid = (s+e)/2;
        long long cnt = 0;
        FOR(i,N) if(mid!=0) cnt+=arr[i]/mid;
        if(cnt>=K) {
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    FOR(i,N) cin >> arr[i];
    sort(arr,arr+(N+1));
    binary_search();
    cout << ans;
    return 0;
}