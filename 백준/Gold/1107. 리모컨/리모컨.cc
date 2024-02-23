#include<iostream>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
map<int,int> m;
bool check(int n)
{
    while(true)
    {
        if(m[n%10]==1) return false;
        else n/=10;
        if(n==0) break;
    }
    return true;
}
int jarisoo(int n)
{
    int cnt=0;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    if(cnt<=0) return 1;
    else return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int n;
    cin >> n;
    FOR(i,n)
    {
        int a; cin >> a;
        m[a]=1;
    }
    int c=0;
    int result = abs(N-100);
    if(jarisoo(N)>abs(N-100))
    {
        cout << abs(N-100);
        return 0;
    }else if(m.size()==10)
    {
        cout << abs(N-100);
        return 0;
    }
    while(true)
    {
        int u = N+c;
        int d = N-c;
        if(d<0) d=0;
        int ansu = 500000;
        int ansd = 500000;
        if(check(u))
        {
            ansu = jarisoo(u) + c;
        }
        if(check(d))
        {
            ansd = jarisoo(d) + c;
        }
        c++;
        if(ansu!=500000 || ansd!=500000)
        {
            cout << min(result,min(ansu, ansd));
            break;
        }
    }
    return 0;
}