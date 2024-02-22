#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        int n; cin >> n;
        map<string,vector<string>> m;
        FOR(i,n)
        {
            string a,b;
            cin >> a >> b;
            m[b].push_back(a);
        }
        for(auto&a:m) a.second.push_back("a");
        int cnt=1;
        for(auto&a:m) cnt*=a.second.size();
        cout << cnt-1 << '\n';
    }
    return 0;
}