#include<iostream>
using namespace std;
char graph[51][51];
#define FOR(i,N) for(int i=1; i<=N; i++)
int check(int startx, int starty)
{
    //맨 처음이 W일때
    int a = 0;
    FOR(x,8)FOR(y,8)
    {
        int X = x+startx-1;
        int Y = y+starty-1;
        if(X%2==1)
        {
            if(y%2==1)
            {
                if(graph[X][Y]!='W') a++;
            }
            else
            {
                if(graph[X][Y]!='B') a++;
            }
        }
        else
        {
            if(y%2==1)
            {
                if(graph[X][Y]!='B') a++;
            }
            else
            {
                if(graph[X][Y]!='W') a++;
            }
        }
    }
    //B 시작
    int aa = 0;
    FOR(x,8)FOR(y,8)
    {
        int X = x+startx-1;
        int Y = y+starty-1;
        if(X%2==1)
        {
            if(y%2==1)
            {
                if(graph[X][Y]!='B') aa++;
            }
            else
            {
                if(graph[X][Y]!='W') aa++;
            }
        }
        else
        {
            if(y%2==1)
            {
                if(graph[X][Y]!='W') aa++;
            }
            else
            {
                if(graph[X][Y]!='B') aa++;
            }
        }
    }
    return min(a,aa);
}
int main()
{
    int N,M; cin >> N >> M;
    FOR(i,N)FOR(j,M) cin >> graph[i][j];
    int a = 2501;
    FOR(i,N-7)FOR(j,M-7)
    {
        a = min(a,check(i,j));
    }
    cout << a;
}
