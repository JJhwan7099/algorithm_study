#include<iostream>
using namespace std;
int N;
long long DP[81];
void dp()
{
    DP[1] = 1;
    DP[2] = 1;
    for(int i=3; i<=80; i++)
    {
        DP[i] = DP[i-1] + DP[i-2];
    }
}
int main()
{
    cin >> N;
    dp();
    cout << 2 * (DP[N] + DP[N] + DP[N-1]);
}