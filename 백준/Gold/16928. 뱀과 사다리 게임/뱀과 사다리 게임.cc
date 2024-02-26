#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
map<int,int> m;
int visit[101];
void bfs()
{
    queue<pair<int,int>> q;
    q.push({1,0});
    visit[1] = 1;
    while(!q.empty())
    {
        int n = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(n==100)
        {
            cout << cnt;
            return;
        }
        for(int i=1; i<=6; i++)
        {
            if(visit[n+i]!=1)
            {
                if(m[n+i]==0)
                {
                    visit[n+i]=1;
                    q.push({n+i,cnt+1});
                }else{
                    visit[n+i]=1;
                    q.push({m[n+i],cnt+1});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M; cin >> N >> M;
    FOR(i,N+M)
    {
        int a,b; cin >> a >> b;
        m[a] = b;
    }
    bfs();
    return 0;
}