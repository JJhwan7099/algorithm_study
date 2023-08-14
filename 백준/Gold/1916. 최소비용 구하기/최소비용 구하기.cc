#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N, M;
vector<int> v1[1001];
int tot[1001];
int cost[1001][1001];
bool visit[1001][1001];
bool zerocheck[1001][1001];
void search(int start)
{
    queue<int> q1;
    q1.push(start);
    while(!q1.empty())
    {
        int a = q1.front();
        for(int i = 0; i < v1[a].size(); i++)
        {
            if(visit[a][v1[a][i]] != 1)
            {
                q1.push(v1[a][i]);
                visit[a][v1[a][i]] = 1;
            }
            if(tot[v1[a][i]] > tot[a] + cost[a][v1[a][i]] || tot[v1[a][i]] == -1)
            {
                if(tot[v1[a][i]] == -1) tot[v1[a][i]] = 0;
                if(tot[a] == -1) tot[a] = 0;;
                tot[v1[a][i]] = tot[a] + cost[a][v1[a][i]];
                q1.push(v1[a][i]);
            }
            // cout << a << " => " << v1[a][i] << " cost: " << tot[v1[a][i]] << '\n';
        }
        q1.pop();
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,M)
    {
        int a,b; cin >> a >> b;
        v1[a].push_back(b);
        int c; cin >> c;
        if(zerocheck[a][b] == true)
        {
            continue;
        }
        else if(c == 0)
        {
            zerocheck[a][b] = 1;
            cost[a][b] = 0;
            continue;
        }
        else if(c < cost[a][b] || zerocheck[a][b] != 1)
        {
            if(zerocheck[a][b] != 1)
            {
                if(cost[a][b]==0)
                    cost[a][b] = c;
                else if(c < cost[a][b])
                {
                    cost[a][b] = c;
                }
            }
        }
    }
    int start, end; cin >> start >> end;
    fill(&tot[0],&tot[1001],-1);
    search(start);
    cout << tot[end];
}