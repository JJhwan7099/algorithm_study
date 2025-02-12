#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[100001];
int A;
int B;
int sum = 2100000000;
void binarySearch(int start, int end, int n) {
    int s = start, e = end;
    while(s<=e) {
        int mid = (s+e)/2;
        if(abs(arr[mid]+n)<sum) {
            A = start-1;
            B = mid;
            sum = abs(arr[mid]+n);
        }
        if(arr[mid]+n>0) e=mid-1;
        else if(arr[mid]+n<0) s=mid+1;
        else return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> arr[i];
    FOR(i,N-1) {
        binarySearch(i+1,N,arr[i]);
    }
    cout << arr[A] << " " << arr[B];
    return 0;
}