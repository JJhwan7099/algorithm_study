#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
long long N,M;
long long staff[1000001];
long long ans;
void binarysearch(long long int start, long long int end)
{
    long long s = 0;
    long long e = end;
    long long mid = (s+e)/2;
    while(s < e)
    {
        mid = (s+e)/2;
        long long balloon = 0;
        long long cnt = 0;
        FOR(i,N)
        {
            balloon += mid / staff[i];
            cnt += mid % staff[i];
        }
        if(balloon >= M) e = mid;
        else s = mid + 1;
        // cout << "start: " << s << " end: " << e << endl;
    }
    cout << s;
}
int main()
{
    cin >> N >> M;

    FOR(i,N)
    {
        cin >> staff[i];
    }
    binarysearch(1,1000000000000);
    return 0;
}