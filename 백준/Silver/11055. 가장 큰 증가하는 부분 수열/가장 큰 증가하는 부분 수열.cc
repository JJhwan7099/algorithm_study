#include<iostream>
using namespace std;
int N;
int num[1001];
int DP[1001];
void dp()
{
    for(int i = 1; i <= N; i++)
    {
        DP[i] = num[i];
        for(int j = 1; j < i; j++)
        {
            if(num[j]<num[i] && DP[i] < DP[j]+num[i])
                DP[i] = DP[j] + num[i];
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> num[i];
    dp();
    int max = DP[1];
    for(int i = 2; i <= N; i++) if(max < DP[i]) max = DP[i];
    cout << max;
}