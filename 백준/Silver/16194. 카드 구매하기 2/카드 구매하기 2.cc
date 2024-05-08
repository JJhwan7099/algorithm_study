#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int cost[1001];
int DP[1001];
void dp() {
    FOR(i,N) DP[i] = cost[i];
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            DP[i] = min(DP[i],DP[i-j]+cost[j]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> cost[i];
    dp();
    cout << DP[N];
    return 0;
}