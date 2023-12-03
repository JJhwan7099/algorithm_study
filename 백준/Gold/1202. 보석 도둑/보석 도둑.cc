#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
vector<pair<int,int>> m;
multiset<int> s;
int N,K;
bool cmp(pair<int,int>&a, pair<int,int>&b)
{
    return a.first > b.first;
}
int main()
{
    cin >> N >> K;
    FOR(i,N){
        int a, b; cin >> a >> b;
        m.push_back({b,a});
    }
    FOR(j,K){
        int a; cin >> a;
        s.insert(a);
    }
    sort(m.begin(),m.end(),cmp);
    long long result = 0;
    for(auto &a : m)
    {
        int v = a.first; int m = a.second;
        if(s.empty()) break;
        auto it = s.lower_bound(m);
        if(it==s.end()) continue;
        result += v;
        s.erase(it);
    }
    cout << result;
}