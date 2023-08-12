#include <iostream>
#include <queue>
#define FOR(i,N) for(int i=0;i<=N;i++)
using namespace std;
int N, M;
int graph[102][102];
int visit[102][102];
bool check = false;
struct three
{
    int num1, num2, num3;
};
vector<three> v1;
void search(int x, int y, three t)
{
    if (x == M)
    {
        check = true;
        return;
    }
    int a = graph[x][y];
    int b[4] = { 0 , 1, -1, 0 };
    int c[4] = { 1 , 0, 0, -1 };
    if (a == t.num1 || a == t.num2 || a == t.num3)
    {
        for (int i = 0; i < 4; i++)
        {
            if (graph[x + b[i]][y + c[i]] == t.num1 || graph[x + b[i]][y + c[i]] == t.num2 || graph[x + b[i]][y + c[i]] == t.num3)
            {
                if (visit[x + b[i]][y + c[i]] != 1)
                {
                    visit[x + b[i]][y + c[i]] = 1;
                    search(x + b[i], y + c[i], t);
                }
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i, M + 1)FOR(j, N + 1)
    {
        if (i == 0 || i == M + 1)
        {
            graph[i][j] = -1;
            continue;
        }
        else if (j == 0 || j == N + 1)
        {
            graph[i][j] = -1;
            continue;
        }
        else cin >> graph[i][j];
    }
    for (int i = 0; i <= 9; i++)for (int j = 0; j <= 9; j++)for (int k = 0;k <= 9;k++)
    {
        three t;
        t.num1 = i; t.num2 = j; t.num3 = k;
        for (int l = 1; l <= N; l++)
        {
            search(1, l, t);
            if (check)
            {
                cout << t.num1 << " " << t.num2 << " " << t.num3;
                return 0;
            }
            check = false;
            for (int x = 0; x < 102; x++) {
                for (int y = 0; y < 102; y++) {
                    visit[x][y] = 0;
                }
            }
        }
    }
    cout << "-1 -1 -1";
}