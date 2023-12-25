#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    string num = "";
    for(int i=0; i<dartResult.length(); i++)
    {
        if(isdigit(dartResult[i]))
        {
            num+=dartResult[i];
        }else{
            if(dartResult[i]=='*')
            {
                if(v.size()==1) v[0]*=2;
                else
                {
                    v[v.size()-1]*=2; v[v.size()-2]*=2;
                }
            }
            else if(dartResult[i]=='#')
            {
                v[v.size()-1]*=-1;
            }
            else if(dartResult[i]=='S')
            {
                v.push_back(stoi(num));
                num = "";
            }
            else if(dartResult[i]=='D')
            {
                v.push_back(stoi(num)*stoi(num));
                num = "";
            }
            else if(dartResult[i]=='T')
            {
                v.push_back(stoi(num)*stoi(num)*stoi(num));
                num = "";
            }
        }
    }
    for(auto&a:v) answer+=a;
    return answer;
}