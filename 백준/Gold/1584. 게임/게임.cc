#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[501][501];
int vis[501][501];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
void dijk() {
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << "," << y << endl;
        q.pop();
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X<0||Y<0||X>500||Y>500||graph[X][Y]==2) continue;
            else if((vis[X][Y]==0 || vis[X][Y]>vis[x][y]+graph[X][Y])) {
                vis[X][Y]=vis[x][y]+graph[X][Y];
                q.push({X,Y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        vector<int> x;
        vector<int> y;
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back(x1); x.push_back(x2);
        y.push_back(y1); y.push_back(y2);
        sort(x.begin(), x.end()); sort(y.begin(), y.end());
        for(int i=x[0]; i<=x[1]; i++)for(int j=y[0]; j<=y[1]; j++) {
            graph[i][j]=1;//위험한 구역
        }
    }
    cin >> M;
    FOR(i,M) {
        vector<int> x;
        vector<int> y;
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back(x1); x.push_back(x2);
        y.push_back(y1); y.push_back(y2);
        sort(x.begin(), x.end()); sort(y.begin(), y.end());
        for(int i=x[0]; i<=x[1]; i++)for(int j=y[0]; j<=y[1]; j++) {
            graph[i][j]=2;//죽음의 구역
        }
    }
    dijk();
    cout << vis[500][500]-1;
    return 0;
}