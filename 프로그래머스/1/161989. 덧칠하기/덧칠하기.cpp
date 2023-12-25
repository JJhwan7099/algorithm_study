#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    unordered_map<int,int> um;
    for(auto&a:section) um[a] = 1;
    for(int i=section[0]; i<=n; i++)
    {
        if(um[i]==1)
        {
            for(int j=i;j<i+m;j++)
            {
                um[j]=0;
            }
            answer++;
        }
    }
    return answer;
}