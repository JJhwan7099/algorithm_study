#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int n,k;
int DP[10001];
vector<int> coins;
void dp() {
    DP[0]=1;
    for(int i=0; i<coins.size(); i++) {
        for(int j=0; j<=k; j++) {
            if(DP[j]>0) {
                if(j+coins[i]<=k) DP[j+coins[i]]+=DP[j];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    FOR(i,n)  {
        int c; cin >> c;
        coins.push_back(c);
    }
    sort(coins.begin(),coins.end());
    dp();
    cout << DP[k];
    return 0;
}