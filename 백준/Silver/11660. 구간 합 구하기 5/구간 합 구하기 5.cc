#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M;
int graph[1025][1025];
int DP[1025][1025];
vector<int> ans;
void dp()
{
    DP[1][1] = graph[1][1];
    int sum = DP[1][1];
    FOR(i,N) FOR(j,N)
    {
        if(i==1 && j==1) continue;
        else{
            DP[i][j] = sum + graph[i][j];
        }
        sum += graph[i][j];
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    dp();
    // FOR(i,N){FOR(j,N) cout << DP[i][j] << " "; cout << endl;}
    FOR(i,M)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result;
        if(x1==x2 && y1==y2)
        {
            ans.push_back(graph[x1][y1]);
            continue;
        }
        if(y1-1!=0) result = DP[x2][y2] - DP[x1][y1-1];
        else result = DP[x2][y2] - DP[x1-1][N];
        for(int j=x1+1; j<=x2; j++)
        {
            if(y1 > 1) result -= DP[j][y1-1] - DP[j-1][N];
            if(y2 < N) result -= DP[j-1][N] - DP[j-1][y2];
        }
        ans.push_back(result);
    }
    for(auto&a : ans) cout << a <<'\n';
}