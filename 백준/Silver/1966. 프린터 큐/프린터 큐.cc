#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
bool check(queue<pair<int,int>> q)
{
    int a1, a2;
    a1 = q.front().first; a2 = q.front().second;
    q.pop();
    while(!q.empty())
    {
        if(a2<q.front().second) return false;
        else q.pop();
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        queue<pair<int,int>> q;
        for(int i=0; i<a; i++)
        {
            int c; cin >> c;
            q.push({i,c});
        }
        int cnt = 1;
        while(!q.empty())
        {
            if(check(q))
            {
                if(q.front().first == b)
                {
                    cout << cnt << '\n';
                    break;
                }else{
                    cnt++;
                    q.pop();
                }
            }else{
                pair<int,int> p = q.front();
                q.push(p);
                q.pop();
            }
        }
    }
    return 0;
}