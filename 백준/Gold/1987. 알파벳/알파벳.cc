#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int R,C;
char graph[22][22];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans = 0;
void bfs()
{
    unordered_map<string,int> visit;
    queue<pair<pair<int,int>,pair<string,int>>> q;
    string a = "";
    a += graph[1][1];
    visit[to_string(1)+to_string(1)+a] = 1;
    q.push({{1,1},{a,1}});
    while(q.size()>0)
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        string s = "";
        s += q.front().second.first;
        int cnt = q.front().second.second;
        for(int i=0; i<4; i++)
        {            
            int X = x + dx[i];
            int Y = y + dy[i];
            string ss = s + graph[X][Y];
            bool check = true;
            if(X<1 || Y<1 || X > R || Y > C) continue;
            for(int j=0; j<s.length(); j++)
            {
                if(s[j] == graph[X][Y]) 
                {
                    check = false;
                    break;
                }
            }
            if(check == true && visit[to_string(X)+to_string(Y)+ss]!=1)
            {
                visit[to_string(X)+to_string(Y)+ss] = 1;
                q.push({{X,Y},{ss,cnt+1}});
            }else{
                if(ans < cnt) ans = cnt;
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> R >> C;
    fill(&graph[0][0],&graph[21][21],'0');
    FOR(i,R)FOR(j,C) cin >> graph[i][j];
    bfs();
    cout << ans;
}
