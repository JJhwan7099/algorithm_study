#include<iostream>
#include<string>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int cnt1=0;
    int cnt2=0;
    for(int i=2; i<=N; i++)
    {
        int n = i;
        while(n%2==0 || n%5==0)
        {
            if(n%2==0)
            {
                cnt1++;
                n/=2;
            }
            if(n%5==0)
            {
                cnt2++;
                n/=5;
            }
        }
    }
    if(cnt1<=cnt2) cout << cnt1;
    else cout << cnt2;
    return 0;
}