#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
priority_queue<int, vector<int>, greater<int>> pqMin;
priority_queue<int> pqMax;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int num; cin >> num;
        if(i==1) pqMax.push(num);
        else if(i==2) {
            if(pqMax.top() < num) pqMin.push(num);
            else {
                pqMin.push(pqMax.top());
                pqMax.pop();
                pqMax.push(num);
            }
        }
        else {
            if(pqMax.size() == pqMin.size()) {
                if(pqMin.top() < num) {
                    pqMax.push(pqMin.top());
                    pqMin.pop();
                    pqMin.push(num);
                }
                else {
                    pqMax.push(num);
                }
            }
            else if(pqMax.size()-1==pqMin.size()) {
                if(pqMax.top()>num) {
                    pqMin.push(pqMax.top());
                    pqMax.pop();
                    pqMax.push(num);
                }
                else {
                    pqMin.push(num);
                }
            }
        }
        cout << pqMax.top() << "\n";
    }
    return 0;
}