#include<iostream>
using namespace std;
int N;
int arr[1001];
int DP[1001][3];
int ans = -1;
void dp()
{
    DP[1][0] = 0;
    DP[1][2] = 1;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(DP[i][1]==1 && DP[j][1]==3 && DP[j][2]==1)
            {
                if(DP[i][0]==0) DP[i][0] = DP[j][0]+((i-j)*(i-j));
                else DP[i][0] = min(DP[i][0],DP[j][0]+((i-j)*(i-j)));
                DP[i][2] = 1;
            }
            if(DP[i][1]==2 && DP[j][1]==1 && DP[j][2]==1)
            {
                if(DP[i][0]==0) DP[i][0] = DP[j][0]+((i-j)*(i-j));
                else DP[i][0] = min(DP[i][0],DP[j][0]+((i-j)*(i-j)));
                DP[i][2] = 1;
            }
            if(DP[i][1]==3 && DP[j][1]==2 && DP[j][2]==1)
            {
                if(DP[i][0]==0) DP[i][0] = DP[j][0]+((i-j)*(i-j));
                else DP[i][0] = min(DP[i][0],DP[j][0]+((i-j)*(i-j)));
                DP[i][2] = 1;
            }
        }
    }
}
int main()
{
    cin >> N;
    string s; cin >> s;
    for(int j=0; j<s.length(); j++)
    {
        char a = s[j];
        if(a=='B') DP[j+1][1] = 1;
        else if(a=='O') DP[j+1][1] = 2;
        else DP[j+1][1] = 3; 
    }
    dp();
    if(DP[N][0]>0) ans = DP[N][0];
    cout << ans;
}