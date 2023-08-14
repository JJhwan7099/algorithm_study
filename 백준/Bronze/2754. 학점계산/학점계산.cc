#include <iostream>
using namespace std;
int main()
{
    string a; cin >> a;
    float b;
    if(a[0]=='F')
    {
        cout << "0.0";
        return 0;
    }
    if(a[0] == 'A')
    {
        b = 4.0;
    }else if(a[0] == 'B')
    {
        b = 3.0;
    }else if(a[0] == 'C')
    {
        b = 2.0;
    }else if(a[0] == 'D')
    {
        b = 1.0;
    }
    if(a[1]=='+')
    {
        cout << b + 0.3;
    }else if(a[1]=='0')
    {
        printf("%.1lf",b);
    }else if(a[1]=='-')
    {
        cout << b - 0.3;
    }
    return 0;
}