#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<int,int>> m;
int day[1001];
bool cmp(pair<int,int> & a, pair<int,int> & b)
{
    if(a.first==b.first) return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int a,b; cin >> a >> b;
        m.push_back({b,a});
    }
    sort(m.begin(),m.end(),cmp);
    for(int i=1; i<=N; i++) day[i] = 0;
    for(auto&a:m)
    {
        int i = a.second;
        while(true)
        {
            if(i==0) break;
            else if(day[i]==0) 
            {
                day[i] = a.first;
                break;
            }
            else i--;
        }
    }
    int sum = 0;
    for(int i=1; i<=1000; i++) sum += day[i];
    cout << sum;
}