#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> m;
vector<vector<int>> result;
int answer = 0;
bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}
bool check(const vector<vector<string>>& relation)
{
    map<string, int> m1;
    m1.clear();
    for(auto&a: relation)
    {
        string s = "";
        for(auto&b: m)
        {
            if(b.second==1) 
            {
                s+=a[b.first];
                s+=',';
            }
        }
        if(s!="") m1[s]=1;
    }
    if(m1.size()==relation.size())
    {
        return true;
    }
    else return false;
}
void lcheck(vector<vector<int>>& result)
{
    for(int i=0; i<result.size(); i++)
    {
        for(int j=i+1; j<result.size(); j++)
        {
            if(result[i].size()>0&&result[i].size()<result[j].size())
            {
                bool bb = false;
                map<int,int> m1;
                for(auto&a: result[j]) m1[a]=1;
                for(auto&b: result[i]) if(m1[b]!=1) bb=true;
                
                if(!bb) result[j].clear();
            }
        }
    }
    return;
}
void btk(int n, const vector<vector<string>>& relation)
{
    if(check(relation))
    {
        vector<int> v;
        for(auto&a:m) if(a.second==1) v.push_back(a.first);
        result.push_back(v);
        return;
    }else{
        for(int i=n+1; i<relation[0].size(); i++)
        {
            m[i]=1;
            btk(i, relation);
            m[i]=0;
        }
    }
    return;
}
int solution(vector<vector<string>> relation) {
    m.clear();
    result.clear();
    answer=0;
    btk(-1, relation);
    sort(result.begin(),result.end(),cmp);
    lcheck(result);
    for(auto&a:result) if(a.size()>0) answer++;
    return answer;
}