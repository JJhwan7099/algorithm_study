#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int> m;
    int n; cin >> n;
    FOR(i,n)
    {
        int a; cin >> a;
        m[a]++;
    }
    auto it = m.begin();
    while(it!=m.end())
    {
        for(int i=0; i<it->second; i++)
        {
            cout << it->first << '\n';
        }
        it++;
    }
    return 0;
}