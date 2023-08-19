#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,L;
vector<pair<int,int>> v1;
int result = 0;
bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}
void search()
{
    int start = v1[0].first;
    for(int i=0; i<v1.size(); i++)
    {
        int end = v1[i].second;
        if(start < v1[i].first) start = v1[i].first;
        int len = end - start;
        if(len <= 0) continue;
        int cnt = 0;
        if(len % L == 0) cnt = len / L;
        else cnt = len / L + 1;
        result += cnt;
        start = start + cnt * L;
    }
}
int main()
{
    cin >> N >> L;
    FOR(i,N)
    {
        int a,b; cin >> a >> b;
        v1.push_back({a,b});
    }
    sort(v1.begin(),v1.end(),compare);
    search();
    cout << result;
}