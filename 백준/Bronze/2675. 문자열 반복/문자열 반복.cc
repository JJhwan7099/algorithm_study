#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;
        string s;
        cin >> n >> s;
        for(int i=0; i<s.length(); i++) {
            for(int j=0; j<n; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}