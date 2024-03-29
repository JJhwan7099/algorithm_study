#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int color[1002][3];
int DP[1003][3];
int ans = 10000000;
int dp(int s)
{
    FOR(i,N)for(int j=0; j<3; j++) DP[i][j]=100000000;
    DP[1][s] = color[1][s];
    for(int i=2; i<=N; i++)
    {
        DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + color[i][0];
        DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + color[i][1];
        DP[i][2] = min(DP[i-1][1], DP[i-1][0]) + color[i][2];
    }
    DP[N][s] = 100000000;
    return min(DP[N][0],min(DP[N][1],DP[N][2]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> color[i][0] >> color[i][1] >> color[i][2];
    for(int i=0; i<3; i++) ans = min(ans,dp(i));
    cout << ans;
    return 0;
}