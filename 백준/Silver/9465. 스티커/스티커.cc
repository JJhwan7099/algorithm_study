#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int sticker[2][100002];
int DP[2][100002];
void dp(int n)
{
    DP[0][1] = sticker[0][1];
    DP[1][1] = sticker[1][1];
    for(int i=2; i<=n; i++)
    {
        if(DP[1][i-1]+sticker[0][i] < DP[1][i-1]+sticker[0][i+1])
        {
            DP[0][i] = max(DP[1][i-1] + sticker[0][i],DP[0][i]);
            DP[0][i+1] = max(DP[0][i+1],DP[1][i-1]+sticker[0][i+1]);
        }
        else{
            DP[0][i] = max(DP[0][i],DP[1][i-1] + sticker[0][i]);
        }
        if(DP[0][i-1]+sticker[1][i] < DP[0][i-1]+sticker[1][i+1])
        {
            DP[1][i] = max(DP[0][i-1]+sticker[1][i],DP[1][i]);
            DP[1][i+1] = max(DP[1][i+1],DP[0][i-1]+sticker[1][i+1]);
        }else{
            DP[1][i] = max(DP[1][i],DP[0][i-1] + sticker[1][i]);
        }
    }
}
int main()
{
    vector<int> ans;
    cin >> T;
    int c = T;
    while(c--)
    {
        int n; cin >> n;
        FOR(i,2)FOR(j,n+1)
        {
            DP[i-1][j] = 0;
            sticker[i-1][j] = 0;
        }
        FOR(i,2)
        {
            FOR(j,n)
            {
                cin >> sticker[i-1][j];
            }
        }
        dp(n);
        ans.push_back(max(DP[0][n],DP[1][n]));
    }
    for(auto&a : ans) cout << a << '\n';
}