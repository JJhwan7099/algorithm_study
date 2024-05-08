#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<long long> arr;
int bSearch(int s, int e, int ss) {
    int mid;
    long long a,b,c;
    int idx = mid;
    while(abs(s-e)>=2) {
        mid = (s+e)/2;
        a = abs(ss+arr[mid]);
        if(mid+1!=e) b = abs(ss+arr[mid+1]);
        else b = 5000000000;
        if(mid-1!=s) c = abs(ss+arr[mid-1]);
        else c = 5000000000;
        if(min(a,min(b,c))==a) {
            idx = mid;
            break;
        }
        else if(min(a,min(b,c))==b) {
            s = mid;
        }
        else if(min(a,min(b,c))==c) {
            e = mid;
        }
    }
    return idx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; 
    FOR(i,N) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long long mini = 5000000000;
    int x,y,z = 0;
    for(int i=0; i<arr.size()-2; i++) {
        for(int j=arr.size()-1; abs(i-j)>=2; j--) {
            int a = bSearch(i,j,arr[i]+arr[j]);
            if(mini>abs(arr[i]+arr[j]+arr[a])) {
                mini = abs(arr[i]+arr[j]+arr[a]);
                x=i; y=j; z=a;
            }
        }
    }
    cout << arr[x] << " " << arr[z] << " " << arr[y];
    return 0;
}