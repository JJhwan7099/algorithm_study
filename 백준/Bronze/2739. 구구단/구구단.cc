#include <iostream>
using namespace std;
int main()
{
    int a; cin >> a;
    for(int i = 1; i <= 9; i++)
    {
        if(i == 9)
        {
            cout << a << " * " << i << " = " << a*i;
            return 0;
        }
        cout << a << " * " << i << " = " << a*i << '\n';
    }
}