#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> result;
    vector<string> answer;
    unordered_map<string,string> m;
    for(auto&s :record)
    {
        stringstream ss(s);
        string cmd, id, name;
        ss >> cmd >> id >> name;
        if(cmd=="Enter")
        {
            m[id]=name; 
            result.push_back(id+" "+"님이 들어왔습니다.");
        }
        else if(cmd=="Leave")
        {
            result.push_back(id+" "+"님이 나갔습니다.");
        }
        else if(cmd=="Change")
        {
            m[id]=name;
        }
    }
    for(auto&s: result)
    {
        stringstream ss(s);
        string id, content1, content2;
        ss >> id >> content1 >> content2;
        answer.push_back(m[id]+content1+" "+content2);
    }
    return answer;
}