#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int N, K, W;
int buildTime[1001];
vector<int> buildSeq[1001];
int buildCount[1001];
int completeTime[1001];
void build(queue<pair<int,int>>& q) {
    while(!q.empty()) {
        int cur = q.front().first;
        int curTime = q.front().second;
        if(cur==W) {
            cout << curTime << '\n';
            return;
        }
        q.pop();
        for(int i=0; i<buildSeq[cur].size(); i++) {
            buildCount[buildSeq[cur][i]]--;
            completeTime[buildSeq[cur][i]] = max(completeTime[buildSeq[cur][i]], curTime + buildTime[buildSeq[cur][i]]);
            if(buildCount[buildSeq[cur][i]] == 0) {
                q.push({buildSeq[cur][i], completeTime[buildSeq[cur][i]]});
                buildCount[buildSeq[cur][i]] = -1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> K;
        FOR(i,N) {
            cin >> buildTime[i];
            buildCount[i] = 0;
            completeTime[i] = 0;
            buildSeq[i].clear();
        }
        FOR(i,K) {
            int first,second;
            cin >> first >> second;
            buildSeq[first].push_back(second);
            buildCount[second]++;
        }
        cin >> W;
        queue<pair<int,int>> q;
        FOR(i,N) {
            if(buildCount[i] == 0) {
                q.push({i,buildTime[i]});
                completeTime[i] = buildTime[i];
            }
        }
        build(q);
    }
    return 0;
}