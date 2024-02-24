#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans=0;
    cin >> N >> M;
    FOR(i,N)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int s=1;
    int e=*prev(v.end());
    int mid;
    while(s<=e)
    {
        long long len=0;
        mid=(s+e)/2;
        for(int i=v.size()-1;i>=0; i--)
        {
            if(v[i]<=mid) break;
            else len+=v[i]-mid;
        }
        if(len>=M)
        {
            ans=mid;
            s= mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout << ans;
    return 0;
}