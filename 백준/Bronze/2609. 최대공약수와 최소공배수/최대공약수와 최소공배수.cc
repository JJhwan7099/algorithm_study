#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int n1, n2;
void choidae(int N1, int N2)
{
    if(N1<=N2)
    {
        int n = N1;
        while(n>0)
        {
            if(N1%n==0 && N2%n==0)
            {
                cout << n << '\n';
                return;
            }
            n--;
        }
    }else{
        int n = N2;
        while(n>0)
        {
            if(N1%n==0 && N2%n==0)
            {
                cout << n << '\n';
                return;
            }
            n--;
        }
    }
}
void choiso(int N1, int N2)
{
    if(N1>=N2)
    {
        int n = N1;
        while(n<=N1*N2)
        {
            if(n%N1==0 && n%N2==0)
            {
                cout << n << '\n';
                return;
            }
            n++;
        }
    }else{
        int n = N2;
        while(n<=N1*N2)
        {
            if(n%N1==0 && n%N2==0)
            {
                cout << n << '\n';
                return;
            }
            n++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n1 >> n2;
    choidae(n1,n2);
    choiso(n1,n2);
    return 0;
}