#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> cranes;
vector<int> boxes;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int x; cin >> x;
        cranes.push_back(x);
    }
    cin >> M;
    FOR(i,M) {
        int x; cin >> x;
        boxes.push_back(x);
    }
    sort(cranes.rbegin(), cranes.rend());
    sort(boxes.begin(), boxes.end());
    if(*prev(boxes.end())>cranes[0]) {
        cout << -1 << '\n';
        return 0;
    }
    stack<int> extraBoxes;
    stack<int> priorBoxes;
    for(auto& box: boxes) extraBoxes.push(box);
    while(!extraBoxes.empty()) {
        for(auto& crane: cranes) {
            while(!extraBoxes.empty() && extraBoxes.top() > crane) {
                priorBoxes.push(extraBoxes.top());
                extraBoxes.pop();
            }
            if(!extraBoxes.empty())extraBoxes.pop();
        }
        while(!priorBoxes.empty()) {
            extraBoxes.push(priorBoxes.top());
            priorBoxes.pop();
        }
        ans++;
    }
    cout << ans << '\n';
    return 0;
}