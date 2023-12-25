#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char,int> m;
    for(int i=0; i<survey.size(); i++)
    {
        if(choices[i]-4<0)
        {
            m[survey[i][0]]+=abs(choices[i]-4);
        }
        else if(choices[i]-4>0)
        {
            m[survey[i][1]]+=abs(choices[i]-4);
        }
    }
    if(m['R']<m['T']) answer+='T';
    else answer+='R';
    if(m['C']<m['F']) answer+='F';
    else answer+='C';
    if(m['J']<m['M']) answer+='M';
    else answer+='J';
    if(m['A']<m['N']) answer+='N';
    else answer+='A';
    return answer;
}