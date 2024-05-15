#include <iostream>
using namespace std;
int S,C;
long long arr[1000001];
long long e = 0;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> C;
    FOR(i,S) {
        cin >> arr[i]; e = max(e,arr[i]);
    }
    long long s = 1;
    long long mid;
    long long rlt;
    while(s<=e) {
        mid = (s+e)/2;
        long long cnt = 0;
        FOR(i,S) cnt+=(arr[i]/mid);
        if(cnt>=C) {
            rlt = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    long long sum = 0;
    FOR(i,S) sum += arr[i];
    cout << sum - (rlt*C);
    return 0;
}