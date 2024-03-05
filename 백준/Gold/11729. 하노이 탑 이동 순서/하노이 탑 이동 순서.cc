#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int ans=0;
vector<pair<int,int>> v;
void btk(int n, int s, int m, int e)
{
    if(n<=1) 
    {
        ans++;
        v.push_back({s,e});
    }
    else{
        btk(n-1, s, e, m);
        ans++;
        v.push_back({s,e});
        btk(n-1, m, s, e);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    btk(N,1,2,3);
    cout << ans << '\n';
    for(auto&a:v) cout << a.first << " " << a.second << '\n';
    return 0;
}