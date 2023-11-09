#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    int n;
    int arr[100002];
    vector<char> v;
    vector<int> newarr;
    cin >> n;
    stack<int> s;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }
    int cnt=1;
    int pnum = 1;
    while(pnum<=n+1)
    {
        if(!s.empty() && s.top() == arr[cnt])
        {
            newarr.push_back(s.top());
            s.pop();
            v.push_back('-');
            cnt++;
        }else{
            if(pnum<=n)
            {
                s.push(pnum);
                v.push_back('+');
            }
            pnum++;
        }
    }
    if(newarr.size()!=n) cout << "NO";
    else for(auto&a:v) cout << a << '\n';
}