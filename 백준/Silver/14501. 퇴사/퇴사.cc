#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
pair<int,int> day[16];
int DP[16];
int check(int n)
{
    int m=0;
    FOR(i,n-1) m = max(m,DP[i]);
    return m;
}
void dp()
{
    int maxv = 0;
    FOR(i,N) if(i-1+day[i].first<=N) DP[i-1+day[i].first] = max(check(i)+day[i].second,  DP[i-1+day[i].first]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> day[i].first >> day[i].second;
    dp();
    int ans=0;
    FOR(i,N) ans = max(ans,DP[i]);
    cout << ans;
    return 0;
}