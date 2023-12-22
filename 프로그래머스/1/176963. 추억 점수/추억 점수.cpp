#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> m;
    for(int i=0; i<name.size(); i++)
    {
        m[name[i]] = yearning[i];
    }
    for(auto&a:photo)
    {
        int score = 0;
        for(auto&b:a) score+=m[b];
        answer.push_back(score);
    }
    return answer;
}