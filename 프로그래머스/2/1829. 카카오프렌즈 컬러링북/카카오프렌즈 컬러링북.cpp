#include <vector>
#define FOR(i,N) for(int i=0; i<N; i++)
using namespace std;
int visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int M,N;
void dfs(int x, int y,const int& color, int& cnt, const vector<vector<int>>& board)
{
    cnt++;
    visit[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X<0||Y<0||X>=M||Y>=N) continue;
        else if(board[X][Y]==color && visit[X][Y]!=1)
        {
            dfs(X,Y,color, cnt, board);
        }
    }
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    M = m;
    N = n;
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;
    FOR(i,m)FOR(j,n) visit[i][j]=0;
    FOR(i,m)FOR(j,n)
    {
        int cnt = 0;
        if(picture[i][j]!=0&&visit[i][j]!=1)
        {
            int c = picture[i][j];
            dfs(i,j,c,cnt,picture);
            answer[0]++;
            answer[1] = max(answer[1],cnt);
        }
    }
    return answer;
}