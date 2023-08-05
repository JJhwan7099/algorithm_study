#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int> m;
    int a; cin >> a; m[a]++;
    int b; cin >> b; m[b]++;
    int c; cin >> c; m[c]++;
    if(a==b && b==c)
    {
        cout << 10000 + a * 1000;
        return 0;
    }
    if(a==b && b!=c)
    {
        cout << 1000 + a*100;
        return 0;
    }
    if(b==c && c!=a)
    {
        cout << 1000 + b*100;
        return 0;
    }
    if(c==a && a!=b)
    {
        cout << 1000 + c*100;
        return 0;
    }
    if(a>b)
    {
        if(a>c)
        {
            cout << a*100;
            return 0;
        }else if(c>a)
        {
            cout << c*100;
        }
    }
    else if(b>a)
    {
        if(c>b)
        {
            cout << c*100;
            return 0;
        }
        else if(b>c)
        {
            cout << b*100;
            return 0;
        }
    }
}