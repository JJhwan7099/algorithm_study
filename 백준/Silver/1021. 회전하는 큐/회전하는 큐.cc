#include <iostream>
#include <deque>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
deque<int> haveToPick;
deque<int> nums;
int ans=0;
void calOne() {
    nums.pop_front();
}
int calTwo(int targetNum, deque<int> nums) {
    int cnt = 0;
    while(targetNum!=nums.front()) {
        int n = nums.front();
        nums.pop_front();
        nums.push_back(n);
        cnt++;
    }
    return cnt;
}
int calThree(int targetNum) {
    int cnt = 0;
    while(targetNum!=nums.front()) {
        int n = nums.back();
        nums.pop_back();
        nums.push_front(n);
        cnt++;
    }
    return cnt;
}
int start() {
    int cnt = 0;
    while(!haveToPick.empty()) {
        int targetNum = haveToPick.front();
        haveToPick.pop_front();
        int n = calThree(targetNum);
        ans+=min(N-cnt-n,n);
        calOne();
        cnt++;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M) {
        int n; cin >> n;
        haveToPick.push_back(n);
    }
    FOR(i,N) {
        nums.push_back(i);
    }
    cout << start();
    return 0;
}