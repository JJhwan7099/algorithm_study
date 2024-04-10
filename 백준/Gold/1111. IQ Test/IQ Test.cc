#include <iostream>
#include <map>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int num[52];
map<int,int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,N) cin >> num[i];
    if(N==1){
        cout << "A";
        return 0;
    }else if(N==2){
        if(num[1]==num[2]) cout << num[1];
        else cout << "A";
        return 0;
    }else{
        bool bb = true;
        FOR(i,N-1) if(num[i]!=num[i+1]) bb = false;
        if(bb){
            cout << num[1];
            return 0;
        }
        int a,b;
        if(num[1]-num[2]!=0)
        {
            a = (num[2]-num[3])/(num[1]-num[2]);
            b = num[2]-num[1]*a;
        }
        FOR(i,N){
            if(i==N){
                cnt[num[i]*a+b]++;
                if(cnt.size()>1){
                    cout << "A";
                    return 0;
                }
                break;
            }
            if(num[i]*a+b==num[i+1]) continue;
            else break;
        }
    }
    if(cnt.size()==1) cout << cnt.begin()->first;
    else if(cnt.size()==0) cout << "B";
    return 0;
}