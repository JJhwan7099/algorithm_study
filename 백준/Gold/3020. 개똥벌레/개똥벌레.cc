#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,H;
int top[500002];
int bottom[500002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> H;
    FOR(i,N) {
        int n;
        cin >> n;
        if(i%2==1) {
            top[n]++;
        }
        else {
            bottom[n]++;
        }
    }
    for(int i=H; i>0; i--) {
        top[i]+=top[i+1];
        bottom[i]+=bottom[i+1];
    }
    int result=10000000;
    int cnt=0;
    FOR(i,H) {
        if(top[i]+bottom[H-i+1]<result) {
            result=top[i]+bottom[H-i+1];
            cnt=1;
        }
        else if(top[i]+bottom[H-i+1]==result) cnt++;
    }
    cout << result << " " << cnt;
    return 0;
}