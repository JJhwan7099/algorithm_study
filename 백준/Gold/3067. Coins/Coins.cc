#include <iostream>
#include <vector>

int T;
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        int N,M; cin >> N;
        vector<int> nums;
        nums.clear();
        FOR(i,N) {
            int n; cin >> n;
            nums.push_back(n);
        }
        cin >> M;
        int DP[10001]={0,};
        DP[0]=1;
        for(auto&n: nums) {
            for(int i=0; i<M; i++) {
                if(DP[i]>0 && i+n<=M) DP[i+n] += DP[i];
            }
        }
        cout << DP[M] << "\n";
    }
    return 0;
}