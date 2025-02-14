#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int a,b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
    return 0;
}