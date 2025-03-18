#include <iostream>
#include <cmath>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
long long N;
pair<long long,long long> dots[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> dots[i].first >> dots[i].second;
    long long cal = 0;
    FOR(i,N-1) {
        cal += dots[i].first * dots[i+1].second;
        cal -= dots[i+1].first * dots[i].second;
    }
    cal += dots[N].first * dots[1].second;
    cal -= dots[1].first * dots[N].second;
    cal = abs(cal);
    cout << fixed;
    cout.precision(1);
    cout << (double)round(cal*5)/10;
    return 0;
}