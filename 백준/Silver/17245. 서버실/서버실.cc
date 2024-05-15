#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1001][1001];
long long total = 0;
int max_minute = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N)FOR(j,N) {
        cin >> arr[i][j]; total += arr[i][j];
        max_minute = max(max_minute, arr[i][j]);
    }
    int max_val = 0;
    int e = max_minute;
    int s = 1;
    while(s<=e) {
        int mid  = (s+e)/2;
        long long computer = 0;
        FOR(i,N)FOR(j,N) if(arr[i][j]<mid) computer+=arr[i][j]; else computer+=mid;
        if(total%2==0 && computer>=total/2) {
            max_val = mid;
            e = mid - 1;
        }
        else if(total%2==1 && computer>total/2) {
            max_val = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    cout << max_val;
    return 0;
}