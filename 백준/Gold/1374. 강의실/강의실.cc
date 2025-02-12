#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
vector<pair<int,int>> classes;
bool compare(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}
int start() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push(classes[0]);
    int cnt = 1;
    for(int i=1; i<N; i++) {
        int curStart = pq.top().first;
        int curEnd = pq.top().second;
        if(classes[i].first >= curEnd) {
            pq.pop();
        }
        pq.push(classes[i]);
    }
    return pq.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int a,b,c; cin >> a; cin >> b; cin >> c;
        classes.push_back({b,c});
    }
    sort(classes.begin(), classes.end(), compare);
    cout << start();
    return 0;
}