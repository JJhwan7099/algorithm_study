#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> um;
map<string, int> result;
int answer = 0;
bool check(string a, string b)
{
    if(a.length()!=b.length()) return false;
    for(int i=0; i<a.length(); i++)
    {
        if(b[i]=='*') continue;
        else if(a[i]!=b[i]) return false;
    }
    return true;
}
bool joongbok(const vector<string>& banned_id)
{
    string s = "";
    int cnt=0;
    for(auto&a: um) if(a.second==1) {cnt++; s+=a.first; s+=",";}
    if(result[s]!=1&&cnt==banned_id.size()) {
        result[s]=1;
        return true;
    }
    else return false;
}
void btk(int x, const vector<string>& user_id, const vector<string>& banned_id)
{
    bool b=false;
    for(int i=x+1; i<banned_id.size(); i++)
    {
        for(int j=0; j<user_id.size(); j++)
        {
            if(um[user_id[j]]!=1 && check(user_id[j], banned_id[i]))
            {
                b=true;
                um[user_id[j]]=1;
                btk(i,user_id,banned_id);
                um[user_id[j]]=0;
            }
        }
    }
    if(!b && joongbok(banned_id)) answer++;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    for(auto&a: user_id) um[a]=0;
    btk(-1,user_id,banned_id);
    return answer;
}