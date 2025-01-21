#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1001];
int DP[1001];
void dp() {
    FOR(i,N) {
        for(int j=0; j<=N; j++) {
            if(j==0 || DP[j]!=0) {
                if(j+i<=N) DP[j+i] = max(DP[j+i], DP[j]+arr[i]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> arr[i];
    dp();
    cout << DP[N];
    return 0;
}