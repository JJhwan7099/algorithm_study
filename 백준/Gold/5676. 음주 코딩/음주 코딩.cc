#include <iostream>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, K;
int nums[100001];
map<int,int> tree[400001];
map<int,int> init(int start, int end, int node) {
    if(start==end) {
        tree[node][nums[start]]++;
        return tree[node];
    }
    int mid = (start+end)/2;
    map<int,int> resultA = init(start,mid,node*2);
    map<int,int> resultB = init(mid+1,end,node*2+1);
    map<int,int> result;
    for(auto it : resultA) {
        if(it.second>0) result[it.first]+=it.second;
    }
    for(auto jt : resultB) {
        if(jt.second>0) result[jt.first]+=jt.second;
    }
    return tree[node]=result;
}
map<int,int> query(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return map<int,int>();
    if(left <= start && right >= end) {
        return tree[node];
    }
    else {
        int mid = (start+end)/2;
        map<int,int> resultA = query(start,mid,node*2,left,right);
        map<int,int> resultB = query(mid+1,end,node*2+1,left,right);
        map<int,int> result;
        for(auto it : resultA) {
            if(it.second!=0) result[it.first]+=it.second;
        }
        for(auto jt : resultB) {
            if(jt.second!=0) result[jt.first]+=jt.second;
        }
        return result;
    }
}
void update(int start, int end, int node, int index, int original, int change) {
    if(index < start || index > end) return;
    tree[node][original]--;
    tree[node][change]++;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start,mid,node*2,index,original,change);
    update(mid+1,end,node*2+1,index,original,change);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>N>>K) {
        FOR(i,N) {
            cin >> nums[i];
            if(nums[i]>0) nums[i] = 1;
            else if(nums[i]<0) nums[i] = -1;
            else nums[i] = 0;
        }
        FOR(i,4*N) tree[i].clear();
        init(1,N,1);
        FOR(i,K) {
            char cmd; cin >> cmd;
            if(cmd == 'C') {
                int index, value;
                cin >> index >> value;
                if(value>0) value = 1;
                else if(value<0) value = -1;
                else value = 0;
                update(1,N,1,index,nums[index],value);
                nums[index] = value;
            }
            else if(cmd == 'P') {
                int i,j; cin >> i >> j;
                map<int,int> result = query(1,N,1,i,j);
                if(result[0]>0) cout << 0;
                else if(result[-1]%2==0) cout << "+";
                else if(result[-1]%2==1) cout << "-";
                result.clear();
            }
        }
        cout << '\n';
    }
    return 0;
}