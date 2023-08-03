#include <iostream>
using namespace std;
int DP[200001];
int DPresult[200001];
int NUM[200001];
int N;
void dp()
{
    DP[1] = NUM[1];
    for(int i = 2; i <= N; i++)
    {
        if(NUM[i]<DP[i-1]) DP[i] = NUM[i];
        else DP[i] = DP[i-1];
    }
    DPresult[1] = 0;
    for(int i = 2; i <= N; i++)
    {
        
        if(NUM[i]-DP[i-1] >= DPresult[i-1])
            DPresult[i] = NUM[i]-DP[i-1];
        else
            DPresult[i] = DPresult[i-1];
        // cout << NUM[i] << "**" << DP[i-1]<< " " << DPresult[i] << '\n';
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> NUM[i];
    }
    dp();
    for(int i = 1; i <= N; i++)
    {
        if(i==N)
        {
            cout << DPresult[i];
            return 0;
        }
        cout << DPresult[i] << " ";
    }
    return 0;
}