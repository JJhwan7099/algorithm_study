#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M, R;
vector<int> v[100001];
int main()
{
    cin >> N >> M >> R;
    FOR(i,M)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    FOR(i,N) sort(v[i].begin(), v[i].end());
    int cnt = 1;
    int visit[100001];
    queue<int> q;
    q.push(R);
    visit[R]=1;
    int ans[100001] = {0,};
    while(q.size()>0)
    {
        int a = q.front();
        ans[a]= cnt++;
        for(int i=0; i<v[a].size(); i++)
        {
            if(visit[v[a][i]]!=1)
            {
                visit[v[a][i]]=1;
                q.push(v[a][i]);
            }
        }
        q.pop();
    }
    FOR(i,N)
    {
        cout << ans[i] << '\n';
    }
}