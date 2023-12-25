#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        int a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(target==a && cnt==numbers.size()) answer++;
        if(cnt>numbers.size()-1) continue;
        else{
            q.push({a+numbers[cnt],cnt+1});
            q.push({a-numbers[cnt],cnt+1});
        }
    }
    
    return answer;
}