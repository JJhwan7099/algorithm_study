#include <iostream>
using namespace std;
int main()
{
    int a; cin >> a;
    int arr[101];
    for(int i = 1; i <= a; i++)
    {
        cin >> arr[i];
    }
    int b; cin >> b;
    int count = 0;
    for(int i = 1; i <= a; i++)
    {
        if(arr[i]==b) count++;
    }
    cout << count;
}