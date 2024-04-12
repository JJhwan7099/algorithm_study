#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M;
int seat[42];
int DP[42];
int soonseo[41];
int ans = 1;
void dp()
{
    soonseo[1]=1;
    soonseo[2]=2;
    soonseo[3]=3;
    for(int i=4; i<=N; i++)
    {
        soonseo[i] = soonseo[i-1]+soonseo[i-2];
    }
    FOR(i,N) DP[i]=1;
    for(int i=2; i<=N; i++)
    {
        if(seat[i]==-1) continue;
        else if(seat[i-1]!=-1) {
            DP[i] = DP[i-1]+1;
            DP[i-1]=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M){
        int n; cin >> n;
        seat[n]=-1;
    }
    dp();
    FOR(i,N) ans*=soonseo[DP[i]];
    cout << ans;
    return 0;
}