#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s[31];
    stack<int> bucket;
    for(int i=board.size();i>0; i--)for(int j=1; j<=board[i-1].size();j++)
    {
        // cout << board[2][2] << endl;
        if(board[i-1][j-1]>0) s[j].push(board[i-1][j-1]);
    }
    for(auto&a:moves)
    {
        if(!s[a].empty())
        {
            int aa = s[a].top();
            s[a].pop();
            if(!bucket.empty()&&aa==bucket.top())
            {
                bucket.pop();
                answer+=2;
            }else{
                bucket.push(aa);
            }
        }
    }
    return answer;
}