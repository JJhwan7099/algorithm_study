#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
long long DP[1000005];
int N;
void dp() {
    DP[1] = 1;
    DP[2] = 2;
    for(int i=3; i<=N; i++) {
        DP[i] = (DP[i-1] + DP[i-2])%15746;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp();
    cout << DP[N]%15746;
    return 0;
}