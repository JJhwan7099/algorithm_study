#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int graph[101][101];
vector<int> solution(int rows, int cols, vector<vector<int>> queries) {
    vector<int> answer;
    int cc=1;
    FOR(i,rows)FOR(j,cols){graph[i][j]=cc; cc++;}
    for(auto&a: queries)
    {
        queue<pair<int,int>> q1;
        deque<int> q2;
        int x1=a[0]; int y1=a[1]; int x2=a[2]; int y2=a[3];
        int x=x1; int y=y1;
        int mini = graph[x][y];
        while(y!=y2){q1.push({x,y}); q2.push_back(graph[x][y]); mini = min(mini,graph[x][y]); y++;}
        while(x!=x2){q1.push({x,y}); q2.push_back(graph[x][y]); mini = min(mini,graph[x][y]); x++;}
        while(y!=y1){q1.push({x,y}); q2.push_back(graph[x][y]); mini = min(mini,graph[x][y]); y--;}
        while(x!=x1){q1.push({x,y}); q2.push_back(graph[x][y]); mini = min(mini,graph[x][y]); x--;}
        q2.push_front(q2.back()); q2.pop_back();
        while(!q1.empty())
        {
            int X=q1.front().first; int Y=q1.front().second; int val = q2.front();
            q1.pop(); q2.pop_front();
            graph[X][Y] = val;
        }
        answer.push_back(mini);
    }
    return answer;
}