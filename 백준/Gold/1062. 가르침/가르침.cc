#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,K;
unordered_map<char,int> um1;
unordered_map<char,int> um2;
vector<string> v;
vector<unordered_map<char,int>> vv;
int ans=0;
int check(unordered_map<char,int> um1) {
    int cnt=0;
    for(auto&str: v) {
        bool b = true;
        for(int i=4; i<str.size()-4; i++) {
            if(um1.find(str[i])==um1.end()) {
                b=false;
                break;
            }
        }
        if(b) cnt++;
    }
    return cnt;
}
void btk(unordered_map<char,int>::iterator iter) {
    if(um1.size()==K) {
        ans = max(ans,check(um1));
        return;
    }
    for(auto it=iter; it!=um2.end(); it=next(it)) {
        if(um1.find(it->first)!=um1.end()) continue;
        else {
            um1[it->first]=1;
            if(um1.size()<=K) {
                btk(next(it));
            }
            um1.erase(it->first);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    um1['a']=1;
    um1['n']=1;
    um1['t']=1;
    um1['i']=1;
    um1['c']=1;
    FOR(i,N) {
        string s; cin >> s;
        for(int i=4; i<s.size()-4; i++) {
            if(um1.find(s[i])==um1.end())um2[s[i]]=1;
        }
        v.push_back(s);
    }
    if(um2.size()+um1.size()<=K) {
        for(auto&a: um2) {
            um1[a.first] = 1;
        }
        ans = check(um1);
    }
    else {
        btk(um2.begin());
    }
    cout << ans;
    return 0;
}