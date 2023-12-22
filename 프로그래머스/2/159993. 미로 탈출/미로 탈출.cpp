#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=0; i<N; i++)
int solution(vector<string> maps) {
    int answer = -1;
    pair<int,int> s;
    pair<int,int> l;
    FOR(i,maps.size())FOR(j,maps[i].length())
    {
        if(maps[i][j]=='S') s = {i,j};
        else if(maps[i][j]=='L') l = {i,j};
    }
    int xlen = maps.size();
    int ylen = maps[0].length();
    int cost[100][100];
    FOR(i,xlen)FOR(j,ylen) cost[i][j] = -1;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    queue<pair<pair<int,int>,pair<bool,int>>> q;
    q.push({{s},{0,0}});
    cost[s.first][s.second] = 0;
    
    int dis;
    bool check = false;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool open = q.front().second.first;
        int cnt = q.front().second.second;
        if(x==l.first && y==l.second)
        {
            dis = cnt;
            check = true;
            break;
        }
        q.pop();
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<0 || X>=xlen || Y<0 || Y>=ylen ) continue;
            else
            {
                if(maps[X][Y]!='X' && (cost[X][Y]==-1||cost[X][Y]>cost[x][y]+1))
                {
                    cost[X][Y] = cost[x][y]+1;
                    q.push({{X,Y},{open,cnt+1}});
                }
            }
        }
    }
    while(!q.empty()) q.pop();
    FOR(i,xlen)FOR(j,ylen) cost[i][j] = -1;
    if(check)
    {
        q.push({{l.first,l.second},{1,dis}});
        cost[l.first][l.second] = 0;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            q.pop();
            if(maps[x][y]=='E')
            {
                answer = dis + cost[x][y];
            }
            for(int i=0; i<4; i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X<0 || Y<0 || X>=xlen || Y>= ylen) continue;
                if(maps[X][Y]!='X' && (cost[X][Y]==-1 || cost[X][Y] > cost[x][y] + 1))
                {
                    cost[X][Y] = cost[x][y] + 1;
                    q.push({{X,Y},{1,1}});
                }
            }
        }
    }
    return answer;
}