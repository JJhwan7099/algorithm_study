#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M,N;
int max_len = 0;
int arr[1000001];
int ans = 0;
void binary_search() {
    int s = 1;
    int e = arr[N];
    while(s<=e) {
        int mid = (s+e)/2;
        long long cnt = 0;
        FOR(i,N) cnt+=arr[i]/mid;
        if(cnt>=M) {
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    FOR(i,N) cin >> arr[i];
    sort(arr,arr+(N+1));
    binary_search();
    cout << ans;
    return 0;
}