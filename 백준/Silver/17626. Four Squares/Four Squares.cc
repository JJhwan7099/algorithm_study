#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int num[50001];
int DP[50001];
int N;
void dp()
{
    for(int i=1; i<=N; i++)
    {
        DP[i]=DP[i-1]+1;
        for(int j=1; j*j<=i; j++)
        {
            DP[i] = min(DP[i],DP[i-j*j]+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,sqrt(N)) num[i*i]=1;
    dp();
    cout << DP[N];
    return 0;
}