#include <iostream>
#include <math.h>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
double x1,Y1,r1,x2,y2,r2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2;
        double dis = sqrt(pow(abs(x1-x2),2)+pow(abs(Y1-y2),2));
        if(dis==0) {
            if(r1==r2) {
                cout << -1;
            }
            else cout << 0;
        }else {
            if(dis<r1+r2) {
                if(dis<abs(r1-r2)) cout << 0;
                else if(dis>abs(r1-r2)) cout << 2;
                else cout << 1;
            }
            else if(dis>r1+r2) {
                cout << 0;
            }
            else {
                cout << 1;
            }
        }
        if(T!=0)cout << '\n';
    }   
    return 0;
}