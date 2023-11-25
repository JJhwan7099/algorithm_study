#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n,x;
int main()
{
    map<int,int> m;
    vector<int> v;
    cin >> n;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int a; cin >> a;
        m[a]++;
    }
    cin >> x;
    for(int i=1; i<x; i++)
    {
        while(m[i]--)
        {
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++)
    {
        if(v[i]+v[j]==x)cnt++;
        else if(v[i]+v[j]>x) break;
    }
    cout << cnt;
}