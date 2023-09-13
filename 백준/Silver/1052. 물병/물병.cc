#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,K;
int bottle(int n)
{
    int nn = n;
    int cnt = 0;
    while(n > 1)
    {
        if(cnt + n <= K)
        {
            return 0;
        }
        if(n%2==1) cnt++;
        n/=2;
    }
    return cnt + 1;
}
int main()
{
    cin >> N >> K;
    if(N <= K)
    {
        cout << 0;
        return 0;
    }
    FOR(i,1000000000)
    {
        if(i < N) continue;
        int a = bottle(i);
        if(a <= K)
        {
            cout << i - N;
            return 0;
        }
    }
}