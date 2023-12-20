#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int n,m;
vector<int> graph[201];
int cost[201][201];
string r[201][201];
void bfs(int x)
{
    FOR(i,n)
    {
        r[x][i] = to_string(x) + " ";
    }
    int tcost[201];
    FOR(i,n) tcost[i] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int X = q.front();
        q.pop();
        for(int j = 0; j<graph[X].size(); j++)
        {
            int i = graph[X][j];
            if(i!=x && (tcost[i]==0 || tcost[i] > tcost[X] + cost[X][i]))
            {
                r[x][i] = r[x][X] + to_string(i) + " ";
                tcost[i] = tcost[X] + cost[X][i];
                q.push(i);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    FOR(i,m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(cost[a][b]==0)
        {
            cost[a][b] = c;
            cost[b][a] = c;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }else if(cost[a][b]>c){
            cost[a][b] = c;
            cost[b][a] = c;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    FOR(i,n) bfs(i);
    FOR(i,n)
    {
        FOR(j,n)
        {
            vector<string> v;
            string s = "";
            for(int k=0; k<r[i][j].length(); k++)
            {
                if(r[i][j][k]==' ')
                {
                    v.push_back(s);
                    s = "";
                }else{
                    s+=r[i][j][k];
                }
            }
            if(v.size()==1) cout << "- ";
            else cout << v[1] << " ";
        }
        cout << '\n';
    }
}