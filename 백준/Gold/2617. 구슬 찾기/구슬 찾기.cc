#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N, M;
vector<int> graph1[101];
vector<int> graph2[101];
bool visit[101];
int wcnt = 0;
int arr1[101];
int arr2[101];
void count(int n, int a)
{
    if(a==1)
    {
        visit[n] = 1;
        for(int i=0; i<graph1[n].size(); i++)
        {
            if(visit[graph1[n][i]] != 1)
            {
                wcnt++;
                count(graph1[n][i],1);
            }
        }
    }else{
        visit[n] = 1;
        for(int i=0; i<graph2[n].size(); i++)
        {
            if(visit[graph2[n][i]] != 1)
            {
                wcnt++;
                count(graph2[n][i],2);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int ans = 0;
    FOR(i,M)
    {
        int a,b; cin >> a >> b;
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }
    FOR(i,N)
    {
        fill(&visit[0],&visit[100],0);
        wcnt = 0;
        count(i,1);
        arr1[i] = wcnt;
        if(arr1[i] > N/2) ans++;
    }
    FOR(i,N)
    {
        fill(&visit[0],&visit[100],0);
        wcnt = 0;
        count(i,2);
        arr2[i] = wcnt;
        if(arr2[i] > N/2) ans++;
    }
    cout << ans;
}