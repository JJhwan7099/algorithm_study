#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int L;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L;
    int r = 1;
    int val = 0;
    FOR(i,L)
    {
        char a; cin >> a;
        int h = a-'a'+1;
        h*=r;
        h%=1234567891;
        val+=h;
        r*=31;
    }
    cout << val;
    return 0;
}