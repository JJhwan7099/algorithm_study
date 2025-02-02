#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int arr[100001];
long long calculate(long long second) {
    long long personCount = 0;
    FOR(i,N) {
        if(personCount + second/arr[i] >=M) {
            return true;
        }
        else personCount += second / arr[i];
    }
    return false;
}
long long binarySearch() {
    long long start = 1;
    long long end = 1000000000000000000;
    long long mid;
    long long answer;
    while(start <= end) {
        mid = (start + end)/2;
        if(!calculate(mid)) {
            start = mid+1;
        }
        else {
            end = mid-1;
            answer = mid;
        }
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N) {
        cin >> arr[i];
    }
    cout << binarySearch();
    return 0;
}