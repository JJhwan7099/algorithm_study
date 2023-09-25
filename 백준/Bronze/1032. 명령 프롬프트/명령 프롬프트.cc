#include<iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            cin >> s;
        }
        else{
            string ss; cin >> ss;
            for(int j=0; j<s.length(); j++)
            {
                if(ss[j]!=s[j]) s[j] = '?';
            }
        }
    }
    cout << s;
}