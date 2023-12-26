#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    string answer = "";
    map<string,string> m;
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
    string ss="";
    for(int i=0; i<s.length(); i++)
    {
        if(!isdigit(s[i])) ss += s[i];
        if(m.find(ss)!=m.end())
        {
            answer+=m[ss];
            ss="";
        }
        if(isdigit(s[i])) answer += s[i];
    }
    return stoi(answer);
}