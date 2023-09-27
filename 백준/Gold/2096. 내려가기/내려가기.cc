#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
int graph[100001][3];
int DP[6];
int main()
{
    cin >> N;
    FOR(i,N)
    {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        int a = DP[0]; int b = DP[1]; int c = DP[2];
        int d = DP[3]; int e = DP[4]; int f = DP[5];
        DP[0] = graph[i][0] + max(a,b);
        DP[1] = graph[i][1] + max(max(a,b),c);
        DP[2] = graph[i][2] + max(b,c);
        DP[3] = graph[i][0] + min(d,e);
        DP[4] = graph[i][1] + min(min(d,e),f);
        DP[5] = graph[i][2] + min(e,f);
    }
    int high = max(max(DP[0],DP[1]),DP[2]);
    int low = min(min(DP[3],DP[4]),DP[5]);
    cout << high << " " << low;
}