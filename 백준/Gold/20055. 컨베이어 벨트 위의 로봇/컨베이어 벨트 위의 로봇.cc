#include <iostream>
#include <queue>
#include <deque>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,K;
int arr[201];
deque<pair<int,int>> u;
deque<pair<int,int>> d;
int cnt = 0; // 0인 곳의 개수
int result = 0;
void doing()
{
    if(u[0].second == 1) u[0].second--; // 마지막 칸에 로봇 있으면 없애줌
    u.push_back(d.front());
    d.push_back(u.front());
    u.pop_front(); d.pop_front();
    for(int i=0; i<N; i++)//로봇이 움직임
    {
        if(u[i].second == 1)
        {
            if(i==0)
            {
                u[i].second = 0;
            }else if(u[i-1].second == 0 && u[i-1].first > 0){
                u[i].second = 0;
                u[i-1].second = 1;
                u[i-1].first--;
            }
        }
    }
    if(u[N-1].first != 0) // 첫칸에 로봇 올림
    {
        u[N-1].second = 1;
        u[N-1].first--;
    }
}
int main()
{
    cin >> N >> K;
    FOR(i,2*N)
    {
        cin >> arr[i];
    }
    for(int i=0; i<2*N; i++)
    {
        if(i < N) d.push_back({arr[2*N-i],0});
        else u.push_back({arr[2*N-i],0});
    }
    while(true)
    {
        doing();
        int a = 0;
        for(int i = 0; i < N; i++)
        {
            if(u[i].first == 0) a++;
            if(d[i].first == 0) a++;
        }
        cnt = a;
        result++;
        if(cnt >= K) break;
    }
    cout << result;
}