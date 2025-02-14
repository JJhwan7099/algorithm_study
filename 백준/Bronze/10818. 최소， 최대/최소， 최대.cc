#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int maxN=-1000000;
int minN=1000000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int num;
        cin >> num;
        maxN = max(maxN, num);
        minN = min(minN, num);
    }
    cout << minN << " " << maxN << '\n';
    return 0;
}