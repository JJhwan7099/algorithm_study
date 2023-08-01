#include <iostream>
using namespace std;
int DP[1001];
void dp(int n)//상근턴 1, 창영턴 0
{
    DP[1] = 1;//상근턴
    DP[2] = 0;//창영턴
    DP[3] = 1;//상근턴
    for(int i = 4; i <= n; i++)
    {
        if(DP[i-3] == 1)
            DP[i] = 0;
        else
            DP[i] = 1;
    }
    if(DP[n]==1)
    {
        cout<<"CY";
    }
    else cout<<"SK";
    return;
}
int main()
{
    int N; cin >> N;
    dp(N);
    return 0;
}