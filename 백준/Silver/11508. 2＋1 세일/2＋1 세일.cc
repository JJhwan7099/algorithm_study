#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    int total=0;
    for(int i=v.size()-1; i>=0; i--) {
        total+=v[i];
        if((v.size()-i)%3==0){
            total-=v[i];
        }    
    }
    cout << total;
    return 0;
}