#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<pair<int,int>> v;
    vector<pair<int,int>> v1;
    for(int i=0;i<wallpaper.size();i++)
    {
        for(int j=0;j<wallpaper[i].length();j++)
        {
            if(wallpaper[i][j]=='#') v.push_back({i,j});
        }
    }
    int u=-1;
    int l=-1;
    int r=-1;
    int d=-1;
    for(auto&a:v)
    {
        if(u==-1||u>a.first) u=a.first;
        if(l==-1||l>a.second) l=a.second;
        if(r==-1||r<a.second) r=a.second;
        if(d==-1||d<a.first) d=a.first;
    }
    return {u,l,d+1,r+1};
}