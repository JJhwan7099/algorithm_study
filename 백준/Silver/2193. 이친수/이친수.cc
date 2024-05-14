#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
long long DP[91][2];
int N;
void dp() {
    DP[1][0] = 0; DP[1][1] = 1;
    for(int i=2; i<=N; i++) {
        DP[i][0] = DP[i-1][0] + DP[i-1][1];
        DP[i][1] = DP[i-1][0];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp();
    cout << DP[N][0]+DP[N][1];
    return 0;
}