#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int n = N;
    int ans = 0;
    while(n>0)
    {
        string s = to_string(n);
        int n1 = n;
        for(int i=0; i<s.length(); i++)
        {
            n1 += s[i]-'0';
        }
        if(n1==N) ans = n;
        n--;
    }
    cout << ans;
    return 0;
}