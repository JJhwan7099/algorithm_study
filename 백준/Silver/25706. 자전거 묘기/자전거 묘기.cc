#include <iostream>
using namespace std;
int n; 
int N[200001];
int DP[200001];
void dp()
{
    DP[n] = 1;
    for(int i = n-1; i >= 1; i--)
    {
        if(N[i]+1+i <= n)
            DP[i] = 1+DP[N[i]+1+i];
        else
            DP[i] = 1;
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> N[i];
    }
    dp();
    for(int i = 1; i <= n; i++)
    {
        if(i == n)
        {
            cout << DP[i];
            return 0;
        }
        cout << DP[i] << " ";
    }
    return 0;
}