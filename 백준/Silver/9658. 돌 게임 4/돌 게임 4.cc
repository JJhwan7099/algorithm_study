#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if(N%7==1||N%7==3) cout << "CY";
    else cout << "SK";
    return 0;
}