#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
struct Egg{
    int s,w;
};
Egg eggs[9];
int result=0;
void start(int curEgg, int curLeftEggsCnt, Egg eggs[9]) {
    if(curEgg>N) return;
    if(eggs[curEgg].s<=0 || curLeftEggsCnt==1) {
        start(curEgg+1, curLeftEggsCnt, eggs);
    }
    else {
        FOR(i,N) {
            if(i==curEgg || eggs[i].s<=0) continue;
            else {
                Egg tempA = eggs[curEgg];
                Egg tempB = eggs[i];
                int tempcurLeftEggsCnt = curLeftEggsCnt;
                tempA.s -= tempB.w;
                tempB.s -= tempA.w;
                if(tempA.s<=0) tempcurLeftEggsCnt--;
                if(tempB.s<=0) tempcurLeftEggsCnt--;
                eggs[curEgg] = tempA;
                eggs[i] = tempB;
                result = max(result, N-tempcurLeftEggsCnt);
                start(curEgg+1, tempcurLeftEggsCnt, eggs);
                eggs[curEgg].s += tempB.w;
                eggs[i].s += tempA.w;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> eggs[i].s >> eggs[i].w;
    }
    start(1, N, eggs);
    cout << result;
    return 0;
}