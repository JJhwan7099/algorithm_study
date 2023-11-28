#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<int> v[51];
int fr[51] = {0,};
int visit[51] = {0,};
void bfs(int n)
{
    visit[n] = 1;
    queue<pair<int,int>> q;
    q.push({n,0});
    while(!q.empty())
    {
        int a = q.front().first;
        int cnt = q.front().second;
        if(cnt<=2)
        {
            if(a!=n) fr[n]++;
        }else break;
        for(int i=0; i<v[a].size(); i++)
        {
            if(visit[v[a][i]]!=1)
            {
                q.push({v[a][i],cnt+1});
                visit[v[a][i]]=1;
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N;
    FOR(i,N)FOR(j,N)
    {
        char a; cin >> a;
        if(a=='Y') 
        {
            v[i].push_back(j);
        }
    }
    FOR(i,N) 
    {
        FOR(j,N) visit[j]=0;
        bfs(i);
    }
    int ans = fr[0];
    FOR(i,N) if(ans<fr[i]) ans = fr[i];
    cout << ans;
}