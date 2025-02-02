#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int maxHoney = 0;
int honey[100001];
int honeySum[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> honey[i];
        honeySum[i] = honeySum[i-1]+honey[i];
    }
    int result = 0;
    FOR(i,N) {
        if(i>2) {
            for(int j=2; j<i; j++) {
                result = max(result,honeySum[i]-honeySum[1]+honeySum[i]-honeySum[j]-honey[j]);
                // cout << honeySum[i]-honeySum[1]+honeySum[i]-honeySum[j]-honey[j] << " " << i  << " " << j << endl;
            }
        }
        if(N-i>1) {
            for(int j=N-1; j>i; j--) {
                result = max(result,honeySum[N-1]-honeySum[i-1]+honeySum[j-1]-honeySum[i-1]-honey[j]);
                // cout << honeySum[N-1]-honeySum[i-1]+honeySum[j-1]-honeySum[i-1]-honey[j] << " " << i << " " << j << endl;
            }
        }
        if(i>1 && N-i>0) {
            result = max(result,honeySum[i]-honeySum[1]+honeySum[N-1]-honeySum[i-1]);
        }
    }
    cout << result;
    return 0;
}