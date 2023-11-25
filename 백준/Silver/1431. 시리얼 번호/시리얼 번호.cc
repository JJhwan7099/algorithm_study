#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
vector<string> v;
bool cmp(string& a, string& b)
{
    if(a.length()!=b.length())
    {
        return a.length()<b.length();
    }else{
        int aa=0;
        int bb=0;
        for(int i=0; i<a.length(); i++)
        {
            if(isdigit(a[i])) aa+=a[i]-'0';
            if(isdigit(b[i])) bb+=b[i]-'0';
        }
        if(aa!=bb) return aa<bb;
        return a < b;
    }
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(),cmp);
    for(auto&a: v) cout << a << '\n';
}