#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int DP[1001][10];
int dp() {
    for(int i=0; i<=9; i++) DP[1][i]=1;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<=9; j++) for(int k=0; k<=j; k++) DP[i][j] = (DP[i][j] + DP[i-1][k])%10007;
    }
    int ans = 0;
    for(int i=0; i<=9; i++) ans += DP[N][i];
    return ans % 10007;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << dp();
    return 0;
}