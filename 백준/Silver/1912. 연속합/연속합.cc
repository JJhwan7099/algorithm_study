#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int DP[100001];
int num[100001];
int N;
void dp()
{
    FOR(i,N)
    {
        DP[i] = num[i];
    }
    for(int i=2; i<=N; i++)
    {
        if(DP[i-1]+num[i] > DP[i]) DP[i] = DP[i-1]+num[i];
    }
}
int main()
{
    cin >> N;
    FOR(i,N)
    {
        cin >> num[i];
    }
    dp();
    int ans = DP[1];
    FOR(i,N) if(ans < DP[i]) ans = DP[i];
    cout << ans;
}