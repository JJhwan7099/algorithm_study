#include <iostream>
#include <vector>
using namespace std;
int DP[11];
int dp(int n)
{
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i = 4; i <= n; i++)
    {
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }
    return DP[n];
}
int main()
{
    int T; cin >> T;
    vector<int>num;
    for(int i = 0; i < T; i++)
    {
        int a; cin >> a;
        num.push_back(dp(a));
    }
    for(auto&a : num)
    {
        cout << a << '\n';
    }
    return 0;
}