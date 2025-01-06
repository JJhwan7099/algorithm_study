#include <iostream>
#include <math.h>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2,m1,m2;
    cin >> n1 >> m1 >> n2 >> m2;
    int N= n1*m2+n2*m1;
    int M = m1*m2;
    int mini = min(N,M);
    int maxi = max(N,M);
    while(maxi%mini) {
        int n=maxi%mini;
        maxi=mini;
        mini=n;
    }
    cout << N/mini << " " << M/mini;
    return 0;
}