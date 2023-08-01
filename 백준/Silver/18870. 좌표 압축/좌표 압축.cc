#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int a; cin >> a;
    map<int, int> m;
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < a; i++)
    {
        int b; cin >> b;
        v1.push_back(b);
    }
    v2 = v1;
    sort(v2.begin(), v2.end());
    for(int i =0; i < a; i++)
    {
       m.insert(make_pair(v2[i],1));
    }
    int b = 0;
    for(auto&a : m)
    {
        m[a.first] = b++;
    }
    for(int i = 0; i < a; i++)
    {
        if( i == a-1)
            cout<< m[v1[i]];
        else
            cout << m[v1[i]] << " ";
    }
    return 0;
}