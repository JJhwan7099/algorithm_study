#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[18];
vector<int> infoGlobal;
int ans = 0;
int n;

void dfs(int sheep, int wolf, vector<int>& candidates, vector<bool>& visited) {
    // 현재까지 확보한 양의 최대치 갱신
    ans = max(ans, sheep);

    // 모든 현재 후보들 중에서 다음 방문 노드를 골라 시도
    for (int i = 0; i < (int)candidates.size(); ++i) {
        int node = candidates[i];
        // 방문하면 늑대/양 수 업데이트
        int nsheep = sheep;
        int nwolf = wolf;
        if (infoGlobal[node] == 0) nsheep++;
        else nwolf++;

        // 만약 늑대가 양 이상이면 이 경로는 실패
        if (nwolf >= nsheep) continue;

        // 다음 후보 목록 만들기 (현재 후보에서 node를 제거하고 node의 자식들을 추가)
        vector<int> nextCandidates = candidates;
        nextCandidates.erase(nextCandidates.begin() + i);
        for (int c : tree[node]) {
            if (!visited[c]) nextCandidates.push_back(c);
        }

        // 방문 마킹
        visited[node] = true;
        dfs(nsheep, nwolf, nextCandidates, visited);
        visited[node] = false;
        // 다음 반복에서 다른 후보들 시도
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    infoGlobal = info;
    n = info.size();
    ans = 0;
    for (int i = 0; i < 18; ++i) tree[i].clear();

    for (auto &e : edges) {
        int parent = e[0], child = e[1];
        tree[parent].push_back(child);
    }

    // 초기 상태: 루트(0)는 항상 양(문제 보장). 0은 방문 처리, 후보는 0의 자식들.
    vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> candidates;
    for (int c : tree[0]) candidates.push_back(c);

    // 시작할 때 양 1, 늑대 0
    dfs(1, 0, candidates, visited);

    return ans;
}
