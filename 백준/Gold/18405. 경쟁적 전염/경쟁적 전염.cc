#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct location
{
    int vname, x, y;
};
struct compare
{
    bool operator()(location &a, location &b)
    {
        if(a.vname == b.vname) return a.x > b.x;
        return a.vname > b.vname;
    }
};
int N, K; 
int graph[202][202] = {0,};
bool visited[202][202] = {false,};
priority_queue<location,vector<location>,compare> q1;
int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> graph[i][j];
            location loc;
            if(graph[i][j]!=0)
            {
                loc.vname = graph[i][j];
                loc.x = i;
                loc.y = j;
                q1.push(loc);
                visited[i][j] = true;
            }
        }
    }
    int S, X, Y; cin >> S >> X >> Y;
    while(S--)
    {
        int cnt = q1.size();
        if(cnt == 0) break;
        priority_queue<location,vector<location>,compare> q2;
        while(cnt--)
        {
            location loc = q1.top(); q1.pop();
            if(1 <= loc.x && loc.x <= 200 && 1 <= loc.y && loc.y <= 200)
            {
                if ((graph[loc.x+1][loc.y] == 0 && loc.x+1 <= N))
                {
                    graph[loc.x + 1][loc.y] = loc.vname;
                    location l; l.x = loc.x + 1; l.y = loc.y; l.vname = loc.vname;
                    q2.push(l);
                    visited[loc.x+1][loc.y] = true;
                }

                if ((graph[loc.x-1][loc.y] == 0 && loc.x-1 >= 1))
                {
                    graph[loc.x - 1][loc.y] = loc.vname;
                    location l; l.x = loc.x - 1; l.y = loc.y; l.vname = loc.vname;
                    q2.push(l);
                    visited[loc.x-1][loc.y] == true;
                }

                if ((graph[loc.x][loc.y+1] == 0 && loc.y+1 <= N ))
                {
                    graph[loc.x][loc.y + 1] = loc.vname;
                    location l; l.x = loc.x; l.y = loc.y + 1; l.vname = loc.vname;
                    q2.push(l);
                    visited[loc.x][loc.y+1] == true;
                }

                if ((graph[loc.x][loc.y-1] == 0 && loc.y-1 >= 1))
                {
                    graph[loc.x][loc.y - 1] = loc.vname;
                    location l; l.x = loc.x; l.y = loc.y - 1; l.vname = loc.vname;
                    q2.push(l);
                    visited[loc.x][loc.y-1] == true;
                }
            }
        }
        q1 = q2;
    }
    int answer = graph[X][Y];
    cout << answer;
    
    return 0;
}