#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,K;
int arr[9];
int karr[9];
int ans=-1;
string swap(string ss, int l)
{
    stack<int> s;
    string sss = "";
    string start="";
    string end="";
    for(int i=0; i<ss.length(); i++)
    {
        if(i<l) start += ss[i];
        else if(i>=l+K) end += ss[i];
        else s.push(ss[i]);
    }
    while(s.size()>0)
    {
        sss += s.top();
        s.pop();
    }
    string result = "";
    result += start;
    result += sss;
    result += end;
    return result;
}
bool check(string s)
{
    int tot = s.length();
    int cnt=1;
    FOR(i,s.length()-1)
    {
        if(s[i-1]<s[i]) cnt++;
    }
    if(cnt==tot) return true;
    else return false;
}
void bfs(string s)
{
    queue<pair<string,int>> q;
    q.push({s,0});
    unordered_map<string,int> m;
    m[s] = 1;
    while(q.size()>0)
    {
        string ss = q.front().first;
        int cnt = q.front().second;
        if(check(ss)){
            ans = cnt;
            break;
        }
        for(int i=0; i<= ss.length()-K; i++)
        {
            string a = swap(ss,i);
            if(m[a]!=1)
            {
                m[a] = 1;
                q.push({a,cnt+1});
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> N >> K;
    string s = "";
    FOR(i,N)
    {
        string a;
        cin >> a; s+=a;
    }
    bfs(s);
    cout << ans;
}