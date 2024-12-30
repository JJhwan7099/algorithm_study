#include <iostream>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
unordered_map<string,int> um;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        um.clear();
        int N; cin >> N;
        FOR(i,N) {
            string num;
            cin >> num;
            um[num]=1;
        }
        bool b = true;
        for(auto&a:um) {
            string s = a.first;
            string ss = "";
            for(int i=0; i<s.length()-1; i++) {
                string sss = ss+s[i];
                ss = sss;
                if(um.find(sss)!=um.end()) {
                    cout << "NO\n";
                    b = false;
                    break;
                }
            }
            if(!b) break;
        }
        if(b) {
            cout << "YES\n";
        }
    }
    return 0;
}