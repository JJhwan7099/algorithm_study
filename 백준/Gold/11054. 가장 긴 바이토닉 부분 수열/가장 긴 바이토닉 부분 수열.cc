#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1001];
int upDP[1001];
int downDP[1001];

void updp() {
    FOR(i,N) upDP[i]=1;
    FOR(i,N) {
        for(int j=i+1; j<=N; j++) {
            if(arr[i]<arr[j]) {
                if(upDP[j]>upDP[i]) continue;
                else if(upDP[j]<=upDP[i]+1) {
                    upDP[j]=upDP[i];
                    upDP[j]++;
                }
            }
        }
    }
}
void downdp() {
    FOR(i,N) downDP[i]=1;
    for(int i=N; i>=1; i--) {
        for(int j=i-1; j>=1; j--) {
            if(arr[i]<arr[j]) {
                if(downDP[j]<=downDP[i]+1) {
                    downDP[j]=downDP[i];
                    downDP[j]++;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> arr[i];
    }

    updp();
    downdp();

    int ans = 0;
    FOR(i,N) ans = max(ans,upDP[i]+downDP[i]-1);
    cout << ans;
    
    return 0;
}