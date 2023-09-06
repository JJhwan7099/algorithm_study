#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,s;
int arr[100001];
int visit[100001];
int cnt = 1;
void dfs(int n)
{
    int a = n;
    visit[a] = 1;
    if(a - arr[a] > 0 && visit[a-arr[a]] == 0)
    {
        cnt++;
        dfs(a - arr[a]);
    }
    if(a + arr[a] <= N && visit[a+arr[a]] == 0)
    {
        cnt++;
        dfs(a + arr[a]);
    }
}
int main()
{
    cin >> N;
    FOR(i,N) cin >> arr[i];
    cin >> s;
    dfs(s);
    cout << cnt;
}