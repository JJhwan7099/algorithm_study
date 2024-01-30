#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> m;
    for(int i=0; i<want.size(); i++) m[want[i]] = number[i];
    for(int i=0; i<discount.size()-9; i++)
    {
        map<string,int> m1;
        for(int j=i; j<i+10; j++)
        {
            m1[discount[j]]++;
        }
        if(m.size()==m1.size())
        {
            bool b = true;
            for(auto&a:m1) if(m.find(a.first)==m.end() || m[a.first]!=a.second) {b=false; break;}
            if(b) answer++;
        }
    }
    return answer;
}