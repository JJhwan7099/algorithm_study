#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> m;
    map<int,int,greater<>> result;
    string ss="";
    for(int i=1; i<s.length()-1; i++)
    {
        if(isdigit(s[i])) ss+=s[i];
        else if((s[i]==','&&ss!="")||s[i]=='}')
        {
            m[stoi(ss)]++;
            ss="";
        }
    }
    for(auto&a:m) result[a.second] = a.first;
    for(auto&a:result) answer.push_back(a.second);
    return answer;
}