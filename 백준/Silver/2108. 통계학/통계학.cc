#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> v;
    map<int,int> m1;
    map<int,vector<int>,greater<>> m2;
    double sum = 0;
    FOR(i,N)
    {
        int a; cin >> a;
        sum += a;
        m1[a]++;
        v.push_back(a);
    }
    for(auto&a: m1) m2[a.second].push_back(a.first);
    cout << fixed;
	cout.precision(0);
    sort(v.begin(),v.end());
    sort((m2.begin()->second).begin(),(m2.begin()->second).end());
    if(-0.5>sum/(double)N || 0<=sum/(double)N) cout << sum/(double)N << '\n';
    else cout << 0 << '\n';
    cout << v[v.size()/2] << '\n';
    if(m2.begin()->second.size()==1) cout << m2.begin()->second[0] << '\n';
    else cout << m2.begin()->second[1] << '\n';
    cout << *prev(v.end())-*v.begin() << '\n';
    return 0;
}