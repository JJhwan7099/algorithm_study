#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int graph[21][21];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans=0;
void move(int x, int y)
{
    if(x==0&&y==1)
    {
        FOR(i,N)
        {
            int cnt=N;
            int e = N;
            bool first = false;
            int num = 0;
            for(int j=N; j>0; j--)
            {
                if(first==0 && graph[i][j]!=0)
                {
                    first = 1;
                    num = graph[i][j];
                }
                else if(first==1 && graph[i][j]!=0)
                {
                    if(graph[i][j]==num)
                    {
                        graph[i][e--]=num*2;
                        num = 0;
                        first = 0;
                        cnt--;
                    }else{
                        first = 1;
                        graph[i][e--] = num;
                        num = graph[i][j];
                    }
                }else cnt--;
            }
            if(first==1) graph[i][e]=num;
            for(int j=1; j<=N-cnt; j++) graph[i][j]=0;
        }
    }
    else if(x==0&&y==-1)
    {
        FOR(i,N)
        {
            int cnt=N;
            int e = 1;
            bool first = false;
            int num = 0;
            for(int j=1; j<=N; j++)
            {
                if(first==0 && graph[i][j]!=0)
                {
                    first = 1;
                    num = graph[i][j];
                }
                else if(first==1 && graph[i][j]!=0)
                {
                    if(graph[i][j]==num)
                    {
                        graph[i][e++]=num*2;
                        num = 0;
                        first = 0;
                        cnt--;
                    }else{
                        first = 1;
                        graph[i][e++] = num;
                        num = graph[i][j];
                    }
                }else cnt--;
            }
            if(first==1) graph[i][e]=num;
            for(int j=N; j>cnt; j--) graph[i][j]=0;
        }
    }
    else if(x==1&&y==0)
    {
        FOR(j,N)
        {
            int cnt=N;
            int e = N;
            bool first = false;
            int num = 0;
            for(int i=N; i>0; i--)
            {
                if(first==0 && graph[i][j]!=0)
                {
                    first = 1;
                    num = graph[i][j];
                }
                else if(first==1 && graph[i][j]!=0)
                {
                    if(graph[i][j]==num)
                    {
                        graph[e--][j]=num*2;
                        num = 0;
                        first = 0;
                        cnt--;
                    }else{
                        first = 1;
                        graph[e--][j] = num;
                        num = graph[i][j];
                    }
                }else cnt--;
            }
            if(first==1) graph[e][j]=num;
            for(int i=1; i<=N-cnt; i++) graph[i][j]=0;
        }
    }
    else if(x==-1&&y==0)
    {
        FOR(j,N)
        {
            int cnt=N;
            int e = 1;
            bool first = false;
            int num = 0;
            for(int i=1; i<=N; i++)
            {
                if(first==0 && graph[i][j]!=0)
                {
                    first = 1;
                    num = graph[i][j];
                }
                else if(first==1 && graph[i][j]!=0)
                {
                    if(graph[i][j]==num)
                    {
                        graph[e++][j]=num*2;
                        num = 0;
                        first = 0;
                        cnt--;
                    }else{
                        first = 1;
                        graph[e++][j] = num;
                        num = graph[i][j];
                    }
                }else cnt--;
            }
            if(first==1) graph[e][j]=num;
            for(int i=N; i>cnt; i--) graph[i][j]=0;
        }
    }
}
void backtracking(int cnt)
{
    int g[21][21];
    FOR(i,N)FOR(j,N)
    {
        g[i][j] = graph[i][j];
        ans = max(ans,graph[i][j]);
    }
    if(cnt==5) return;
    for(int i=0; i<4; i++)
    {
        move(dx[i], dy[i]);
        backtracking(cnt+1);
        FOR(i,N)FOR(j,N) graph[i][j] = g[i][j];
    }
}
int main()
{
    cin >> N;
    FOR(i,N)FOR(j,N) cin >> graph[i][j];
    backtracking(0);
    cout << ans;
}