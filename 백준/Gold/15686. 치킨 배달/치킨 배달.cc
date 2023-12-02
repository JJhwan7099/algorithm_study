#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,M;
int graph[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int,int>> gv;
vector<vector<pair<int,int>>> vv;
vector<pair<int,int>> hv;
int ans = -1;
void pick(vector<pair<int,int>> v,pair<int,int> p,int index)
{
    if(p.first!=-1&&p.second!=-1) v.push_back(p);
    if(v.size()==M){
        vv.push_back(v);
    }else{
        for(int i=index;i<gv.size();i++)
        {
            bool check = true;
            for(int j=0;j<v.size();j++)
            {
                if(gv[i]==v[j]) check = false;
            }
            if(check) pick(v,gv[i],i+1);
        }
    }
}
int main()
{
    cin >> N >> M;
    FOR(i,N)FOR(j,N) 
    {
        cin >> graph[i][j];
        if(graph[i][j]==2) 
        {
            gv.push_back({i,j});
        }else if(graph[i][j]==1){
            hv.push_back({i,j});
        }
    }
    vector<pair<int,int>> v;
    pick(v,{-1,-1},0);
    // for(auto&a : vv){for(auto&b: a) cout << b.first << ", " << b.second << endl; cout << "****\n";}
    for(auto&a:vv)
    {
        int cnt = 0;
        for(auto&h : hv)
        {
            int dis = 0;
            for(auto&c: a)
            {
                if(dis==0||dis>abs(h.first-c.first) + abs(h.second-c.second)) dis = abs(h.first-c.first) + abs(h.second-c.second);
            }
            cnt += dis;
        }
        if(ans==-1||ans>cnt) ans = cnt;
    }
    cout << ans;
}