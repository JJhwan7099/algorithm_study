#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
string arr[20001];
unordered_map<string,int> um;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) {
        cin >> arr[i];
        unordered_map<string,int> subum;
        for(int j=0; j<arr[i].size(); j++) {
            string s = "";
            for(int k=j; k<arr[i].size(); k++) {
                s+=arr[i][k];
                if(subum[s]!=1) {
                    um[s]++;
                    subum[s]=1;
                }
            }
        }
    }
    int result = 0;
    for(int i=1; i<=N; i++) {
        if(um[arr[i]]-1>0) {
            result+=um[arr[i]]-1;
        }
    }
    cout << result;
    return 0;
}