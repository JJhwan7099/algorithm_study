#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, N) for(int (i) = 1; (i) <= (N); (i)++)
int N;
int arr[1000001];
int arr2[1000001];
vector<int> btn;
int change(int n)
{
    if(n==0) return 1;
    else return 0;
}
void search()
{
    int count = 0;
    FOR(i,N)
    {
        if(arr[i]!=arr2[i])
        {
            if(i==N-1)
            {
                arr2[i] = change(arr2[i]); arr2[i+1] = change(arr2[i+1]);
            }
            else if(i==N)
            {
                arr2[i] = change(arr2[i]);
            }
            else
            {
                arr2[i] = change(arr2[i]);
                arr2[i+1] = change(arr2[i+1]);
                arr2[i+2] = change(arr2[i+2]);
            }
            count++;
            // FOR(j,N) cout << arr2[j] << " ";
            // cout <<"<- " << i << endl;
        }
    }
    cout << count;
}
int main()
{
    cin >> N;
    FOR(i,N) 
    {
        cin >> arr[i];
        if(arr[i]==1)
        {
            btn.push_back(i);
        }
    }
    search();
}