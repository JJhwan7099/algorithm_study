#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<pair<int,int>> v;
int len=-1;
pair<int,int> line;
bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first==b.first) return a.second < b.second;
    return a.first<b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int result = 0;
    for(auto&pair:v) {
        if(len==-1) {
            len=0;
            line.first=pair.first;
            line.second=pair.second;
        }
        else if(line.second<pair.first) {
            result+=line.second-line.first;
            line.first=pair.first;
            line.second=pair.second;
        }
        else{
            if(line.second<pair.second) line.second=pair.second;
        }
    }
    result+=line.second-line.first;
    cout <<result;
    return 0;
}