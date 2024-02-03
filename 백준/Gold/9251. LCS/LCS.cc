#include<iostream>
using namespace std;
string s1,s2;
int DP[1001][1001];
void dp()
{
    for(int i=1; i<=s1.length(); i++)for(int j=1;j<=s2.length();j++)
    {
        if(s1[i-1]==s2[j-1]) DP[i][j] = DP[i-1][j-1]+1;
        else DP[i][j]=max(DP[i-1][j],DP[i][j-1]); 
    }
}
int main()
{
    cin >> s1 >> s2;
    dp();
    cout << DP[s1.length()][s2.length()];
}