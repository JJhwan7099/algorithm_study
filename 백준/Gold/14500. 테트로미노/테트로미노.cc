#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[501][501];
int ans = 0;
int ndx[4][4] = {{0,1,2,2},{0,0,1,2},{0,1,2,2},{0,0,1,2}};
int ndy[4][4] = {{0,0,0,1},{0,1,1,1},{1,1,1,0},{0,1,0,0}};
int zdx[2][4] = {{0,1,1,2},{0,1,1,2}};
int zdy[2][4] = {{0,0,1,1},{1,1,0,0}};
int square(int x, int y)
{
    int dx[3] = {1,1,0};
    int dy[3] = {0,1,1};
    int sum = graph[x][y];
    for(int i=0; i<3; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X>N||Y>M) return -1;
        sum += graph[X][Y];
    }
    return sum;
}
int stick(int x, int y)
{
    int xsum = 0;
    int ysum = 0;
    for(int i=0; i<4; i++)
    {
        xsum+=graph[x][y+i];
        if(y+i>M){
            xsum = -1;
            break;
        }
    }
    for(int i=0; i<4; i++)
    {
        ysum+=graph[x+i][y];
        if(x+i>N){
            ysum = -1;
            break;
        }
    }
    if(xsum>ysum) return xsum;
    else return ysum;
}
int yeot(int x, int y)
{
    //가장자리 탐색 시 문제 수정

    if((x==1&&y==1)||(x==N&&y==M)||(x==N&&y==1)||(x==1&&y==M)) return -1;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int arr[4];
    int sum = graph[x][y];
    for(int i=0; i<4; i++)
    {
        sum += graph[x+dx[i]][y+dy[i]];
    }
    for(int i=0;i<4;i++)
    {
        if(x==N)
        {
            arr[i] = sum - graph[x+1][y];
        } 
        else if(y==M)
        {
            arr[i] = sum - graph[x][y+1];
        }
        else if(x+dx[i]<=N && y+dy[i]<=M) arr[i] = sum - graph[x+dx[i]][y+dy[i]];
        else arr[i] = 0;
    }
    int result = 0;
    for(int i=0; i<4; i++) if(result<arr[i]) result = arr[i];
    return result;
}
int nieun(int x,int y)
{
    int result = 0;
    for(int i=0;i<4;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            int X = x+ndx[i][j];
            int Y = y+ndy[i][j];
            if(X>N||Y>M) 
            {
                sum = 0;
                break;
            }
            sum+=graph[X][Y];
        }
        if(sum>result) result = sum;
    }
    for(int i=0;i<4;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            int X = x+ndy[i][j];
            int Y = y+ndx[i][j];
            if(X>N||Y>M) 
            {
                sum = 0;
                break;
            }
            sum+=graph[X][Y];
        }
        if(sum>result) result = sum;
    }
    return result;
}
int zigzag(int x, int y)
{
    int result = 0;
    for(int i=0;i<2;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            int X = x+zdx[i][j];
            int Y = y+zdy[i][j];
            if(X>N||Y>M) 
            {
                sum = 0;
                break;
            }
            sum+=graph[X][Y];
        }
        if(sum>result) result = sum;
    }
    for(int i=0;i<2;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            int X = x+zdy[i][j];
            int Y = y+zdx[i][j];
            if(X>N||Y>M) 
            {
                sum = 0;
                break;
            }
            sum+=graph[X][Y];
        }
        if(sum>result) result = sum;
    }
    return result;
}
int main()
{
    cin >> N >> M;
    FOR(i,500)FOR(j,500) graph[i][j] = 0;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    for(int i=1;i<=N;i++)for(int j=1; j<=M; j++)
    {
        int arr[5];
        arr[0] = square(i,j);
        arr[1] = stick(i,j);
        arr[2] = yeot(i,j);
        arr[3] = nieun(i,j);
        arr[4] = zigzag(i,j);
        for(int i=0;i<5;i++)
        {
            if(arr[i]!=-1)ans = max(ans,arr[i]);
        }
    }
    if(ans!=-1) cout << ans;
    else cout << 0;
}