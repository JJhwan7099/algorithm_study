#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<pair<int,pair<int,int>>> edges;
int parent[51];
int totLength = 0;
int find_parent(int n) {
    if(parent[n]==n) return n;
    return parent[n] = find_parent(parent[n]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        string s; cin >> s;
        for(int j=0; j<s.length(); j++) {
            if(s[j]=='0') continue;
            else if(isupper(s[j])) {
                edges.push_back({s[j]-38,{i,j+1}});
                totLength+=s[j]-38;
            }
            else if(islower(s[j])) {
                edges.push_back({s[j]-96,{i,j+1}});
                totLength+=s[j]-96;
            }
        }
    }
    FOR(i,N) parent[i] = i;
    sort(edges.begin(),edges.end());
    int result = 0;
    for(auto&a:edges) {
        int cost = a.first;
        int u = a.second.first;
        int v = a.second.second;
        int parentu = find_parent(u);
        int parentv = find_parent(v);
        if(parentu!=parentv) {
            parent[min(parentu,parentv)] = max(parentu,parentv);
            result += cost;
        }
    }
    int check = find_parent(1);
    FOR(i,N) if(find_parent(i)!=check) {
        cout << -1;
        return 0;
    }
    cout << totLength - result;
    return 0;
}