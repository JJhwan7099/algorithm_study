#include <iostream>
using namespace std;
int DP[1000000];
int max(int a, int b, int c) 
{   
    if(a == 0) a = 1000000;
    if(b == 0) b = 1000000;
    if(c == 0) c = 1000000;
    if(a>b) 
    {
        if(c>b)
            return b; 
        else
            return c;
    }else 
        if(a>c)
            return c;
        else
            return a;
    
}
void dp(int n)
{
    DP[1] = 0;
    DP[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        int a = 0;
        int b = 0;
        int c = 0;

        if(i%3 == 0) a = DP[i/3]+1;
        if(i%2 == 0) b = DP[i/2]+1;
        c = DP[i-1]+1;
        DP[i] = max(a,b,c);
    }
    cout << DP[n];
}
int main()
{
    int N; cin >> N;
    dp(N);
    return 0;
}