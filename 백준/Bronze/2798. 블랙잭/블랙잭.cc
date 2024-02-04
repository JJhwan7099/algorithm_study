#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int n, m;
int num[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    FOR(i,n){
        cin >> num[i];
    }
    int result = 0;
    FOR(i,n)FOR(j,n)FOR(k,n)
    {
        if(i==j||j==k||k==i)continue;
        else{
            int sum = num[i]+num[j]+num[k];
            if(sum>result && sum <= m) result = sum;
        }
    }
    cout << result;
    return 0;
}