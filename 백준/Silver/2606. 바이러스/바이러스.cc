#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int N, K; 
int count = 0;
int v1[101][101];
int check[101][101];
int result[101];
void search(int n)
{
    for(int i = 1; i <= N; i++)
    {
        if(n == i) continue;
        if(check[n][i] == 1 && check[i][n] == 1) continue;
        if(v1[n][i] == 1)
        {
            check[n][i] = 1; check[i][n] = 1;
            result[i] = 1;
            search(i);
        }
    }
    for(int i = 1; i <= N; i++)
    {
        if(n == i) continue;
        if(check[n][i] == 1 && check[i][n] == 1) continue;
        if(v1[i][n] == 1)
        {
            check[n][i] = 1; check[i][n] = 1;
            result[i] = 1;
            search(i);
        }
    }
    return;
}
int main()
{
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a,b; cin >> a >> b;
        v1[a][b] = 1;
    }
    search(1);
    for(int i = 2; i <= N; i++)
    {
        if(result[i] == 1) count++;
    }
    cout << count;
    return 0;
}