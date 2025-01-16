#include <iostream>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
multimap<int,int> mapA;
multimap<int,int> mapB;
int answer[51];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int n;
        cin >> n;
        mapA.insert({n,i});
    }
    FOR(i,N) {
        int n;
        cin >> n;
        mapB.insert({n,i});
    }
    auto iterA=mapA.begin();
    auto iterB=prev(mapB.end());
    for(iterB=prev(mapB.end()); iterB!=mapB.begin(); iterB--) {
        answer[iterB->second]=iterA->first * iterB->first;
        iterA++;
    }
    answer[iterB->second]=iterA->first * iterB->first;
    int result = 0;
    int cnt=1;
    for(auto&B: mapB){
        result+=answer[cnt++];
    }
    cout << result;
    return 0;
}