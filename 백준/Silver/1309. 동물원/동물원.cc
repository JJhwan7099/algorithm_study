#include<iostream>
using namespace std;
int N;
long long int DP[100001][3];
int main()
{
    cin >> N;
    DP[1][0] = 1; // 한마리도 안두는 경우
    DP[1][1] = 1; // 왼쪽에 한마리 두는 경우
    DP[1][2] = 1; // 오른쪽에 한마리 두는 경우
    for(int i=2; i<=N; i++)
    {
        DP[i][0] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2])%9901;
        DP[i][1] = (DP[i-1][0] + DP[i-1][2])%9901;
        DP[i][2] = (DP[i-1][0] + DP[i-1][1])%9901;
    }
    int ans = (DP[N][0] + DP[N][1] + DP[N][2])%9901;
    cout << ans;
}