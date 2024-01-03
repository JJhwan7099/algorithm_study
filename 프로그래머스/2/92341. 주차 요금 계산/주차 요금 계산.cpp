#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,int> tottime;
    int night = 60*23+59;
    for(auto&s :records)
    {
        string ss = "";
        int time = ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
        int num = stoi(ss+s[6]+s[7]+s[8]+s[9]);
        if(s.length()==13)
        {
            tottime[num] += night - time;
        }
        else if(s.length()==14)
        {
            tottime[num] -= night - time;
        }
    }
    for(auto&a : tottime)
    {
        int t = a.second;
        if(t<=fees[0])
        {
            answer.push_back(fees[1]);
        }else{
            if((t-fees[0])%fees[2]==0)
            {
                answer.push_back(fees[1]+(t-fees[0])/fees[2]*fees[3]);
            }else{
                answer.push_back(fees[1]+((t-fees[0])/fees[2]+1)*fees[3]);
            }
        }
    }
    return answer;
}