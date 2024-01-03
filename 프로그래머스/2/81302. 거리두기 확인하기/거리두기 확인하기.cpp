#include <string>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=0; i<N; i++)
int visit[5][5];
bool check = true;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(pair<int,int> p, int cnt, const vector<string>& map)
{
    int x = p.first;
    int y = p.second;
    visit[x][y]=1;
    if(cnt>0&&map[x][y]=='P')
    {
        check = false;
        return;
    }
    if(cnt<=1)
    {
        for(int i=0; i<4; i++)
        {
            int X = dx[i]+x;
            int Y = dy[i]+y;
            if(X<0||Y<0||X>4||Y>4) continue;
            else{
                if(visit[X][Y]!=1&&map[X][Y]!='X') dfs({X,Y},cnt+1,map);
            }
        }
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto&a : places)
    {
        check = true;
        vector<pair<int,int>> v;
        FOR(i,a.size())
        {
            FOR(j,a[i].length())
            {
                if(a[i][j]=='P') v.push_back({i,j});
            }
        }
        for(auto& b: v)
        {
            FOR(i,5)FOR(j,5) visit[i][j]=0;
            dfs(b,0,a);
        }
        if(check == true) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}