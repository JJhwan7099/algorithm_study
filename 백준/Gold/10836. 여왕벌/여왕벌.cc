#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int M, N;
int graph[701][701];
vector<queue<int>> v;
int main()
{
    cin >> M >> N;
    FOR(i,M)FOR(j,M) graph[i][j]=1;
    FOR(i,N)
    {        
        queue<int> a;
        FOR(j,3)
        {
            int b; cin >> b;
            FOR(k,b)
            {
                a.push(j-1);
            }
        }
        v.push_back(a);
    }
    auto it = v.begin();
    while(N--)
    {
        queue<int> b = *it;
        for(int i=M; i>0; i--)
        {
            graph[i][1] += b.front();
            b.pop();
        }
        for(int i=2; i<=M; i++)
        {
            graph[1][i] += b.front();
            b.pop();
        }
        for(int i=2; i<=M; i++)for(int j=2; j<=M; j++)
        {
            int m = max(max(graph[i][j-1],graph[i-1][j-1]),graph[i-1][j]);
            graph[i][j] = m;
        }
        it++;
    }
    FOR(i,M){FOR(j,M) cout << graph[i][j] << " "; cout << endl;}
}