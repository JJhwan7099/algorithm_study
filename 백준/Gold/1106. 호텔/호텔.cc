#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int C,N;
int DP[3000] = {0,};
vector<pair<int,int>> cost;
void dp()
{
    for(auto& a : cost)
    {
        if(DP[a.first]==0 || DP[a.first] > a.second) DP[a.first] = a.second;
    }
    for(int i=0; i<=C; i++)
    {
        FOR(j,cost.size())
        {
            if(DP[i]==0) continue;
            else if(DP[i+cost[j-1].first]==0) DP[i+cost[j-1].first] = DP[i]+cost[j-1].second;
            else DP[i+cost[j-1].first] = min(DP[i+cost[j-1].first], DP[i] + cost[j-1].second);
        }
    }
}
int main()
{
    cin >> C >> N;
    FOR(i,N)
    {
        int a,b; cin >> a >> b;
        cost.push_back({b,a});
    }
    dp();
    int ans = -1;
    for(int i=C; i<=2000; i++)
    {
        if((ans==-1||ans>DP[i])&&DP[i]!=0) ans = DP[i];
    }
    cout << ans;
}