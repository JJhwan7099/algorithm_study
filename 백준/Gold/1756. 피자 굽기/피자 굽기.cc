#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int D,N;
int len = -1;
int arr[300002];
queue<int> pizza;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> D >> N;
    FOR(dep,D) {
        int zireum; cin >> zireum;
        if(len==-1) {
            len=zireum;
            arr[dep] = zireum;
        }
        else if(len<=zireum) {
            arr[dep] = len;
        }
        else if(len>zireum) {
            len = zireum;
            arr[dep] = len;
        }
    }
    FOR(i,N) {
        int a; cin >> a;
        pizza.push(a);
    }
    int depth = D;
    while(!pizza.empty()) {
        bool b = false;
        int zireum = pizza.front();
        pizza.pop();
        while(depth>0) {
            if(arr[depth]>=zireum)
            {
                b=true;
                depth--;
                break;
            }
            else depth--;
        }
        if(!b) {
            cout << 0;
            return 0;
        }
    }
    cout << depth+1;
    return 0;
}