#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int T;
int num(int n)
{
    if(n < 10000 && n > 999) return n;
    else if(n < 1000 && n > 99) return n%1000;
    else if(n < 100 && n > 9) return n%100;
    else if(n < 10 && n > 0) return n%10;
    else if(n == 0) return 0;
}
int D(int n)
{
    return (n*2) % 10000;
}
int S(int n)
{
    if(n==0) return 9999;
    else return n-1;
}
int L(int n)
{
    int a = (n%1000) * 10;
    int b = n/1000;
    a += b;
    return a;
}
int R(int n)
{
    int a = n/10;
    int b = (n%10) * 1000;
    a += b;
    return a;
}
string bfs(int a, int b)
{
    int visit[10000] = {0,};
    queue<pair<int,string>> q;
    q.push({a,""});
    while(q.size() > 0)
    {
        int n = q.front().first;
        string s = q.front().second;
        if(n == b)
        {
            return s;
        }
        int nd = D(n);
        int ns = S(n);
        int nl = L(n);
        int nr = R(n);
        if(visit[nd] == 0)
        {
            visit[nd] = 1;
            string ss = s + 'D';
            q.push({nd,ss});
        }
        if(visit[ns] == 0)
        {
            visit[ns] = 1;
            string ss = s + 'S';
            q.push({ns,ss});
        }
        if(visit[nl] == 0)
        {
            visit[nl] = 1;
            string ss = s + 'L';
            q.push({nl,ss});
        }
        if(visit[nr] == 0)
        {
            visit[nr] = 1;
            string ss = s + 'R';
            q.push({nr,ss});
        }
        q.pop();
    }
}
int main()
{
    cin >> T;
    vector<string> v;
    FOR(i,T)
    {
        int a,b; cin >> a >> b;
        a = num(a); b = num(b);
        v.push_back(bfs(a,b));
    }
    for(auto&a : v) cout << a << '\n';
}