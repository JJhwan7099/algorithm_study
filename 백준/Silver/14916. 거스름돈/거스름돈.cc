#include <iostream>
using namespace std;
int n;
int DP[100001] = {1,};
void dp()
{
    DP[1] = -1;
    DP[2] = 1;
    DP[3] = -1;
    DP[4] = 2;
    DP[5] = 1;
    for(int i = 6; i <= n; i++)
    {
        DP[i] = n/2;
        if(DP[i-2] != -1 && DP[i] > DP[i-2] + 1) DP[i] = DP[i-2] + 1;
        if(DP[i-5] != -1 && DP[i] > DP[i-5] + 1) DP[i] = DP[i-5] + 1;
    }
}
int main()
{
    cin >> n;
    dp();
    cout << DP[n];
}