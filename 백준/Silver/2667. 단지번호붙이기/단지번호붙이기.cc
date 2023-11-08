#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int graph[26][26];
int visit[26][26];
vector<int> v;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void dfs(int x, int y, int cnt, int &max)
{
    visit[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(visit[X][Y]!=1 && graph[X][Y]==1)
        {
            dfs(X,Y,cnt+1,max);
        }
    }
    max++;
}
int main()
{
int ccnt=0;
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        string s; cin >> s;
        for(int j=1; j<=s.length(); j++)
        {
            graph[i][j] = s[j-1]-'0';
        }
    }
    for(int i=1;i<=N;i++)for(int j=1; j<=N; j++)
    {
        if(visit[i][j]!=1 && graph[i][j]==1)
        {
            ccnt++;
            int max = 0;
            dfs(i,j,1, max);
            v.push_back(max);
        }
    }
    cout << ccnt << '\n';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << '\n';
    }
}