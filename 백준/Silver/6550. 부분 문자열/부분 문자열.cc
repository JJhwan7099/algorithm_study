#include <iostream>
#include <string>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    while(cin>>s>>t) {
        int sidx = 0;
        for(int i=0; i<t.size(); i++) {
            if(s[sidx] == t[i]) sidx++;
        }
        if(sidx == s.size()) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}