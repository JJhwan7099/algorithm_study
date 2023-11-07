#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int A,B;
int ans = -1;
void bfs(int n, int r)
{
    unordered_map<long long,int> m;
    queue<pair<long long,int>> q;
    q.push({n,1});
    m[n] = 1;
    while(q.size()>0)
    {
        long long a = q.front().first;
        int cnt = q.front().second;
        if(a==r)
        {
            ans = cnt;
            return;
        }
        else
        {
            if(a*10+1 <= r && m[a*10+1]!=1)
            {
                m[a*10+1] = 1;
                q.push({a*10+1,cnt+1});
            }
            if(a*2 <= r && m[a*2]!=1)
            {
                m[a*2] = 1;
                q.push({a*2,cnt+1});
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> A >> B;
    bfs(A,B);
    cout << ans;
}
