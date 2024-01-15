#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<vector<pair<int,vector<int>>>> v;
map<string,int> M;
void makec(const vector<vector<int>>& dice, vector<pair<int,vector<int>>> vv)
{
    map<int,int> m;
    if(vv.size()==n/2)
    {
        vector<int> abc;
        for(auto&a:vv) abc.push_back(a.first);
        sort(abc.begin(),abc.end());
        string s = "";
        for(auto&a:abc) s+=to_string(a);
        if(M[s]!=1)
        {
            v.push_back(vv);
            M[s] = 1;
        }
        return;
    }else{
        for(auto&a:vv) m[a.first] = 1;
        for(int i=1; i<=dice.size(); i++)
        {
            if(m[i]!=1)
            {
                vv.push_back({i,dice[i-1]});
                makec(dice, vv);
                vv.pop_back();
            }
        }
    }
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    n = dice.size();
    int max = -1;
    vector<pair<int,vector<int>>> v1;
    makec(dice, v1);
    for(auto&a:v){for(auto&b:a) cout << b.first << " "; cout << endl;}
    for(auto&a:v)
    {
        map<int,int> m;
        vector<int> A;
        vector<int> B;
        for(int i=0; i<a.size(); i++)
        {
            m[a[i].first]=1;
            A.push_back(a[i].first);
        }
        for(int i=0; i<dice.size(); i++)
        {
            if(m[i+1]!=1) B.push_back(i+1);
        }
        
        for(auto&b:A)cout << b << " ";
        cout << " || ";
        for(auto&b:B)cout << b << " ";
        cout << endl;
        
        multimap<int,int> asum;
        for(auto&c:dice[A[0]-1]) asum.insert({c,1});
        for(int z=1; z<n/2; z++)
        {
            vector<int>v;
            for(auto&b:asum)
            {
                if(b.second==z)
                {
                    v.push_back(b.first);
                }
            }
            for(auto&b:v)
            {
                for(auto&c:dice[A[z]-1]) asum.insert({b+c,z+1});
            }
        }
        multimap<int,int> bsum;
        for(auto&c:dice[B[0]-1]) bsum.insert({c,1});
        for(int z=1; z<n/2; z++)
        {
            vector<int>v;
            for(auto&b:bsum)
            {
                if(b.second==z)
                {
                    v.push_back(b.first);
                }
            }
            for(auto&b:v)
            {
                for(auto&c:dice[B[z]-1]) bsum.insert({b+c,z+1});
            }
        }
        map<int,int> Am;
        map<int,int> Bm;
        for(auto&b:asum) if(b.second==n/2) Am[b.first]++;
        for(auto&b:bsum) if(b.second==n/2) Bm[b.first]++;
        int cnt=0;
        for(auto&b:Am)
        {
            for(auto&c:Bm) if(b.first>c.first) cnt+=c.second*b.second;
        }
        if(max==-1||max<cnt) 
        {
            max = cnt;
            answer = A;
        }
    }
    return answer;
}