#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int DP[501][501];
    DP[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++)for(int j=0;j<triangle[i].size();j++)
    {
        DP[i][j] = max(triangle[i][j]+DP[i-1][j-1],triangle[i][j]+DP[i-1][j]);
    }
    for(int i=0; i<triangle[triangle.size()-1].size(); i++) answer = max(answer,DP[triangle.size()-1][i]);
    return answer;
}