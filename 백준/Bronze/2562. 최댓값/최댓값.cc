#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxNum = 0;
    int maxNumIndex = 0;
    FOR(i,9) {
        int n;
        cin >> n;
        if(n>maxNum) {
            maxNum = n;
            maxNumIndex = i;
        }
    }
    cout << maxNum << '\n' << maxNumIndex;
    return 0;
}