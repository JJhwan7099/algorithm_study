#include <iostream>
#include <map>
using namespace std;
map<char, int>color;
int check = -1;
int main()
{
    int N; cin >> N;
    string s; cin >> s;
    for(int i = 0; i < N; i++)
    {
        
        if(i==N-1)
        {
            // if(s[i-1] != s[i])
            // {
                color[s[i]]++;
            // }
            continue;
        }
        else if(s[i] != s[i+1]) 
        {
            check++;
            color[s[i]]++;
        }
        else if(s[i] == s[i+1])
        {
            continue;
        }
    }
    // for(auto&pair : color)
    // {
    //     cout << pair.first << " " << pair.second << '\n';
    // }
    int count = 1;
    // if(check == 0)
    // {
    //     cout << "2";
    //     return 0;
    // }
    if(color['B']>color['R'])
    {
        count += color['R'];
    }else
    {
        count += color['B'];
    }
    cout << count;
    return 0;
}