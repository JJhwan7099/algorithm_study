#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> nums;
int binarySearch(int start, int end, int n) {
    int s = start, e = end;
    int result=2000000000;
    int mid;
    while(s<=e) {
        mid = (s+e)/2;
        if(abs(nums[mid] - nums[n])>=M) {
            e = mid-1;
            result = abs(nums[mid] - nums[n]);
        }
        else if(abs(nums[mid] - nums[n])<M) {
            s = mid+1;
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,N) {
        int num; cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    int answer = 2000000000;
    for(int i=0; i<nums.size(); i++) {
        answer = min(answer,min(binarySearch(0,i-1,i),binarySearch(i+1,nums.size()-1,i)));
    }
    cout << answer;
    return 0;
}