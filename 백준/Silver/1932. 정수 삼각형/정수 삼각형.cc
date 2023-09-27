#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int n;
vector<int> graph[501];
int DP[501][501];
void dp()
{
    FOR(i,n)
    {
        DP[n][i] = graph[n][i];
    }
    for(int i = n-1; i > 0; i--)
    {
        FOR(j,i)
        {
            if(DP[i+1][j] > DP[i+1][j+1]) DP[i][j] = DP[i+1][j] + graph[i][j];
            else DP[i][j] = DP[i+1][j+1] + graph[i][j];
        }
    }
}
int main()
{
    cin >> n;
    FOR(i,n)
    {
        graph[i].push_back(-1);
        FOR(j,i)
        {
            int a; cin >> a;
            graph[i].push_back(a);
        }
    }
    dp();
    cout << DP[1][1];
}