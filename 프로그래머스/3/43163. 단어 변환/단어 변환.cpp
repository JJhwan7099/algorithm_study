#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int check(string a, string b)
{
    int cnt = 0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]!=b[i]) cnt++;
    }
    return cnt;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    unordered_map<string,int> m;
    queue<pair<string,int>> q;
    q.push({begin,0});
    while(!q.empty())
    {
        string a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        m[a] = 1;
        if(a==target) return cnt;
        for(auto&b:words)
        {
            if(m[b]==1) continue;
            else if(check(a,b)==1)
            {
                q.push({b,cnt+1});
            }
        }
    }
    return answer;
}