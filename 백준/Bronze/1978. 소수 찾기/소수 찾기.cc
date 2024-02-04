#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int num[1001];
bool isprime(int n)
{
    bool b = true;
    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            b=false;
            break;
        }
    }
    if(b) return true;
    else return false;
}
void start()
{
    num[1]=1;
    for(int i=2; i<=1000; i++)
    {
        if(num[i]!=1 && isprime(i))
        {
            int n = i;
            while(n<=1000)
            {
                num[n] = 1;
                n+=i;
            }
            num[i]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    cin >> N;
    start();
    FOR(i,N)
    {
        int n; cin >> n;
        if(num[n]==0) ans++;
    }
    cout << ans;
    return 0;
}