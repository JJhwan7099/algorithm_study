#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    map<int,int> m1;
    queue<pair<pair<int,int>,pair<int,map<int,int>>>> q;
    q.push({{k,0},{0,m1}});
    while(!q.empty())
    {
        int pirodo = q.front().first.first;
        int index = q.front().first.second;
        int cnt = q.front().second.first;
        map<int,int> m = q.front().second.second;
        q.pop();
        answer = max(answer,cnt);
        for(int i=0; i<dungeons.size(); i++)
        {
            if(m[i]!=1)
            {
                if(pirodo>=dungeons[i][0])
                {
                    m[i]=1;
                    q.push({{pirodo-dungeons[i][1],index+1},{cnt+1,m}});
                    m[i]=0;
                }else{
                    m[i]=1;
                    q.push({{pirodo,index+1},{cnt,m}});
                    m[i]=0;
                }
            }
        }
    }
    return answer;
}