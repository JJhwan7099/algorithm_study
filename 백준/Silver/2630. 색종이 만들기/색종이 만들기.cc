#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int paper[129][129];
int white=0;
int blue=0;
bool check(int x1, int y1, int x2, int y2)
{
    int color = paper[x1][y1];
    for(int i=x1; i<x2; i++)for(int j=y1; j<y2; j++)
    {
        if(paper[i][j]!=color) return false;
    }
    return true;
    
}
void cut(int x1, int y1, int n)
{
    if(check(x1,y1,x1+n,y1+n))
    {
        if(paper[x1][y1]==0) white++;
        else blue++;
    }
    else{
        cut(x1,y1,n/2);
        cut(x1,y1+n/2,n/2);
        cut(x1+n/2,y1,n/2);
        cut(x1+n/2,y1+n/2,n/2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N)FOR(j,N) cin >> paper[i][j];
    cut(1,1,N);
    cout << white << "\n" << blue;
    return 0;
}