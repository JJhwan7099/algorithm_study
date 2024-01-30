#include <string>
#include <vector>

using namespace std;
vector<int> graph[102];
int visit[102];
int cnt = 0;
void dfs(int N, int s, int e)
{
    cnt++;
    visit[N]=1;
    for(int i=0; i<graph[N].size(); i++)
    {
        if(visit[graph[N][i]]==0 && !((N==s && graph[N][i]==e) || (N==e && graph[N][i]==s)))
        {
            dfs(graph[N][i],s,e);
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    for(auto&a: wires)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    for(auto&a: wires)
    {
        for(int i=1; i<=n; i++) visit[i]=0;
        vector<int> ccnt;
        for(int i=1; i<=n; i++)
        {
            if(visit[i]!=1)
            {
                cnt = 0;
                dfs(i,a[0],a[1]);
                ccnt.push_back(cnt);
            }
        }
        if(ccnt.size()==2)
        {
            answer = min(answer,abs(ccnt[0]-ccnt[1]));
        }
    }
    return answer;
}