#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> win[101];
vector<int> lose[101];
int arr[101];
int wcnt = -1;
int lcnt = -1;
int wvisit[101];
int lvisit[101];
void wdfs(int n)
{
    wcnt++;
    wvisit[n]=1;
    for(int i=0; i<win[n].size(); i++)
    {
        if(wvisit[win[n][i]]!=1) wdfs(win[n][i]);
    }
}
void ldfs(int n)
{
    lcnt++;
    lvisit[n]=1;
    for(int i=0; i<lose[n].size(); i++)
    {
        if(lvisit[lose[n][i]]!=1) ldfs(lose[n][i]);
    }
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto&a:results)
    {
        lose[a[1]].push_back(a[0]);
        win[a[0]].push_back(a[1]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) {wvisit[j]=0; lvisit[j]=0;}
        wcnt=-1;
        lcnt=-1;
        wdfs(i);
        ldfs(i);
        if(wcnt+lcnt==n-1) answer++;
    }
    return answer;
}