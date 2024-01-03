#include <string>
#include <vector>
#include <queue>
using namespace std;
int visit[1000000];
int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> q;
    q.push({x,0});
    visit[x]=1;
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visit[a]=1;
        if(a>y) continue;
        else if(a==y)
        {
            return b;
        }else{
            if(a+n<=1000000 && visit[a+n]!=1)q.push({a+n,b+1});
            if(a*2<=1000000 && visit[a*2]!=1)q.push({a*2,b+1});
            if(a*3<=1000000 && visit[a*3]!=1)q.push({a*3,b+1});
        }
    }
    return answer;
}