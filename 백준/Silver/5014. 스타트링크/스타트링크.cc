#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int F,S,G,U,D;
int arr[1000001]; // 최단 거리 저장
int visit[1000001];
void search(int S)
{
    queue<int> q1;
    q1.push(S);
    while(!q1.empty())
    {
        int a = q1.front(); 
        visit[a] = 1;
        for(int i=0; i<q1.size(); i++)
        {
            // if((arr[a+U] > arr[a] + 1|| arr[a+U]==0))
            // {
                
            //     if(visit[a+U]!=1 && a+U <= F)
            //     {
            //         arr[a+U] = arr[a] + 1;
            //         q1.push(a+U);
            //     }
            // }
            // if((arr[a-D] > arr[a] + 1|| arr[a-D]==0))
            // {
                
            //     if(visit[a-D]!=1 && a-D >= 1)
            //     {
            //         arr[a-D] = arr[a] + 1;
            //         q1.push(a+U);
            //     }
            // }
            if( a+U<=F && visit[a+U]!= 1)
            {
                if(arr[a+U] < arr[a] + 1 || arr[a+U] == 0)
                {
                    arr[a+U] = arr[a] + 1;
                }
                visit[a+U] = 1;
                q1.push(a+U);
            }
            if( a-D>=1 && visit[a-D]!= 1)
            {
                if(arr[a-D] < arr[a] + 1 || arr[a-D] == 0)
                {
                    arr[a-D] = arr[a] + 1;
                }
                visit[a-D] = 1;
                q1.push(a-D);
            }
        }
        q1.pop();
    }
}
int main()
{
    cin >> F >> S >> G >> U >> D;
    arr[S] = 0;
    search(S);
    if(G == S)
    {
        cout << "0";
        return 0;
    }
    if(arr[G]==0)
    {
        cout << "use the stairs";
        return 0;
    }
    cout << arr[G];
}