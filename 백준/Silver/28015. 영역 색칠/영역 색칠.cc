#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int draw[102][102];
int cnt=0;
bool check(int color[], int n)
{
    FOR(i,M)
    {
        if(color[i]!=draw[n][i]) return false;
    }
    return true;
}
int drawline(int n)
{
    int totcnt=0;
    int one = 0;
    int two = 0;
    FOR(i,M+1)
    {
        if(draw[n][i]==1 && draw[n][i-1]!=1) one++;
        else if(draw[n][i]==2 && draw[n][i-1]!=2) two++;
        else if(draw[n][i]==0)
        {
            if(one>two) totcnt += (two+1);
            else if(one<two) totcnt += (one+1);
            else 
            {
                if(one!=0) totcnt += (one+1);
                else continue;
            }
            one = 0; two = 0;
        }
    }
    return totcnt;
}
int main()
{
    cin >> N >> M;
    FOR(i,N+1)FOR(j,N+1) draw[i][j]=0; 
    FOR(i,N)FOR(j,M) cin >> draw[i][j];
    FOR(i,N)
    {
        cnt += drawline(i);
    }
    cout << cnt;
}