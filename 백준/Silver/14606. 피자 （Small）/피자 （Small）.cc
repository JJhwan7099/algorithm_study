#include <iostream>
using namespace std;
int N;
int DP[1000];
void dp()
{
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 3;
    for(int i = 4; i <= N; i++)
    {
        if(DP[i] < (i*(i-(i/2))) + DP[i/2] + DP[i-(i/2)]) 
            DP[i] = ((i/2)*(i-(i/2)))+DP[i/2]+DP[i-(i/2)];
    }
}
int main()
{
    cin >> N;
    dp();
    cout << DP[N];
}