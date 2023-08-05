#include <iostream>
using namespace std;
int main()
{
    int a; cin >> a;
    if(a >= 60)
    {
        if(a>= 70)
        {
            if(a>=80)
            {
                if(a>=90) cout << "A";
                else cout << "B";
            }else cout << "C";
        }else cout<< "D";
    }else cout << "F";
    return 0;
}