#include <iostream>
#include <stack>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int arr[1000001];
int result[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> arr[i];
    }
    stack<int> s;
    s.push(1);
    for(int i=2; i<=N; i++) {
        if(arr[s.top()]<arr[i]){
            while(!s.empty() && arr[s.top()]<arr[i]){
                result[s.top()]=arr[i];
                s.pop();
            }
        }
        s.push(i);
    }
    while(!s.empty()) {
        result[s.top()]=-1;
        s.pop();
    }
    FOR(i,N) {
        cout << result[i] << " ";
    }
    return 0;
}