#include <string>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=0; i<N; i++)
int visit[101][101];
int N, M;
pair<int,int> gogo(int x, int y, int dx, int dy, const vector<string>& map)
{
    int X = x;
    int Y = y;
    while(true)
    {
        if(X+dx<0||Y+dy<0||X+dx>=map.size()||Y+dy>=map[0].length()) break;
        else{
            if(map[X+dx][Y+dy]=='D') break;
            else{
                X+=dx;
                Y+=dy;
            }
        }
    }
    return {X,Y};
}
int solution(vector<string> board) {
    int answer = -1;
    pair<int,int> start;
    N = board.size();
    M = board[0].length();
    FOR(i,board.size())FOR(j,board[i].length())
    {
        if(board[i][j]=='R') start = {i,j};
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{start.first,start.second},0});
    visit[start.first][start.second] = 1;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(board[x][y]=='G') return cnt;
        else{
            for(int i=0; i<4; i++)
            {
                pair<int,int> XY = gogo(x,y,dx[i],dy[i],board);
                if(visit[XY.first][XY.second]!=1)
                {
                    q.push({{XY.first,XY.second},cnt+1});
                    visit[XY.first][XY.second] = 1;
                }
            }
        }
    }
    return answer;
}