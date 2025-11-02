#include <string>
#include <vector>

using namespace std;

long long DP[2001];

void dp(int n) {
    DP[1]=1;
    DP[2]=1;
    for(int i=1; i<n; i++) {
        if(i+1<=n) {
            DP[i+1] = (DP[i+1]+DP[i])%1234567;
        }
        if(i+2<=n) {
            DP[i+2] = (DP[i+2]+DP[i])%1234567;
        }
    }
}
long long solution(int n) {
    long long answer = 0;
    dp(n);
    answer = DP[n];
    return answer;
}