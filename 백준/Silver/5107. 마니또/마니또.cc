#include <iostream>
#include <string>
#include <vector>
#define FOR(i,N) for(int i=1; i<=N; i++)
using namespace std;
int N;
vector<pair<string,string>> v;
vector<int> manitto[21];
int visit[21];
int checkp;
int cnt=0;
void dfs(int n)
{
    visit[n] = 1;
    for(int i=0; i<manitto[n].size(); i++)
    {
        if(visit[manitto[n][i]]==1&&checkp==manitto[n][i])
        {
            cnt++;
            return;
        }
        else if(visit[manitto[n][i]]!=1)
        {
            dfs(manitto[n][i]);
        }
    }
}
int main()
{
    int c = 1;
    while(c)
    {
        v.clear();
        FOR(i,20) manitto[i].clear();
        FOR(i,20) visit[i] = 0;
        cnt = 0;
        cin >> N;
        if(N==0) break;
        else{
            FOR(i,N)
            {
                string a, b;
                cin >> a >> b;
                v.push_back({a,b});
            }
            FOR(i,v.size())
            {
                FOR(j,v.size())
                {
                    if(v[i-1].second==v[j-1].first)
                    {
                        manitto[i].push_back(j);
                    }
                }
            }
            FOR(i,N)
            {
                if(visit[i]!=1)
                {
                    checkp = i;
                    dfs(i);
                }
            }
            cout << c << " " << cnt << '\n';
            c++;
        }
    }
}