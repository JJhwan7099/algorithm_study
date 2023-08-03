#include <iostream>
using namespace std;
int R,C,W;
int paskal[31][31];
int DP[31];
void PASKAL()
{
    paskal[1][1] = 1;
    paskal[2][1] = 1; paskal[2][2] = 1;
    paskal[3][1] = 1; paskal[3][2] = 2; paskal[3][3] = 1;
    for(int i = 1; i <= 30; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j==1)
                paskal[i][j] = 1;
            else if(j == i)
                paskal[i][j] = 1;
            else
                paskal[i][j] = paskal[i-1][j-1] + paskal[i-1][j];
        }
    }
}

int main()
{
    cin >> R >> C >> W;
    PASKAL();
    int answer = 0;
    for(int i = R; i < R+W; i++)
    {
        for(int j = 0; j < i-R+1; j++)
        {
            answer += paskal[i][j+C];
        }
    }
    cout << answer;
}