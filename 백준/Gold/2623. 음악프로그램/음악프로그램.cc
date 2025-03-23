#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
vector<int> seqSinger[1001];
set<int> countPrevSinger[1001];
vector<int> answer;
void topologicalSort(queue<int>& q) {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(int i=0; i<seqSinger[cur].size(); i++) {
            auto it = countPrevSinger[seqSinger[cur][i]].find(cur);
            if(it!=countPrevSinger[seqSinger[cur][i]].end()) {
                countPrevSinger[seqSinger[cur][i]].erase(it);
                if(countPrevSinger[seqSinger[cur][i]].size()==0) q.push(seqSinger[cur][i]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    FOR(i,M) {
        int n; cin >> n;
        int prevSinger = 0;
        int nextSinger = 0;
        FOR(i,n) {
            cin >> nextSinger;
            if(prevSinger != 0){
                seqSinger[prevSinger].push_back(nextSinger);
                countPrevSinger[nextSinger].insert(prevSinger);
            }    
            prevSinger = nextSinger;
        }
    }
    queue<int> q;
    FOR(i,N) if(countPrevSinger[i].size()==0) q.push(i);
    topologicalSort(q);
    if(answer.size()==N) {
        for(auto& a: answer) cout << a << '\n';
    }
    else cout << 0;
    return 0;
}