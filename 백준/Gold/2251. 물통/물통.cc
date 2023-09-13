#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int A,B,C;
vector<int> ans;
unordered_map<string,int> um;
struct cup{
    int size, L;
};
struct three{
    cup a, b, c;
};
pair<int,int> pour(cup a, cup b) //a를 b에 붓는다.
{
    int c, d;
    if(a.L > b.size - b.L)
    {
        c = a.L - b.size + b.L;
        d = b.size;
    }else{
        c = 0;
        d = a.L + b.L;
    }
    pair<int,int> p;
    p = {c,d};
    return p;
}
void bfs()
{
    three t; 
    t.a.size = A; t.b.size = B; t.c.size = C;
    t.a.L = 0; t.b.L = 0; t.c.L=C;
    string s = "";
    s = to_string(t.a.L) + ',' + to_string(t.b.L) + ',' + to_string(t.c.L);
    um[s] = 1;
    queue<three> q;
    q.push(t);
    while(q.size() > 0)
    {
        three th = q.front();
        cup a, b, c;
        a = th.a; b = th.b; c = th.c;
        if(a.L==0)
        {
            ans.push_back(c.L);
        }
        // a를 b에
        if(a.L!=0 && b.L!=b.size)
        {
            pair<int,int> p = pour(a,b);
            string ss = "";
            ss = to_string(p.first)+','+to_string(p.second)+','+to_string(c.L);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = p.first; cb.L = p.second; cc.L = c.L;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        // a를 c에
        if(a.L!=0 && c.L!=c.size)
        {
            pair<int,int> p = pour(a,c);
            string ss = "";
            ss = to_string(p.first)+','+to_string(b.L)+','+to_string(p.second);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = p.first; cb.L = b.L; cc.L = p.second;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        // b를 c에
        if(b.L!=0 && c.L!=c.size)
        {
            pair<int,int> p = pour(b,c);
            string ss = "";
            ss = to_string(a.L)+','+to_string(p.first)+','+to_string(p.second);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = a.L; cb.L = p.first; cc.L = p.second;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        // b를 a에
        if(b.L!=0 && a.L!=a.size)
        {
            pair<int,int> p = pour(b,a);
            string ss = "";
            ss = to_string(p.second)+','+to_string(p.first)+','+to_string(c.L);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = p.second; cb.L = p.first; cc.L = c.L;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        // c를 a에
        if(c.L!=0 && a.L!=a.size)
        {
            pair<int,int> p = pour(c,a);
            string ss = "";
            ss = to_string(p.second)+','+to_string(b.L)+','+to_string(p.first);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = p.second; cb.L = b.L; cc.L = p.first;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        // c를 b에
        if(c.L!=0 && b.L!=b.size)
        {
            pair<int,int> p = pour(c,b);
            string ss = "";
            ss = to_string(a.L)+','+to_string(p.second)+','+to_string(p.first);
            if(um[ss]!=1)
            {
                um[ss]=1;
                cup ca,cb,cc;
                ca.size = A; cb.size = B; cc.size = C;
                ca.L = a.L; cb.L = p.second; cc.L = p.first;
                three tt;
                tt.a = ca; tt.b = cb; tt.c = cc;
                q.push(tt);
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> A >> B >> C;
    bfs();
    sort(ans.begin(),ans.end());
    for(auto&a : ans)
    {
        cout << a << " ";
    }
}