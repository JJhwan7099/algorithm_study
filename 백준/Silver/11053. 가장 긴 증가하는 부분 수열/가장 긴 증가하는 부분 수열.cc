#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1001];
int DP[1001];
void dp()
{
    FOR(i,N) DP[i] = 1;
    for(int i=1; i<=N; i++)
    {
        for(int j=i+1; j<=N; j++)
        {
            if(arr[j] > arr[i]) DP[j] = max(DP[j],DP[i]+1);
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N)
    {
        cin >> arr[i];
    }
    dp();
    int max = DP[1];
    FOR(i,N) if(DP[i]>max) max = DP[i];
    cout << max;
}