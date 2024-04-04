#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int DP[101][10];
void dp()
{
    FOR(i,9) DP[1][i]=1;
    for(int i=2; i<=N; i++)
    {
        DP[i][0] = DP[i-1][1];
        DP[i][9] = DP[i-1][8];
        FOR(j,8) DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%1000000000;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp();
    int ans = 0;
    for(int i=0; i<=9; i++) ans = (ans+DP[N][i])%1000000000;
    cout << ans;
    return 0;
}