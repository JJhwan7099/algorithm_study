#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<pair<pair<char,char>,pair<char,int>>> rule;
map<char,int> m;
int cnt;
int answer;
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
void make_name(const vector<char>& v, string s)
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
                make_name(v,s+v[i]);
                cnt--;
                m[v[i]]=0;
            }
        }
    }
}
int solution(int n, vector<string> data) {
    cnt=1;
    answer=0;
    rule.clear();
    m.clear();
    for(auto&a: data) rule.push_back({{a[0],a[2]},{a[3],a[4]-'0'}});
    vector<char> person(8);
    person[0]='A'; person[1]='C'; person[2]='F'; person[3]='J';
    person[4]='M'; person[5]='N'; person[6]='R'; person[7]='T';
    for(auto&a:person) m[a]=0;
    string s = "";
    make_name(person, s);
    int a = answer;
    return a;
}