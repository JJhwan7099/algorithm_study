#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, K;
int visit[100001];
void bfs()
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{N,K},0});
    while(q.size() > 0)
    {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int cnt = q.front().second;
        if(a==b)
        {
            cout << cnt;
            return;
        }else{
            if(2*a <= 100000 && 2*a >= 0 && visit[2*a]!=1)
            {
                visit[2*a] = 1;
                q.push({{2*a,b},cnt});
            }
            if(a-1 >= 0 && visit[a-1]!=1)
            {
                visit[a-1] = 1;
                q.push({{a-1,b},cnt+1});
            }
            if(a+1 <= 100000 && visit[a+1]!=1)
            {
                visit[a+1] = 1;
                q.push({{a+1,b},cnt+1});
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N >> K;
    bfs();
}