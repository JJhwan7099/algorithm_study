#include<iostream>
#include<queue>
#include<map>
using namespace std;
int N,K;
int memo[100100];
int main()
{
    cin >> N >> K;
    map<int,int> m;
    queue<pair<int,int>> q;
    q.push({N,0});
    m[N]=1;
    memo[N]=-1;
    while(!q.empty())
    {
        int s = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(s==K)
        {
            cout << cnt << '\n';
            int ss = K;
            vector<int> v;
            while(memo[ss]!=-1)
            {
                v.push_back(memo[ss]);
                ss = memo[ss];
            }
            for(int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
            cout << K << " ";
            return 0;
        }
        int move[3] = {s+1, s-1, s*2};
        for(int i=0; i<3; i++)
        {
            if(move[i]>=0 && move[i]<=100000 && m[move[i]]!=1)
            {
                m[move[i]]=1;
                memo[move[i]] = s;
                q.push({move[i],cnt+1});
            }
        }
    }
}