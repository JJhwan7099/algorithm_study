#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,Q;
long long nums[100001];
long long tree[400001];
long long init(int start, int end, int node) {
    if(start==end) {
        return tree[node] = nums[start];
    }
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2)+init(mid+1,end,node*2+1);
}

long long sum(int start, int end, int node, int left, int right) {
    if(left>end||right<start) return 0;
    else if(left<=start && right>=end) return tree[node];
    else {
        int mid = (start+end)/2;
        return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
    }
}
void update(int start, int end, int node, int index, long long diff) {
    if(index<start || index>end) return;
    tree[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    FOR(i,N) cin >> nums[i];
    init(1,N,1);
    FOR(i,Q) {
        int X,Y,a,b;
        cin >> X >> Y >> a >> b;
        int x,y;
        x = min(X,Y);
        y = max(X,Y);
        cout << sum(1,N,1,x,y) << "\n";
        update(1,N,1,a,b-nums[a]);
        nums[a]=b;
    }
    return 0;
}