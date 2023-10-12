#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int X,Y;
int ground[501][501];
int result = 0;
int main()
{
    cin >> X >> Y;
    FOR(i,Y)
    {
        int h; cin >> h;
        for(int j = X; j > X-h; j--)
        {
            ground[j][i] = 1;
        }
    }
    FOR(i,X)FOR(j,Y)
    {
        if(ground[i][j]==0)
        {
            if(j==1)
            {
                while(j<=Y)
                {
                    j++;
                    if(ground[i][j]==1)
                    {
                        break;
                    }
                }
                continue;
            }
            int s = j;
            int e = 0;
            while(j<=Y)
            {
                j++;
                if(ground[i][j]==1) 
                {
                    e = j;
                    break;
                }
            }
            if((s!=e && e!=0) || i == X)
            {
                for(int k = s; k<e; k++)
                {
                    ground[i][k] = 2;
                }
            }
        }
    }
    FOR(i,X)FOR(j,Y)
    {
        if(ground[i][j]==2) result++;
    }
    cout << result;
}