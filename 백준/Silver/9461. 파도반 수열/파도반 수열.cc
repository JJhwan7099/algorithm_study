#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
long long DP[101];
vector<int> v;
void dp()
{
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    for(int i = 6; i <= 100; i++)
    {
        DP[i] = DP[i-1] + DP[i-5];
    }
}
int main()
{
    cin >> T;
    dp();
    FOR(i,T)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i=0; i < v.size()-1; i++) cout << DP[v[i]] << '\n';
    cout << DP[v[v.size()-1]];
}