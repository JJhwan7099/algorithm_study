#include <string>
#include <vector>

using namespace std;
int visit[20][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dfs(const vector<vector<string>>&board,int x,int y)
{
    int cnt=0;
    string color = board[x][y];
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<0||Y<0||X>=board.size()||Y>=board.size()) continue;
        else if(board[X][Y]==color)
        {
            cnt++;
        }
    }
    return cnt;
}
int solution(vector<vector<string>> board, int h, int w) {
    return dfs(board,h,w);
}