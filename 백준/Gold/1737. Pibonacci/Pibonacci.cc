#include<iostream>
#include<math.h>
#include<unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
// #define PI 3.1415926535
int n;
// long long DP[1001];
unordered_map<double,long long> m;
long long dp(double N)
{
    if(0<=N&&N<=M_PI) return 1;
    else if(m[N]!=0) return m[N];
    else  
    {
        m[N] = (dp(N-1.0) + dp((double)N-M_PI))%1000000000000000000; 
        return m[N];
    }
}
int main()
{
    cin >> n;
    cout << dp(n);
}