#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int n;
int arrN[102];
int arrM[102];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> n;
    FOR(i,n) {
        int a; cin >> a;
        if(a) {
            int b; cin >> b;
            arrN[b]=1;
        }
        else {
            int b; cin >> b;
            arrM[b]=1;
        }
    }
    int maxN=0;
    int maxM=0;
    int cntN=0;
    FOR(i,N) {
        if(arrN[i]==1) {
            maxN=max(maxN,i-cntN);
            cntN=i;
        }
    }
    maxN=max(maxN,N-cntN);
    int cntM=0;
    FOR(i,M) {
        if(arrM[i]==1) {
            maxM=max(maxM,i-cntM);
            cntM=i;
        }
    }
    maxM=max(maxM,M-cntM);
    cout << maxN*maxM;
    return 0;
}