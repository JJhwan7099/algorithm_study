#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,R,Q;
int visited[100001];
vector<int> graph[100001];
vector<int> tree[100001];
int childNodes[100001];
int countChildNodes(int n) {
    childNodes[n] = 1;
    for(int i=0; i<tree[n].size(); i++) {
        childNodes[n] += countChildNodes(tree[n][i]);
    }
    return childNodes[n];
}
void makeTree(int n) {
    visited[n] = 1;
    for(int i=0; i<graph[n].size(); i++) {
        if(visited[graph[n][i]] == 0) {
            makeTree(graph[n][i]);
            tree[n].push_back(graph[n][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> R >> Q;
    FOR(i,N-1) {
        int U,V; cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    makeTree(R);
    countChildNodes(R);
    FOR(i,Q) {
        int U; cin >> U;
        cout << childNodes[U] << '\n';
    }
    return 0;
}