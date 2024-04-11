#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,L,W;
queue<int> truck;
int t = 0;
void testprint(queue<int> dari) {
    cout << t << endl;
    while(!dari.empty()) {
        cout << dari.front() << " ";
        dari.pop();
    }
    cout << endl;
}
bool check(queue<int> dari) {
    while(!dari.empty()) {
        if(dari.front()!=0) return true;
        dari.pop();
    }
    return false;
}
void GO() {
    int dariW = 0;
    queue<int> dari;
    FOR(i,L) dari.push(0);
    while(!truck.empty()) {
        if(dariW - dari.front() + truck.front() <= W) {
            dariW+=truck.front();
            dari.push(truck.front());
            truck.pop();
        }else{
            dari.push(0);
        }
        while(dari.size()!=L){
            dariW-=dari.front();
            dari.pop();
        }
        t++;
    }
    while(check(dari))
    {
        dari.pop();
        dari.push(0);
        t++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> W;
    FOR(i,N){
        int w; cin >> w;
        truck.push(w);
    }
    GO();
    cout << t;
    return 0;
}