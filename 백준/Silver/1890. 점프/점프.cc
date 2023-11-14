#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
int graph[101][101];
long long DP[101][101];
void dp()
{
    DP[1][1] = 1;
    FOR(i,N)FOR(j,N)
    {
        if(DP[i][j]==0)continue;
        else if(graph[i][j]==0) continue;
        else{
            DP[i+graph[i][j]][j] += DP[i][j];
            DP[i][j+graph[i][j]] += DP[i][j];
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    dp();
    cout << DP[N][N];
}