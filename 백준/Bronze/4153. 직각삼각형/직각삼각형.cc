#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0) break;
        else{
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(),v.end());
            if(v[0]*v[0]+v[1]*v[1]==v[2]*v[2]) cout << "right\n";
            else cout << "wrong\n";
        }
    }
    return 0;
}