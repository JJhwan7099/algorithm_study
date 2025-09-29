#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int num[10000];
int T;
void findPrimeNum() {
    num[1] = 1;
    num[2] = 0;
    for(int i=2; i<=9999; i++) {
        if(num[i]==0) {
            for(int j=i*2; j<=9999; j+=i) {
                num[j] = 1;
            }
        }
    }
}
int bfs(string start, string end) {
    unordered_map<string, int> um;
    um[start] = 1;
    queue<pair<string,int>> q;
    q.push({start,0});
    while(!q.empty()) {
        string currentNum = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(currentNum==end) return depth;
        for(int i=0; i<4; i++) {
            string tempNum = currentNum;
            for(int j=0; j<10; j++) {
                if(i==0 && j==0) continue;
                else if(currentNum[i]==j-'0') continue;
                tempNum[i] = j+'0';
                int index = stoi(tempNum);
                if(num[index]==0 && um.find(tempNum)==um.end()) {
                    q.push({tempNum,depth+1});
                    um[tempNum] = 1;
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    findPrimeNum();
    cin >> T;
    while(T--) {
        int start, end;
        cin >> start >> end;
        int result = bfs(to_string(start),to_string(end));
        if(result==-1) cout << "Impossible\n";
        else cout << result << '\n';
    }
    return 0;
}