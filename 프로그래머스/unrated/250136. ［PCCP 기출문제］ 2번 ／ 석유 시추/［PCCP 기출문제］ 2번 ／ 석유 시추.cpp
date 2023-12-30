#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=0; i<N;i++)
int cnt = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int visit[501][501];
int linevisit[501];
int oil[501];
vector<int> v;
void dfs(int x, int y, const vector<vector<int>>& land)
{
    cnt++;
    visit[x][y]=1;
    v.push_back(y);
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<0||Y<0||X>=land.size()||Y>=land[0].size()) continue;
        else if(visit[X][Y]!=1&&land[X][Y]==1)
        {
            dfs(X,Y,land);
        }
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    FOR(i,land.size())FOR(j,land[i].size())
    {
        if(land[i][j]==1&&visit[i][j]!=1)
        {
            dfs(i,j,land);
            for(auto&a:v) 
            {
                if(linevisit[a]!=1)
                {
                    linevisit[a]=1;
                    oil[a]+=cnt;
                }
            }
            FOR(k,land[0].size()) linevisit[k]=0;
            v.clear();
            cnt = 0;
        }
    }
    FOR(k,land[0].size()) answer = max(answer, oil[k]);
    return answer;
}