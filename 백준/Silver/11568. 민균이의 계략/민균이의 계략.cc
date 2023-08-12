#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
int arr[1001];
int DP[1001];
int main()
{
    cin >> N;
    FOR(i,N) cin >> arr[i];
    int max = 0;
    FOR(i,N) DP[i] = 1;
    FOR(i,N)FOR(j,i)
    {
        if(arr[i] > arr[j])
        {
            if(DP[i]<1 + DP[j])
                DP[i] += 1;
        }
        if(DP[i]>max) max = DP[i];
    }
    cout << max;
}