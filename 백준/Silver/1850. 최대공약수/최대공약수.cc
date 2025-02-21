#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
long long A,B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    long long big = max(A,B);
    long long small = min(A,B);
    while(small!=0) {
        long long temp = big % small;
        big = small;
        small = temp;
    }
    FOR(i,big) cout << 1;
    return 0;
}