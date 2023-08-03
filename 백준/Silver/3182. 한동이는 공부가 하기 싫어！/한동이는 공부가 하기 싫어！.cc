#include <iostream>
#include <string.h>
using namespace std;
int graph[1001][1001];
int result[1001];
int visited[1001][1001];
int count = 0;
int N;
void search(int n)
{
    for(int i = 1; i <= N; i++)
    {
        if(graph[n][i]==1 && (visited[n][i] == 0 && visited[i][n] == 0))
        {
            // cout << n << " -> " << i << '\n';
            count++;
            visited[n][i] = 1; visited[i][n] = 1;
            search(i);
        }
    }
    return;
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)//그래프 완성
    {
        int a; cin >> a;
        graph[i][a] = 1;
    }
    for(int i = 1; i <= N; i++)
    {
        search(i);
        result[i] = count + 1;
        count = 0;
        memset(visited, 0, sizeof(visited));
    }
    int max = result[0];
    int maxi;
    for(int i = 1; i <= N; i++)
    {
        if(result[i] > max) 
        {
            max = result[i];
            maxi = i;
        }
    }
    cout << maxi;
}