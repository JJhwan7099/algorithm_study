#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int people[11];
vector<int> graph[11];
int vis[11];
int ans = -1;
void dfs(int n, map<int,int> target, map<int,int>& m)
{
    m[n]=1;
    for(int i=0; i<graph[n].size(); i++)
    {
        if(m[graph[n][i]]!=1 && target[graph[n][i]]>0){
            dfs(graph[n][i],target,m);
        }
    }
}
bool check()
{
    map<int,int> a;
    map<int,int> b;
    map<int,int> m;
    FOR(i,N) if(vis[i]==1) a[i]=1; else b[i]=1;
    if(a.size()==0||b.size()==0) return false;
    dfs(a.begin()->first,a,m);
    dfs(b.begin()->first,b,m);
    // for(auto&aa:a) cout << aa.first << " "; cout << endl;
    // for(auto&aa:b) cout << aa.first << " "; cout << endl;
    FOR(i,N) if(m[i]!=1) return false;
    return true;
}
void btk(int cnt)
{
    if(check()){
        int suma = 0;
        int sumb = 0;
        FOR(i,N) if(vis[i]==1) suma += people[i]; else sumb+=people[i];
        // cout << "sum: " << abs(suma-sumb) <<'\n';
        if(ans==-1||ans>abs(suma-sumb)) ans = abs(suma-sumb);
    }
    for(int i=cnt; i<=N; i++)
    {
        if(vis[i]!=1) {
            vis[i]=1;
            btk(cnt+1);
            vis[i]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> people[i];
    }
    FOR(i,N){
        int a; cin >> a;
        FOR(j,a){
            int b; cin >> b;
            graph[i].push_back(b);
            graph[b].push_back(i);
        }
    }
    FOR(i,N/2) btk(i);
    // btk(1);
    // btk(2);
    // btk(3);
    cout << ans;
    return 0;
}