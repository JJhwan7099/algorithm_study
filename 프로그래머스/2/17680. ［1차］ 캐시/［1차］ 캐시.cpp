#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
bool check(queue<string>& q, string s, int cacheSize)
{
    int size=q.size();
    bool b = false;
    for(int i=0; i<size; i++)
    {
        if(q.front()==s){
            b=true;
            q.pop();
        }else{
            q.push(q.front());
            if(!q.empty()) q.pop();
        }
    }
    if(b&&q.size()<cacheSize) q.push(s);
    else{
        if(q.size()<cacheSize) q.push(s);
        else{
            if(!q.empty()) q.pop();
            if(q.size()<cacheSize) q.push(s);
        }
    }
    return b;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string>q;
    for(int i=0; i<cities.size(); i++)
    {
        string s = "";
        for(int j=0; j<cities[i].size(); j++)
        {
            if(isupper(cities[i][j])) s+=cities[i][j]+32;
            else s+=cities[i][j];
        }
        if(check(q,s,cacheSize)) answer++;
        else answer+=5;
    }
    return answer;
}