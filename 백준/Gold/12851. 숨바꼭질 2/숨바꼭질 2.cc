#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, K;
int acnt = 0;
int ans;
void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,0});
    int visit[100001];
    while(q.size()>0)
    {
        int n = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(ans!=0 && cnt > ans) continue;
        else{
            if(n-1>=0)
            {
                if(n-1==K)
                {
                    ans = cnt;
                    acnt++;
                    continue;
                }
                else if(visit[n-1] >= cnt + 1 || visit[n-1] == 0)
                {
                    visit[n-1] = cnt+1;
                    q.push({n-1,cnt+1});
                }
            }
            if(n+1<=100000)
            {
                if(n+1==K)
                {
                    ans = cnt;
                    acnt++;
                    continue;
                }
                else if(visit[n+1] >= cnt + 1 || visit[n+1] == 0)
                {
                    visit[n+1] = cnt+1;
                    q.push({n+1,cnt+1});
                }
            }
            if(n*2<=100000)
            {
                if(n*2==K)
                {
                    ans = cnt;
                    acnt++;
                    continue;
                }
                else if(visit[n*2] >= cnt + 1 || visit[n*2] == 0)
                {
                    visit[n*2] = cnt+1;
                    q.push({n*2,cnt+1});
                }
            }
        }
    }
}
int main()
{
    cin >> N >> K;
    if(K==0 && N!=K)
    {
        cout << N << '\n' << 1;
        return 0;
    }
    if(N==K)
    {
        cout << 0 << '\n' << 1;
        return 0;
    }
    bfs(N, K);
    cout << ans + 1 << '\n' << acnt;
}