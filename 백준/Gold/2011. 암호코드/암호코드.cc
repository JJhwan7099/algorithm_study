#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int DP[5001][2];
string num;
void dp() {
    if(num[0]!='0') DP[1][0]=1;
    DP[1][1]=0;
    if(num[1]!='0') DP[2][0]=DP[1][0]+DP[1][1];
    if(num[0]!='0' && (num[0]-'0')*10+(num[1]-'0')<=26) DP[2][1]=1;
    for(int i=3; i<=num.length(); i++) {
        
        if(num[i-2]!='0' && (num[i-2]-'0')*10+(num[i-1]-'0')<=26) {
            DP[i][1] = (DP[i-2][0]+DP[i-2][1])%1000000;
        }
        if(num[i-1]!='0') DP[i][0] = (DP[i-1][0]+DP[i-1][1])%1000000;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    dp();
    cout << (DP[num.length()][0]+DP[num.length()][1])%1000000;
    return 0;
}