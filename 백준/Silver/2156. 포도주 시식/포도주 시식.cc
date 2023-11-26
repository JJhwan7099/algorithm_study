#include<iostream>
using namespace std;
int n;
int num[10001];
int DP[10001][3];
void dp()
{
    DP[1][0] = num[1]; 
    DP[2][0] = num[2]; DP[2][1]=num[1]+num[2];
    for(int i=3;i<=n;i++)
    {
        
        DP[i][0]= max(max(DP[i-2][0],DP[i-2][1]),DP[i-1][2]) + num[i];
        DP[i][1]= DP[i-1][0] + num[i];
        DP[i][2] = max(max(DP[i-1][0],DP[i-1][1]),DP[i-1][2]);
    }
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> num[i];
    }
    dp();
    int mmax = DP[1][1];
    for(int i=1; i<=n; i++) for(int j=0; j<2; j++) if(DP[i][j]>mmax) mmax=DP[i][j];
    cout << mmax;
}