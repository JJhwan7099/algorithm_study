#include<iostream>
using namespace std;
int DP[1001];
int num[1001];
int n;
void dp()
{
    for(int i=1; i<=n; i++) DP[i] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if(num[i]>num[j]) DP[j] = max(DP[j], DP[i] + 1);
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> num[i];
    }
    dp();
    int ans = DP[1];
    for(int i=2; i<=n; i++) ans = max(ans, DP[i]);
    cout << ans;
}