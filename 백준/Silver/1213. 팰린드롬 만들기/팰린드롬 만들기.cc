#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    string a; cin >> a;
    char mid;
    int midcnt = 0;
    vector<char> v1;
    map<char, int> m1;
    for(int i = 0; i < a.length(); i++)
    {
        m1[a[i]]++; 
    }
    for(auto&pair : m1)
    {
        if(pair.second % 2 != 0)
        {
            mid = pair.first;
            pair.second--;
            midcnt++;
        }
        pair.second = pair.second / 2;
        while(pair.second--)
        {
            v1.push_back(pair.first);
        } 
    }
    if(midcnt > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i];
    }
    if(midcnt == 1)
    {
        cout << mid;
    }
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[v1.size()-i-1];
    }
    return 0;
}