#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
map<pair<int,int>,int> m;
map<pair<int,int>,int> visit;
int nx, ny, fx, fy;
void bfs(int x, int y)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},20});
    visit[{x,y}]=1;
    while(!q.empty())
    {
        int X = q.front().first.first;
        int Y = q.front().first.second;
        int n = q.front().second;
        q.pop();
        if(X==fx&&Y==fy)
        {
            cout << "happy\n";
            return;
        }
        for(auto&a:m)
        {
            int dis = abs(a.first.first-X)+abs(a.first.second-Y);
            if(dis<=1000 && visit[{a.first.first,a.first.second}]!=1)
            {
                visit[{a.first.first,a.first.second}]=1;
                q.push({{a.first.first,a.first.second},n});
            }
        }
    }
    cout << "sad\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >>T;
    while(T--)
    {
        m.clear();
        visit.clear();
        int n; cin >> n;
        cin >> nx >> ny;
        FOR(i,n)
        {
            int a, b; cin >> a >> b;
            m[{a,b}]=1;
        }
        cin >> fx >> fy;
        m[{fx,fy}]=2;
        bfs(nx,ny);
    }
    return 0;
}