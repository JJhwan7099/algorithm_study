#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int ground[301][301];
int DP[301][301];
int N,M;
void dp()
{
    DP[1][1] = ground[1][1];
    
    FOR(i,N)FOR(j,M)
    {
        if(i==1&&j!=1)
        {
            DP[i][j] = DP[i][j-1]+ground[i][j];
        }
        else if(i!=1&&j==1)
        {
            DP[i][j] = DP[i-1][j]+ground[i][j];
        }
        else if(i!=1&&j!=1)
        {
            DP[i][j] = max(DP[i-1][j],DP[i][j-1])+ground[i][j];
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,M) cin >> ground[i][j];
    dp();
    cout << DP[N][M];
}