#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
struct cmp
{
    bool operator()(int a, int b)
    {
        if(abs(a)==abs(b)) return a>b;
        else return abs(a)>abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    priority_queue<int,vector<int>,cmp> q;
    FOR(i,n)
    {
        int a; cin >> a;
        if(a==0)
        {
            if(q.empty()) cout << 0 << '\n';
            else{
                cout << q.top() << '\n';
                q.pop();
            }
        }else{
            q.push(a);
        }
    }
    return 0;
}