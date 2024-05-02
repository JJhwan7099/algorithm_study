#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
struct Shark {
    int s,d,z;
};
Shark shark[101][101];
Shark sharkarr[101][101];
int R,C,M;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int fishing_king = 0;
int ans = 0;
Shark sharkcmp(Shark s1, Shark s2) {
    if(s1.z>s2.z) return s1;
    else if(s1.z<s2.z) return s2;
}
void move() {
    FOR(i,R)FOR(j,C) {
        sharkarr[i][j].d=0;
        sharkarr[i][j].s=0;
        sharkarr[i][j].z=0;
    }
    FOR(i,R)FOR(j,C) {
        if(shark[i][j].d!=0) {
            Shark sh = shark[i][j];
            int X = i+(dx[sh.d-1]*sh.s);
            int Y = j+(dy[sh.d-1]*sh.s);
            while(!(X>0&&Y>0&&X<=R&&Y<=C)) {
                if(X>R) {
                    X = R-(X-R);
                    if(sh.d%2==1) sh.d+=1;
                    else sh.d-=1; 
                }else if(X<1) {
                    X = 1+(1-X);
                    if(sh.d%2==1) sh.d+=1;
                    else sh.d-=1; 
                }
                if(Y>C) {
                    Y = C-(Y-C);
                    if(sh.d%2==1) sh.d+=1;
                    else sh.d-=1; 
                }else if(Y<1) {
                    Y = 1+(1-Y);
                    if(sh.d%2==1) sh.d+=1;
                    else sh.d-=1; 
                }
            }
            sharkarr[X][Y] = sharkcmp(sharkarr[X][Y],sh);
        }
    }
    FOR(i,R)FOR(j,C) shark[i][j] = sharkarr[i][j];
}
void start() {
    fishing_king++;
    int dis = 0;
    while(dis<=R) {
        dis++;
        if(shark[dis][fishing_king].d!=0) {
            ans+=shark[dis][fishing_king].z;
            shark[dis][fishing_king].s = 0;
            shark[dis][fishing_king].d = 0;
            shark[dis][fishing_king].z = 0;
            break;
        }
    }
    move();
    if(fishing_king<C) start();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> M;
    FOR(i,M) {
        int r,c; cin >> r >> c;
        cin >> shark[r][c].s >> shark[r][c].d >> shark[r][c].z;
    }
    start();
    cout << ans;
    return 0;
}