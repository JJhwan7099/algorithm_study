#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int stat[21][21];
stack<int> teamA;
stack<int> teamB;
map<int,int> teamCheck;
int ans=-1;
int stat_diff() {
    vector<int> v1,v2;
    stack<int> s1=teamA;
    stack<int> s2=teamB;
    int scoreA=0;
    int scoreB=0;
    while(!s1.empty()) {
        for(auto&a: v1) {
            scoreA+=stat[a][s1.top()];
            scoreA+=stat[s1.top()][a];
        }
        v1.push_back(s1.top());
        s1.pop();
    }   
    while(!s2.empty()) {
        for(auto&a: v2) {
            scoreB+=stat[a][s2.top()];
            scoreB+=stat[s2.top()][a];
        }
        v2.push_back(s2.top());
        s2.pop();
    }
    return abs(scoreA-scoreB);
}
void btk(int n) {
    if(teamA.size()==N/2) {
        while(!teamB.empty()) teamB.pop();
        FOR(i,N) if(teamCheck[i]!=1) teamB.push(i);
        int gap = stat_diff();
        if(ans==-1||ans>gap) {
            ans=gap;
        }
        return;
    }
    for(int i=n+1; i<=N; i++) {
        if(teamA.size()<N/2){
            teamA.push(i);
            teamCheck[i]=1;
            btk(i);
            teamA.pop();
            teamCheck[i]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N)FOR(j,N) cin >> stat[i][j];
    btk(0);
    cout << ans;
    return 0;
}