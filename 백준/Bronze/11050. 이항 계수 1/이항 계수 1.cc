#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    int ans = 1;
    for(int i=N; i>N-K; i--) ans*=i;
    for(int i=1; i<=K; i++) ans/=i;
    cout << ans;
    return 0;
}