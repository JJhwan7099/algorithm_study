#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N, M;
int num[100001];
pair<int,int> range[100001];
int DP[100001];
vector<int> answer;
void doing()
{
    FOR(i,N) DP[i] = DP[i-1] + num[i];
    FOR(i,M)
    {
        int s = range[i].first; int e = range[i].second;
        int ans = DP[e] - DP[s-1];
        answer.push_back(ans);
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N) cin >> num[i];
    FOR(i,M) {int a,b; cin >> a >> b; range[i] = make_pair(a,b);}
    doing();
    for(auto&a:answer) cout << a << '\n';
} 