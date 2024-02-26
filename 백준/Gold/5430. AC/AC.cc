#include<iostream>
#include<deque>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
string doing(deque<int>& dq, string cmd)
{
    bool b = true;
    for(int i=0; i<cmd.length(); i++)
    {
        if(cmd[i]=='R')
        {
            if(b) b=false;
            else b=true;
        }
        else if(cmd[i]=='D')
        {
            if(dq.size()==0) return "error";
            else{
                if(b)
                {
                    dq.pop_front();
                }else dq.pop_back();
            }
        }
    }
    string ss = "[";
    if(b)
    {
        while(!dq.empty())
        {
            if(dq.size()==1) ss+=to_string(dq.front());
            else ss+=to_string(dq.front())+",";
            dq.pop_front();
        }
    }else{
        while(!dq.empty())
        {
            if(dq.size()==1) ss+=to_string(dq.back());
            else ss+=to_string(dq.back())+",";
            dq.pop_back();
        }
    }
    ss+="]";
    return ss;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        deque<int> dq;
        string cmd = "";
        cin >> cmd;
        int n;
        string s;
        cin >> n >> s;
        string num="";
        for(int i=0; i<s.length(); i++)
        {
            if(num!=""&&(s[i]==','||s[i]==']'))
            {
                dq.push_back(stoi(num));
                num="";
            }
            else if(isdigit(s[i]))
            {
                num+=s[i];
            }
        }
        cout << doing(dq,cmd) << '\n';
    }
    return 0;
}