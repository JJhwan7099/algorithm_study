#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int K,N;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    FOR(i,K)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long s = 1;
    long long e = *prev(v.end());
    long long mid = (s+e)/2;
    while(s<=e)
    {
        long long cnt = 0;
        FOR(i,K) cnt += v[i-1]/mid;
        if(cnt>=N)
        {
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid = (s+e)/2;
    }
    cout << mid;
    return 0;
}