#include <iostream>
using namespace std;
int n;
int DP[10000001];
void dp()
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 5;
    for(int i = 5; i <= n; i++)
    {
        DP[i] = (DP[i-1] + DP[i-2])%10;
    }
    return;
}
int main()
{
    cin >> n;
    dp();
    cout << DP[n];
}