#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int checkPrimeNumber[1000001];
void findPrimeNumber() {
    for(int i=2; i<=1000000; i++) {
        if(checkPrimeNumber[i]==0) {
            for(int j=i*2; j<=1000000; j+=i) {
                checkPrimeNumber[j] = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    findPrimeNumber();
    while(true) {
        int n; cin >> n;
        bool b = false;
        if(n==0) break;
        else {
            for(int i=3; i<=n; i++) {
                if(checkPrimeNumber[i]==0 && checkPrimeNumber[n-i]==0) {
                    cout << n << " = " << i << " + " << n-i << "\n";
                    b = true;
                    break;
                }
            }
            if(!b) cout << "Goldbach's conjecture is wrong.\n";
        }
    }
    return 0;
}