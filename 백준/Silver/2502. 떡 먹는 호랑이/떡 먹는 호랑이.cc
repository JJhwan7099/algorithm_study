#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int D, K;
int DP[31];
void dp() {
    for(int j=K-1; j>2; j--) {
        DP[D-1] = j;
        for(int i= D; i>2; i--) {
            if(DP[i-1]>=DP[i]-DP[i-1] && DP[i]-DP[i-1]>0) DP[i-2] = DP[i] - DP[i-1];
            else {
                continue;
            }
            if(DP[1]!=0 && DP[2]!=0) 
            {
                cout << DP[1] << '\n' << DP[2];
                return;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> D >> K;
    DP[D]=K;
    dp();
    return 0;
}