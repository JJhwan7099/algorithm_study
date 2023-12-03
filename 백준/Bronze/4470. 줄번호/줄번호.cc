#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> l;
    int n; cin >> n; cin.ignore();
    for(int i=0; i<n; i++){
        string s;
        getline(cin, s);
        l.push_back(s);
    }
    for(int i=1; i<=l.size(); i++)
    {
        cout << i << ". " << l[i-1] << '\n';
    }
    return 0;
}