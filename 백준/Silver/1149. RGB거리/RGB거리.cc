#include <iostream>
using namespace std;
#define FOR(i,N) for(int (i)=0;(i)<(N);(i)++)
int N;
int arr[1000][3];
int DP[1000][3];
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    cin >> N;
    FOR(i, N) FOR(j, 3) cin >> arr[i][j];
    for (int i = 0; i < N; i++) {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + arr[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + arr[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + arr[i][2];
    }
    int result = min(min(DP[N - 1][0], DP[N - 1][1]), DP[N - 1][2]);
    cout << result;
    return 0;
}
