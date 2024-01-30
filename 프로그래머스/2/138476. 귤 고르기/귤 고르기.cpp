#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b) {return a.first>b.first;}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    vector<pair<int,int>> v;
    for(auto&a:tangerine) m[a]++;
    for(auto&a:m) v.push_back({a.second,a.first});
    sort(v.begin(),v.end(),cmp);
    for(auto&a:v)
    {
        k-=a.first;
        answer++;
        if(k<=0) break;
    }
    return answer;
}