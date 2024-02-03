#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<vector<int>> ans;
map<int,int> m;
void backtracking(vector<int> v)
{
    if(v.size()==M)
    {
        ans.push_back(v);
        return;
    }else if(v.size()<M){
        int msize = m.size();
        auto it = m.begin();
        for(int i=0; i<msize; i++)
        {
            if(it->second>0)
            {
                v.push_back(it->first);
                it->second--;
                backtracking(v);
                it->second++;
                v.pop_back();
            }
            it++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N)
    {
        int a; cin >> a;
        m[a]++;
    }
    vector<int> v;
    backtracking(v);
    sort(ans.begin(), ans.end());
    for(auto&a: ans){for(auto&b: a) cout << b << " "; cout << endl;}
    return 0;
}