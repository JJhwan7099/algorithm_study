#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int>m;
vector<int> solution(string msg) {
    vector<int> answer;
    for(int i=1; i<27; i++)
    {
        char c = 'A'+i-1;
        string s = "";
        s+=c;
        m[s] = i; 
    }
    int cnt = 27;
    string s = "";
    for(int i=0; i<msg.length(); i++)
    {
        if(m.find(s+msg[i])!=m.end()) s+=msg[i];
        else{
            answer.push_back(m[s]);
            s+=msg[i];
            m[s]=cnt++;
            s=msg[i];
        }
        if(i==msg.length()-1){
            answer.push_back(m[s]);
            continue;
        }
    }
    return answer;
}