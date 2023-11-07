#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
vector<int> graph[101];
int ans[101][101];
int visit[102][102];
int N;
bool check=false;
void dfs(int i, int j, int cnt)
{
    if(i==j && cnt != 0){
        check=true;
        return;
    }else{
        for(int k=0; k<graph[i].size();k++)
        {
            if(visit[i][graph[i][k]]!=1)
            {
                visit[i][graph[i][k]] = 1;
                dfs(graph[i][k],j,cnt+1);
            }
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N)FOR(j,N)
    {
        int a; cin >> a;
        if(a==1) graph[i].push_back(j);
    }
    FOR(i,N)FOR(j,N)
    {
        fill(&visit[0][0],&visit[101][101],0);
        dfs(i,j,0);
        if(check)
        {
            ans[i][j]=1;
        }else{
            ans[i][j]=0;
        }
        check=false;
    }
    FOR(i,N){FOR(j,N) cout << ans[i][j] << " "; cout << endl;}
}