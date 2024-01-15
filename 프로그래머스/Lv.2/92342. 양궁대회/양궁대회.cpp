#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> solution(int N, vector<int> info) {
    vector<int> answer;
    vector<pair<int,int>> apeach;
    for(int i=0; i<11; i++)
    {
        apeach.push_back({10-i, info[i]});
    }
    int max = -1;
    int mincnt1 = 0;
    int mincnt2 = 0;
    vector<int> v;
    queue<pair<pair<int,int>,pair<int,vector<int>>>> q;
    q.push({{0,0},{-1,v}});
    while(!q.empty())
    {
        int as = q.front().first.first;
        int ls = q.front().first.second;
        int cnt = q.front().second.first;
        vector<int> v1 = q.front().second.second;
        q.pop();
        
        int n = N;
        if(v1.size()>0) for(auto&a:v1) n -= a;
        if(cnt==10 && n >= 0)
        {
            if(ls-as>0 && (max==-1||max<=ls-as) && n==0)
            {
                int c1 = 0;
                int c2 = 0;
                for(int i=0; i<11; i++) if(v1[i]>0){ c1 = v1[i]; c2 = i;}
                if(max==-1 || max<ls-as)
                {
                    answer = v1;
                    max = ls-as;
                    mincnt1 = c1;
                    mincnt2 = c2;
                    continue;
                }
                else if(mincnt2<c2)
                {
                    answer = v1;
                    max = ls-as;
                    mincnt1 = c1;
                    mincnt2 = c2;
                    continue;
                }else if(mincnt2==c2 && mincnt1<c1)
                {
                    answer = v1;
                    max = ls-as;
                    mincnt1 = c1;
                    mincnt2 = c2;
                    continue;
                }
            }else continue;
        }else{
            if(apeach[cnt+1].second<n)
            {
                v1.push_back(apeach[cnt+1].second+1);
                q.push({{as,ls+apeach[cnt+1].first},{cnt+1,v1}});
                v1.pop_back();
                v1.push_back(0);
                if(apeach[cnt+1].second>0) q.push({{as+apeach[cnt+1].first,ls},{cnt+1,v1}});
                else q.push({{as,ls},{cnt+1,v1}});
                v1.pop_back();
            }else{
                v1.push_back(n);
                if(apeach[cnt+1].second>0) q.push({{as+apeach[cnt+1].first,ls},{cnt+1,v1}});
                v1.pop_back();
                v1.push_back(0);
                if(apeach[cnt+1].second>0) q.push({{as+apeach[cnt+1].first,ls},{cnt+1,v1}});
                else q.push({{as,ls},{cnt+1,v1}});
                v1.pop_back();
            }
        }
    }
    if(answer.size()>0) return answer;
    else return {-1};
}