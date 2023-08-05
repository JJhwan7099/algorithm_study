#include<iostream>
using namespace std;
int n; long long DP[1005];
int ans;
int max(int a, int b){if(a>b)return a; else return b;}
void dp()
{
    DP[1] = 1;
    DP[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        DP[i] = (DP[i-1] + DP[i-2])%10007;
    }
    
}
int main()
{
    cin >> n;
    dp();
    cout << DP[n];
}