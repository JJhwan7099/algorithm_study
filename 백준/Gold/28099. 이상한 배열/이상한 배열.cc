#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int N;
int arr[200001];
int tree[800001];
int maxTreeValue = 0;
int init(int start, int end, int node) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = max(init(start,mid,node*2),init(mid+1,end,node*2+1));
}
void query(int start, int end, int node, int left, int right) {
    if(left<=right) {
        if(left>end || right<start) return;
        else if(left<=start && right>=end) {
            maxTreeValue=max(maxTreeValue,tree[node]);
            return;
        }
        int mid = (start+end)/2;
        query(start,mid,node*2,left,right);
        query(mid+1,end,node*2+1,left,right);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        unordered_map<int,vector<int>> checkSameNums;
        cin >> N;
        FOR(i,N) {
            cin >> arr[i];
            checkSameNums[arr[i]].push_back(i);
        }
        init(1,N,1);
        bool resultCheck = true;
        for(auto&num:checkSameNums) {
            if(num.second.size()>1) {
                for(int i=0; i<num.second.size(); i++) {
                    for(int j=i+1; j<num.second.size(); j++) {
                        maxTreeValue = 0;
                        query(1,N,1,num.second[i]+1,num.second[j]-1);
                        if(maxTreeValue>num.first) {
                            resultCheck = false;
                        }
                        break;
                    }
                    if(!resultCheck) break;
                }
            }
        }
        if(resultCheck) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}