#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int graph[16][16];
int visit[16][16];
int ans = 0;
int dx[3] = {-1,-1,-1};
int dy[3] = {-1,0,1};
bool check(int x, int y)
{
    for(int i=0; i<3; i++)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        while(X>0&&Y>0&&Y<=N)
        {
            if(graph[X][Y]==1) return false;
            else{
                X+=dx[i]; 
                Y+=dy[i];
            }
        }
    }
    return true;
}
void backtracking(int cnt)
{
    if(cnt==N+1){
        ans++; 
        return;
    }
    FOR(j,N)
    {
        if(visit[cnt][j]!=1 && check(cnt,j))
        {
            visit[cnt][j]=1;
            graph[cnt][j]=1;
            backtracking(cnt+1);
            visit[cnt][j]=0;
            graph[cnt][j]=0;
        }
    }
}
int main()
{
    cin >> N;
    backtracking(1);
    cout << ans;
}