#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int&a, int&b)
{
    return a > b;
}
int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    int cnt = score.size()-1;
    while(true)
    {
        if(cnt>=m-1)
        {
            for(int i=0; i<m; i++)
            {
                if(i==m-1) answer += score[cnt]*m;
                cnt--;
            }
        }else break;
    }
    return answer;
}