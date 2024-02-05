#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int num[15][15];
void start()
{
    FOR(i,14)
    {
        FOR(j,14)
        {
            int sum = 0;
            FOR(k,j)
            {
                sum += num[i-1][k];
            }
            num[i][j]=sum;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i,14) num[0][i] = i;
    start();
    cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        cout << num[a][b] << '\n';
    }
    return 0;
}