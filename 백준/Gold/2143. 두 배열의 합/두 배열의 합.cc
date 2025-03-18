#include <iostream>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int N,M;
int Anums[1001];
int Asums[1001];
unordered_map<int,int> Amap;
int Bnums[1001];
int Bsums[1001];
unordered_map<int,int> Bmap;
void makeComb(int arrSize, int n, int sum, int arr[], unordered_map<int,int>& um) {
    if(sum>0) um[sum]+=1;
    for(int i=n; i<=arrSize; i++) {
        makeComb(arrSize,i+1,sum+arr[i],arr,um);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    cin >> N;
    FOR(i,N) cin >> Anums[i];
    cin >> M;
    FOR(i,M) cin >> Bnums[i];
    // makeComb(N,1,0,Anums,Amap);
    // makeComb(M,1,0,Bnums,Bmap);

    FOR(i,N) {
        Asums[i] = Asums[i-1]+Anums[i];
    }
    FOR(i,M) {
        Bsums[i] = Bsums[i-1]+Bnums[i];
    }
    FOR(i,N) {
        for(int j=0;j<i;j++) {
            int sum = Asums[i]-Asums[j];
            Amap[sum]++;
        }
    }
    FOR(i,M) {
        for(int j=0;j<i;j++) {
            int sum = Bsums[i]-Bsums[j];
            Bmap[sum]++;
        }
    }

    long long result = 0;
    for(auto&m:Amap) {
        int n = m.first;
        long long cnt = m.second;
        auto it = Bmap.find(T-n);
        if(it!=Bmap.end()) {
            result += it->second * cnt;
        }
    }
    cout << result;
    return 0;
}