#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int DP[41][2];
void dp()
{
    DP[0][0] = 1; DP[0][1] = 0;
    DP[1][0] = 0; DP[1][1] = 1;

    for(int i=2; i<=40; i++)
    {
        DP[i][0] = DP[i-1][0]+DP[i-2][0];
        DP[i][1] = DP[i-1][1]+DP[i-2][1];
    }
}
int main()
{
    vector<pair<int,int>>ans;
    cin >> T;
    dp();
    FOR(i,T)
    {
        int n; cin >> n;
        ans.push_back({DP[n][0],DP[n][1]});
    }
    for(auto&a:ans) cout << a.first << " " << a.second << '\n';
}