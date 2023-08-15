#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N;
vector<int> U;
vector<int> two;
vector<int> ans;
bool compare(int a, int b)
{
    return a > b;
}
int bsearch(int size, int n)
{
    int s = 0;
    int e = size-1;
    int mid;
    while(s <= e)
    {
        mid = (e+s)/2;
        if(two[mid]==n)
        {
            return 1;
        }
        else if(two[mid] > n) e = mid - 1;
        else if(two[mid] < n) s = mid + 1;
    }
    return 0;
}
int main()
{
    cin >> N;
    FOR(i,N) 
    {
        int a; cin >> a;
        U.push_back(a);
    }
    sort(U.begin(),U.end());
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            two.push_back(U[i]+U[j]);
        }
    }
    sort(two.begin(),two.end());
    for(int j = N-1; j >= 0; j--)
    {
        for(int i = 0; i < N; i++)
        {
            if(bsearch(two.size(), U[j] - U[i]))
            {
                cout << U[j];
                return 0;
            }
        }
    }
}