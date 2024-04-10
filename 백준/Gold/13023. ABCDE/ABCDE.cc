#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> graph[2001];
map<int,int> vis;
bool b=false;
void dfs(int n, int cnt)
{
    if(cnt==5){
        b=true;
        return;
    }
    for(int i=0; i<graph[n].size(); i++)
    {
        if(vis[graph[n][i]]!=1)
        {
            vis[n]=1;
            dfs(graph[n][i],cnt+1);
            vis[n]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    FOR(i,N)
    {
        vis.clear();
        b=false;
        vis[i]=1;
        dfs(i,1);
        vis[i]=0;
        if(b)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}