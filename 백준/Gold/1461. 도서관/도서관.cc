#include<iostream>
#include<set>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M;
multiset<int> pset;
multiset<int,greater<int>> mset;
int main()
{
    cin >> N >> M;
    FOR(i,N)
    {
        int a; cin >> a;
        if(a>0) pset.insert(a);
        else mset.insert(a);
    }
    
    int pit;
    int mit;
    if(pset.size()==0) pit = 0;
    else pit = *prev(pset.end());
    if(mset.size()==0) mit = 0;
    else mit = *prev(mset.end());

    if(pit>abs(mit) || mset.size()==0)
    {
        int dis = 0;
        int cnt = 1;
        while(!mset.empty())
        {
            if(mset.size()==1)
            {
                dis += 2*abs(*mset.begin());
                mset.erase(mset.begin());
            }
            else if(cnt%M==0)
            {
                dis += 2 * abs(*prev(mset.end()));
                mset.erase(prev(mset.end()));
                cnt++;
            }else{
                mset.erase(prev(prev(mset.end())));
                cnt++;
            }
        }
        cnt = 1;
        while(!pset.empty())
        {
            int n = pset.size()%M;
            if(pset.size()<=M)
            {
                dis += *prev(pset.end());
                pset.clear();
            }
            else if(n!=0 && pset.size()>M)
            {
                for(int i=0; i<n; i++)
                {
                    if(i==n-1) dis += 2 * (*pset.begin());
                    pset.erase(pset.begin());
                }
            }else{
                for(int i=0; i<M; i++)
                {
                    if(i==M-1) dis += 2*(*pset.begin());
                    pset.erase(pset.begin());
                }
            }
        }
        cout << dis << endl;
    }else{
        int dis = 0;
        int cnt = 1;
        while(!pset.empty())
        {
            if(pset.size()==1)
            {
                dis += 2*abs(*pset.begin());
                pset.erase(pset.begin());
            }
            else if(cnt%M==0)
            {
                dis += 2 * (*prev(pset.end()));
                pset.erase(prev(pset.end()));
                cnt++;
            }else{
                pset.erase(prev(prev(pset.end())));
                cnt++;
            }
        }
        cnt = 1;
        while(!mset.empty())
        {
            int n = mset.size()%M;
            if(mset.size()<=M)
            {
                dis += abs(*prev(mset.end()));
                mset.clear();
            }
            else if(n!=0 && mset.size()>M)
            {
                for(int i=0; i<n; i++)
                {
                    if(i==n-1) dis += 2 * abs(*mset.begin());
                    mset.erase(mset.begin());
                }
            }else{
                for(int i=0; i<M; i++)
                {
                    if(i==M-1) dis += 2*abs(*mset.begin());
                    mset.erase(mset.begin());
                }
            }
        }
        cout << dis << endl;
    }
}