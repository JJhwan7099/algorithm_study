#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int nums[2001];
int DP[2001][2001];
void dp() {
    FOR(i,N) DP[i][i] = 1;
    FOR(i,N-1) if(nums[i] == nums[i+1]) DP[i][i+1] = 1;
    for(int i=3; i<=N; i++) {
        for(int j=1; j+i-1<=N; j++) {
            if(nums[j]==nums[j+i-1] && DP[j+1][j+i-2]==1) {
                DP[j][j+i-1] = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> nums[i];
    }
    cin >> M;
    dp();
    FOR(i,M) {
        int s,e; cin >> s >> e;
        cout << DP[s][e] << '\n';
    }
    return 0;
}