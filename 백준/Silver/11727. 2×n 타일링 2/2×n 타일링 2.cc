#include<iostream>
using namespace std;
int n;
int DP[1001];
void dp()
{
    DP[1] = 1;
    DP[2] = 3;
    for(int i=3;i<=n;i++)
    {
        DP[i] = (2*(DP[i-2]) + DP[i-1])%10007;
    }
}
int main()
{
    cin >> n;
    dp();
    cout << DP[n];
}