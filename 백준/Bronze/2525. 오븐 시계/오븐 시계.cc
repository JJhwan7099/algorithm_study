#include <iostream>
using namespace std;
int main()
{
    int a, b, c; cin >> a >> b >> c;
    if(b+c/60>0)
    {
        a+=(b+c)/60;
        b=(b+c)%60;
        if(a > 23) a-=24;
    }
    cout << a << " " << b;
}