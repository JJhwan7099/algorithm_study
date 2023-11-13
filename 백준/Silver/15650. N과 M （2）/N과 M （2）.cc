#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int N,M;
unordered_map<string,int> m;
vector<string> v;
void start(int n,string s)
{
    string ss = s;
    unordered_map<int,int> m1;
    int max = ss[ss.length()-1]-'0';
    if(m[ss]!=1 && ss.length()==M)
    {
        m[ss]=1;
        v.push_back(ss);
    }
    else if(ss.length()>M)
    {
        return;
    }
    for(int i=0; i<ss.length(); i++)
    {
        m1[ss[i]-'0'] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        if(m1[i]!=1 && i>max)
        {
            start(n, ss+to_string(i));
        }
    }
}
int main()
{
    cin >> N >> M;
    start(N, "");
    for(auto&a : v)
    {
        for(int i=0; i<a.length(); i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}