#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
int graph[301][301];
int visit[301][301];
int year = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void Print() // 테스트용
{
    cout << "test*****\n";
    for(int i=0; i < N; i++)
    { 
        for(int j=0; j < M; j++) cout << graph[i][j] << " "; 
        cout << endl;
    }
}
void dfs(int x, int y) 
{
    int X,Y;
    for(int i=0; i<4; i++)
    {
        X = x + dx[i]; Y = y + dy[i];
        if(graph[X][Y] > 0 && visit[X][Y] == 0)
        {
            visit[X][Y] = 1;
            dfs(X,Y);
        }
    }
}
int icecount() // 얼음 덩이 수 세기
{
    int ice = 0;
    fill(&visit[0][0],&visit[300][300],0);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++)
    {
        if(graph[i][j] > 0 && visit[i][j] == 0)
        {
            visit[i][j] = 1;
            dfs(i,j);
            ice++;
        }
    }
    return ice;
}
void doing() // 1년 후
{
    fill(&visit[0][0],&visit[300][300],0);
    for(int i=0; i<N; i++) for(int j=0; j<M; j++)
    {
        if(graph[i][j]>0)
        {
            visit[i][j] = 1;
            for(int k=0; k<4; k++)
            {
                int X = i + dx[k]; int Y = j + dy[k];
                if(graph[X][Y] == 0 && visit[X][Y] == 0)
                {
                    if(graph[i][j] == 0) break;
                    else{
                        graph[i][j]--;
                    }
                }
            }
        }
    }
}
int main()
{
    fill(&graph[0][0],&graph[300][300],-1);
    cin >> N >> M;
    for(int i=0; i < N; i++) for(int j=0; j < M; j++) cin >> graph[i][j];
    while(true)
    {
        if(icecount() >= 2)
        {
            cout << year;
            return 0;
        }else if(icecount() == 0)
        {
            cout << "0";
            return 0;
        }else{
            doing();
            year++;
        }
    }
}