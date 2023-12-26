#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
struct Hand{
    int x,y;
};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int,pair<int,int>> m;
    Hand left; left.x = 4; left.y = 1;
    Hand right; right.x = 4; right.y = 3;
    
    int c = 1;
    for(int i=1;i<=3;i++)for(int j=1;j<=3; j++)
    {
        m[c++] = {i,j};
    }
    m[0] = {4,2};
    for(auto&a: numbers)
    {
        int x = m[a].first;
        int y = m[a].second;
        if(y==1) 
        {
            answer+='L';
            left.x = x; left.y = y;
        }
        else if(y==3) 
        {
            answer+='R';
            right.x = x; right.y = y;
        }
        else if(y==2)
        {
            int leftd = abs(left.x-x)+abs(left.y-y);
            int rightd = abs(right.x-x)+abs(right.y-y);
            if(leftd==rightd)
            {
                if(hand=="right")
                {
                    answer+='R';
                    right.x = x; right.y = y;
                }else{
                    answer+='L';
                    left.x = x; left.y = y;
                }
            }else if(leftd>rightd)
            {
                answer+='R';
                right.x = x; right.y = y;
            }else{
                answer+='L';
                left.x = x; left.y = y;
            }
        }
    }
    return answer;
}