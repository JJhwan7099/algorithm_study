#include<iostream>
using namespace std;

pair<int,int> p[1000];
long long DP[1000];
int main()
{
    int T; cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 1; i <= T; i++)
    {
        DP[i] = 1;

        for(int j = 1 ; j <= (p[i].first); j++)
        {
            DP[i] *= p[i].second--;
            DP[i] = DP[i] / j;
        }
    }
    for(int i = 1; i <= T; i++) cout << DP[i] << '\n';
}