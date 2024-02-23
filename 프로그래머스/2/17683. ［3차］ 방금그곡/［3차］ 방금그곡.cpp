#include <string>
#include <vector>
using namespace std;
string solution(string my, vector<string> musicinfos) {
    string answer = "(None)";
    int anst = -1;
    string MY = "";
    for(int i=0; i<my.length(); i++)
    {
        if(my[i+1]=='#')
        {
            MY+=my[i];
            i++;
        }else MY+=my[i]+32;
    }
    my = MY;
    for(auto&s: musicinfos)
    {
        int st = ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
        int et = ((s[6]-'0')*10+(s[7]-'0'))*60+(s[9]-'0')*10+(s[10]-'0');
        int mt = et-st;
        string name = "";
        string code = "";
        bool dot = false;
        for(int i=12; i<s.length(); i++)
        {
            if(s[i]==',') dot=true;
            else if(!dot){
                name+=s[i];
            }
            else if(dot){
                if(s[i+1]=='#')
                {
                    code+=s[i];
                    i++;
                }else code+=s[i]+32;
            }
        }
        if(mt<code.length())
        {
            string cc = "";
            for(int i=0; i<mt; i++)
            {
                cc+=code[i];
            }
            code = cc;
        }
        string ss="";
        for(int i=0; i<code.length(); i++)
        {
            for(int j=i; j<i+my.length()&&j<mt; j++)
            {
                ss+=code[j%code.length()];
            }
            if(ss==my&&((answer=="(None)"&&anst==-1)||anst<mt))
            {
                answer = name;
                anst = mt;
            }
            ss="";
        }
    }
    return answer;
}