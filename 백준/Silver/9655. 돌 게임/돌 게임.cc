#include <iostream>
using namespace std;
int N;
int ans; // 0이면 SK출력, 1이면 CY 출력
int DP[1001];
void dp()
{
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 0;
    DP[4] = 1;
    DP[5] = 0;
    for(int i = 6; i <= N; i++)
    {
        if(DP[i-1]==1) DP[i] = 0;
        else DP[i] = 1;
    }
}
int main()
{
    cin >> N;
    dp();
    if(DP[N] == 0) cout << "SK"; else cout << "CY";
}