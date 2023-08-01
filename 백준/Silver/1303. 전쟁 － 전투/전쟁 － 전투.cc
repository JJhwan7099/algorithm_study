#include <iostream>
#include <vector>
using namespace std;
int N, M; 
int graph[101][101] = {0,};
int cnt;
int Wresult = 0;
int Bresult = 0;
vector<int>Wanswer;
vector<int>Banswer;
void dfs(int i, int j, int n)//아군 탐색끝 > -1, 적군 탐색끝 > -2
{
    if(n == 1)
    {
        graph[i][j] = -1;
        if(graph[i][j+1] == 1)
        {
            dfs(i, j+1, 1);
            cnt++;
        }
        if(graph[i+1][j] == 1)
        {
            dfs(i+1, j, 1);
            cnt++;
        }
        if(graph[i][j-1]==1)
        {
            dfs(i, j-1, 1);
            cnt++;
        }if(graph[i-1][j]==1){
            dfs(i-1, j, 1);
            cnt++;
        }if(graph[i][j+1] != 1 && graph[i+1][j]!=1 && graph[i][j-1] != 1 && graph[i-1][j] != 1)
        {
            return;
        }
    }else if(n == 2)
    {
        graph[i][j] = -2;
        if(graph[i][j+1] == 2)
        {
            dfs(i, j+1, 2);
            cnt++;
        }
        if(graph[i+1][j] == 2)
        {
            dfs(i+1, j, 2);
            cnt++;
        }
        if(graph[i][j-1]==2)
        {
            dfs(i, j-1, 2);
            cnt++;
        }if(graph[i-1][j]==2){
            dfs(i-1, j, 2);
            cnt++;
        }if(graph[i][j+1] != 2 && graph[i+1][j]!=2 && graph[i][j-1] != 2 && graph[i-1][j] != 2)
        {
            return;
        }
    }
    
}
int main()
{
    cin >> N >> M; //N이 가로, M이 세로
    cin.ignore();
    for(int i = 1; i < M+1; i++)
    {
        for(int j = 1; j < N+1; j++)
        {
            char c; cin >> c;
            if(c == 'W') c = 1; else c = 2;
            graph[j][i] = (int)c;
        }
        // cin.ignore();
    }
    for(int i = 1; i < M+1; i++)
    {
        for(int j = 1; j < N+1; j++)
        {
            if(graph[j][i] == 1)
            {
                cnt = 1;
                dfs(j,i,1);
                Wresult += cnt * cnt;
            }else if(graph[j][i] == 2)
            {
                cnt = 1;
                dfs(j,i,2);
                Bresult += cnt * cnt;
            }else
                continue;
        }
    }
    // for(int j = 1; j < M+1; j++)
    // {
    //     for(int i = 1; i < N+1; i++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << Wresult << " " << Bresult;
    return 0;
}