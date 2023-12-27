#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char,int> um[100];
    for(int i=0; i<keymap.size(); i++)
    {
        for(int j=0; j<keymap[i].size(); j++) if(um[i][keymap[i][j]]==0) um[i][keymap[i][j]] = j+1;
    }
    for(auto&t:targets)
    {
        int c = 0;
        for(int i=0; i<t.length(); i++)
        {
            int min = -1;
            for(int j = 0;j<keymap.size();j++)
            {
                if(um[j][t[i]]!=0 && (min==-1||min > um[j][t[i]])) min = um[j][t[i]];
            }
            if(min==-1){
                c = -1;
                break;
            }else c += min;
        }
        if(c>0)answer.push_back(c);
        else answer.push_back(-1);
    }
    return answer;
}