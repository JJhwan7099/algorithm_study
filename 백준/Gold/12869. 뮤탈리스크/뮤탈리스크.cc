#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

map<int,int> m;
vector<string> combs;
int vis[4];
int N;
vector<int> hp;
map<string,int> vism;
void makeComb(int cnt) {
    if(cnt==hp.size()) {
        string s="";
        for(auto&a:m) {
            s+=to_string(a.second);
        }
        combs.push_back(s);
        return;
    }else {
        for(int i=0; i<hp.size(); i++) {
            if(vis[i]!=1) {
                vis[i]=1;
                m[cnt]=i;
                makeComb(cnt+1);
                m.erase(cnt);
                vis[i]=0;
            }
        }
    }
}

void bfs() {
    queue<pair<vector<int>,int>> q;
    q.push({hp,0});
    while(!q.empty()) {
        vector<int> hpv = q.front().first;
        int cnt = q.front().second;
        q.pop();
        bool b = true;
        for(auto&a: hpv) {
            if(a!=0) b=false;
        }
        if(b) {
            cout << cnt;
            return;
        }
        for(auto&s:combs) {
            vector<int> hpvv = hpv;
            string str = "";
            for(int i=0; i<s.length(); i++) {
                hpvv[s[i]-'0']-=9/pow(3,i);
                if(hpvv[s[i]-'0']<0) hpvv[s[i]-'0']=0;
                str+=to_string(hpvv[s[i]-'0'])+" ";
            }
            if(vism[str]==0 || vism[str]>cnt) {
                q.push({hpvv,cnt+1});
                vism[str]=cnt;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        int h; cin >> h;
        hp.push_back(h);
    }
    makeComb(0);
    bfs();
    return 0;
}