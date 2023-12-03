#include<iostream>
#include<set>
using namespace std;
int T;
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        int k; cin >> k;
        multiset<int> m;
        for(int j=0;j<k;j++)
        {
            char a; int b;
            cin >> a >> b;
            if(a=='I') m.insert(b);
            else{
                if(m.empty()) continue;
                else if(b==1)
                {
                    m.erase(prev(m.end()));
                }else{
                    m.erase(m.begin());
                }
            }
        }
        if(m.empty()) cout << "EMPTY\n";
        else{
            cout << *prev(m.end()) << " " << *m.begin() << '\n';
        }
    }
}