#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int a,b;
int arr[11000000];
void findPrimeNumber() {
    for(int i=2; i<=b; i++) {
        if(i>10000000) break;
        arr[i]=1;
    }
    for(int i=2; i<=b; i++) {
        if(i>5005000) break;
        if(arr[i]==0) continue;
        for(int j=2*i; j<=b; j+=i) {
            if(j>10000000) break;
            arr[j]=0;
        }
    }
}
bool isPalindrome(string s) {
    for(int i=0; i<s.length()/2; i++) {
        if(s[i]!=s[s.length()-1-i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    findPrimeNumber();
    int cnt=0;
    for(int i=a; i<=b; i++) {
        if(i>10000000) break;
        else if(arr[i]==1) {
            if(isPalindrome(to_string(i))) {
                cout << i << '\n';
            }
        }
    }
    cout << -1;
    return 0; 
}