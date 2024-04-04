#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
vector<string> car1(1001);
vector<string> car2(1001);
map<string,map<string,int>> m1; // value 에 뒤에 있던 차 저장
map<string,map<string,int>> m2; // value 에 앞에 있던 차 저장
int ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N){
        string a; cin >> a;
        car1[i]=a;
        for(int j=1; j<i; j++) m1[a][car1[j]]=1;
    }
    FOR(i,N){
        string a; cin >> a;
        car2[i]=a;
        for(int j=1; j<i; j++) m2[a][car2[j]]=1;
    }
    for(auto&a:m1)
    {
        bool bb = true;
        
        for(auto&b:a.second)
        {
            if(m2[a.first][b.first]!=1)
            {
                bb=false;
            }
        }
        if(!bb) ans++;
    }
    cout << ans;
    return 0;
}