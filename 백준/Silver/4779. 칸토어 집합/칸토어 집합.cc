#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
string S = "";
int l;
void jaegui(int s, int e)
{
    int l = abs(e-s)+1;
    if(s==e)
    {
        return;
    }else{
        for(int i=l/3+s; i<s+l/3*2; i++) S[i-1]=' ';
        jaegui(s,l/3+s-1);
        jaegui(s+l/3*2,e);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N)
    {
        int n = 1;
        FOR(i,N)
        {
            n*=3;
        }
        S="";
        FOR(i,n) S+='-';
        jaegui(1, n);
        cout << S << '\n';
    }
    return 0;
}