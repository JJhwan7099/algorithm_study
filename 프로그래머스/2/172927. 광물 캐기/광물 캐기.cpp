#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<string> a, vector<string> b)
{
    // if(a.size()!=b.size()) return a.size()>b.size();
    int ad=0; int ai=0; int as=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]=="diamond") ad++;
        else if(a[i]=="iron") ai++;
        else if(a[i]=="stone") as++;
    }
    int bd=0; int bi=0; int bs=0;
    for(int i=0; i<b.size(); i++)
    {
        if(b[i]=="diamond") bd++;
        else if(b[i]=="iron") bi++;
        else if(b[i]=="stone") bs++;
    }
    if(ad!=bd) return ad>bd;
    else if(ai!=bi) return ai>bi;
    else return as>bs;
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int diac = picks[0]; int ironc = picks[1]; int stonec = picks[2];
    vector<vector<string>> V;
    if(minerals.size()%5==0)
    {
        vector<vector<string>> v;
        int a = 0;
        for(int i=0; i<minerals.size()/5; i++)
        {
            vector<string> vv;
            for(int j=0; j<5; j++)
            {
                if(a>=(diac+ironc+stonec)*5)
                {
                    i = minerals.size()/5;
                    continue;
                }
                vv.push_back(minerals[a]);
                a++;
            }
            v.push_back(vv);
        }
        V = v;
    }else{
        vector<vector<string>> v;
        int a = 0;
        for(int i=0; i<minerals.size()/5; i++)
        {
            vector<string> vv;
            for(int j=0; j<5; j++)
            {
                if(a>=(diac+ironc+stonec)*5)
                {
                    i = minerals.size()/5;
                    continue;
                }
                vv.push_back(minerals[a]);
                a++;
            }
            v.push_back(vv);
        }
        vector<string> vv;
        for(int i=0; i<minerals.size()%5; i++)
        {
            if(a>=(diac+ironc+stonec)*5)
            {
                i = minerals.size()%5;
                continue;
            }
            vv.push_back(minerals[a]);
            a++;
        }
        v.push_back(vv);
        V = v;
    }
    
    for(int i=0; i<V.size(); i++)
    {
        for(int j=0; j<V[i].size(); j++) cout << V[i][j] << " ";
        cout << endl;
    }
    sort(V.begin(), V.end(), cmp);
    for(int i=0; i<V.size(); i++)
    {
        for(int j=0; j<V[i].size(); j++) cout << V[i][j] << " ";
        cout << endl;
    }
    int piro = 0;
    for(int i=0; i<V.size(); i++)
    {
        if(diac>0)
        {
            diac--;
            for(auto&aa: V[i])
            {
                piro++;
            }
        }else if(ironc>0)
        {
            ironc--;
            for(auto&aa: V[i])
            {
                if(aa=="diamond") piro+=5;
                else piro++;
            }
        }else if(stonec>0)
        {
            stonec--;
            for(auto&aa: V[i])
            {
                if(aa=="diamond") piro+=25;
                else if(aa=="iron") piro+=5;
                else piro++;
            }
        }
    }
    answer = piro;
    return answer;
}