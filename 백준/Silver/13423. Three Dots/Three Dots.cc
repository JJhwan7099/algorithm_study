#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=0; i<N; i++)
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        int N; cin >> N;
        unordered_map<int,int> m;
        int arr[1001];
        m.clear();
        FOR(i,N) {
            cin >> arr[i];
            m[arr[i]] = 1;
        }
        sort(arr,arr+(N));
        int ans = 0;
        for(int i=0; i<N-2; i++) {
            for(int j=N-1; j>i+1; j--) {
                if((arr[j]+arr[i])%2==0 && m[(arr[j]+arr[i])/2]==1) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}