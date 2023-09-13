#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
int num[100001];
long long DP[100001];
void dp()
{
    FOR(i,N)
    {
        if(i*i > N) break;
        DP[i*i] = 1;
    }
    FOR(i,N)
    {
        FOR(j,N)
        {
            if(i+j*j > N) break;
            if(DP[i+j*j]==0) DP[i+j*j] = DP[i] + 1;
            else DP[i+j*j] = min(DP[i+j*j], DP[i]+1);
        }
    }
}
int main()
{
    cin >> N;
    dp();
    cout << DP[N];
}