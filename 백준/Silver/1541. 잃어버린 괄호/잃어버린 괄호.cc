#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> num;
    stack<char> op;
    stack<int> st;
    string s;
    cin >> s;
    string S="";
    bool check = false;
    FOR(i,s.length())
    {
        if(isdigit(s[i-1])) S+=s[i-1];
        else if(!isdigit(s[i-1])&&s[i-1]!=' ')
        {
            if(!check) st.push(stoi(S));
            else
            {
                st.push(0-stoi(S));
                check = false;
            }
            if(s[i-1]=='-') check=true;  
            S="";          
        }
        if(i==s.length())
        {
            if(!check) st.push(stoi(S));
            else
            {
                st.push(0-stoi(S));
                check = false;
            }  
        }
    }
    int n = 0;
    int totsum = 0;
    vector<int> v;
    while(!st.empty())
    {
        totsum += st.top();
        if(st.top()>0) n+=st.top();
        else if(st.top()<0){
            v.push_back(n);
            n=0;
        }
        st.pop();
    }
    if(v.size()>0) 
    {
        for(auto&a:v) totsum-=2*a;
    }
    cout << totsum;
    return 0;
}