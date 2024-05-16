#include <iostream>
using namespace std;
#define FOR(i,N) for(double i=1; i<=N; i++)
long long X,Y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y;
    int Z = (Y*100/X);
    long long s = 1;
    long long e = X;
    long long result = -1;
    
    while(s<=e) {
        long long mid = (s+e)/2;
        if((int)(((long long)Y+mid)*100/(X+mid))!=Z) {
            if(result==-1) result = mid;
            else result = min(result,mid);
            e = mid - 1;
        }
        else s = mid + 1;
    }
    cout << result;
    return 0;
}