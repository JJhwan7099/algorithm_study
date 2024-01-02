#include <string>
#include <vector>

using namespace std;
int visit[200];
void dfs(int n, const vector<vector<int>>& computers)
{
    visit[n] = 1;
    for(int i=0; i<computers.size(); i++)
    {
        if(computers[n][i]==1)
        {
            if(visit[i]!=1) dfs(i,computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        if(visit[i]!=1)
        {
            dfs(i,computers);
            answer++;
        }
    }
    return answer;
}