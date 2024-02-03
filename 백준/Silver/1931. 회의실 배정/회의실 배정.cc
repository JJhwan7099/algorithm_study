#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int,int>> v;
bool cmp(pair<int,int>a, pair<int,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int ans = 0;
    int t = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(t<=v[i].first) {ans++; t=v[i].second;}
    }
    cout << ans;
}