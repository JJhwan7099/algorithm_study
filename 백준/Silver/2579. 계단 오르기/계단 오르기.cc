#include<iostream>
using namespace std;
#define endl '\n'
int staircnt[301];
int DP[301];
int max(int a, int b) 
{
    if(a>b) return a;
    else return b;
}
void calDP(int s)
{
    DP[1] = staircnt[1];
    DP[2] = staircnt[1] + staircnt[2];
    DP[3] = max(staircnt[1]+staircnt[3], staircnt[2]+staircnt[3]);
    for(int i = 4; i <= s; i++)
    {
        DP[i] = max(DP[i-2] + staircnt[i], DP[i-3] + staircnt[i-1] + staircnt[i]);
    }
    cout << DP[s];
}
int main()
{
    int a; cin >> a;
    for(int i = 1; i < a+1; i++)
    {
        cin >> staircnt[i];
    }
    calDP(a);
    return 0;
}