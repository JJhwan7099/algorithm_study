#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visit[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt = 0;
void dfs(int x, int y, const vector<string>& map)
{
    visit[x][y]=1;
    cnt += map[x][y]-'0';
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<0||Y<0||X>=map.size()||Y>=map[0].length()) continue;
        if(visit[X][Y]!=1 && map[X][Y]!='X')
        {
            dfs(X,Y,map);
        }
    }
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i=0;i<maps.size();i++)for(int j=0;j<maps[0].length();j++)
    {
        if(maps[i][j]!='X'&&visit[i][j]!=1)
        {
            cnt = 0;
            dfs(i,j,maps);
            answer.push_back(cnt);
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size()==0) answer.push_back(-1);
    return answer;
}