#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<double> v;
    FOR(i,N)
    {
        double a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    double max = *prev(v.end());
    for(int i=0; i<v.size(); i++)
    {
        v[i] = v[i]/max * 100;
    }
    double sum = 0;
    for(auto&a: v) sum+=a;
    cout << sum/(double)v.size();
    return 0;
}