#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int visit[201][201];
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visit[0][0] = 1;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(x==maps.size()-1&&y==maps[0].size()-1)
        {
            answer = cnt;
            break;
        }
        for(int i=0; i<4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<0||Y<0||X>maps.size()-1||Y>maps[0].size()-1) continue;
            else{
                if(maps[X][Y]==1 && visit[X][Y]!=1)
                {
                    visit[X][Y]=1;
                    q.push({{X,Y},cnt+1});
                }
            }
        }
    }
    return answer;
}