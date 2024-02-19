#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<pair<pair<char,char>,pair<char,int>>> rule;
map<char,int> m;
int cnt;
int answer;
string v;
bool check()
{
    for(auto&a:rule)
    {
        if(m[a.first.first]!=0&&m[a.first.second]!=0)
        {
            if(a.second.first=='=')
            {
                if(abs(m[a.first.first]-m[a.first.second])-1!=a.second.second) return false;
            }
            if(a.second.first=='<')
            {
                if(abs(m[a.first.first]-m[a.first.second])-1>=a.second.second) return false;
            }
            if(a.second.first=='>')
            {
                if(abs(m[a.first.first]-m[a.first.second])-1<=a.second.second) return false;
            }
        }
    }
    return true;
}
void make_name(string s)
{
    if(check())
    {
        if(s.length()==8)
        {
            answer++;
            return;
        }
        for(int i=0; i<8; i++)
        {
            if(m[v[i]]==0)
            {
                m[v[i]]=cnt;
                cnt++;
                make_name(s+v[i]);
                cnt--;
                m[v[i]]=0;
            }
        }
    }
}
int solution(int n, vector<string> data) {
    cnt=1;
    answer=0;
    v = "ACFJMNRT";
    rule.clear();
    m.clear();
    for(auto&a: data) rule.push_back({{a[0],a[2]},{a[3],a[4]-'0'}});
    string s = "";
    make_name(s);
    return answer;
}