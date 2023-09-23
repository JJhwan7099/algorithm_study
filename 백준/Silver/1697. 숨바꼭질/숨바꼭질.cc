#include<iostream>
#include<queue>
using namespace std;
int N,K;
int visit[150000];
int main()
{
    cin >> N >> K;
    queue<pair<int,int>> q;
    q.push({N,0});
    visit[N] = 1;
    while(q.size()>0)
    {
        int a = q.front().first;
        int b = q.front().second;
        if(a==K)
        {
            cout << b;
            return 0;
        }
        if(a-1>=0)
        {
            if(visit[a-1]==0)
            {
                q.push({a-1,b+1});
                visit[a-1] = 1;
            }
        }
        if(a+1<=100000)
        {
            if(visit[a+1]==0)
            {
                q.push({a+1,b+1});
                visit[a+1] = 1;
            }
        }
        if(2*a<=100000)
        {
            if(visit[2*a]==0)
            {
                q.push({2*a,b+1});
                visit[2*a] = 1;
            }
        }
        q.pop();
    }
}