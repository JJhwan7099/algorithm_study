#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
map<int,int> m;
vector<int> v;
void btk(int n, int sum) {
    sum+=v[n];
    m[sum]=1;
    for(int i=n+1; i<v.size(); i++) {
        btk(i,sum);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    v.push_back(0);
    FOR(i,N) {
        int n; cin >> n;
        v.push_back(n);
    }
    btk(0,0);
    int result=0;
    while(m[result++]){
        
    }
    cout << result-1;
    return 0;
}