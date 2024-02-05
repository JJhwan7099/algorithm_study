#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M,N;
int num[1000001];
bool isprime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
void sosu()
{
    num[1]=1;
    for(int i=2; i*i<=N; i++)
    {
        if(num[i]==1) continue;
        else if(num[i]!=1 && isprime(i))
        {
            int n = i;
            while(n<=N)
            {
                num[n] = 1;
                n += i;
            }
            num[i]=0;
        }else num[i]=1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    sosu();
    for(int i=M; i<=N; i++)
    {
        if(num[i]==0) cout << i << '\n';
    }
    return 0;
}