#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int dx[4]={1,2,2,1};
int dy[4]={2,1,-1,-2};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int cnt=1;
    if(N<=1){
        cout << 1; return 0;
    }
    if(N<=2){
        if(M<=7)cout << (M-1)/2+1;
        else cout << 4;
        return 0;
    }else{
        if(M<=4)
        {
            cout << M; return 0;
        }else if(M==5){
            cout << 4; return 0;
        }
        else{
            cnt=3;
            M-=5;
            cnt+=M;
        }
    }
    cout << cnt;
    return 0;
}