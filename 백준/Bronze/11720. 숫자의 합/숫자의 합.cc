#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += s[i]-'0';
    }
    cout << ans;
    return 0;
}