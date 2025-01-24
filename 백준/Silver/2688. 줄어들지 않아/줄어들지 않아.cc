#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
long long DP[65][10];
void dp() {
    for(int i=0; i<10; i++) {
        DP[1][i]=1;
    }
    for(int i=2; i<65; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<=j; k++) {
                DP[i][j] += DP[i-1][k];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    dp();
    while(T--) {
        int n;
        cin >> n;
        long long result = 0;
        for(int i=0; i<10; i++) {
            result += DP[n][i];
        }
        cout << result << '\n';
    }
    return 0;
}