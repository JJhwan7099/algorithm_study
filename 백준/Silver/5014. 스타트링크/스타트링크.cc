#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int cnt[1000001]={0, };
int main() {
    int F, S, G, U, D;
    cin>>F>>S>>G>>U>>D;
    queue<int>q;
    q.push(S);
    while(!q.empty()) {
        int k=q.front();
        q.pop();
        if(k+U<=F && k+U != S) {
            if(cnt[k+U]==0) {
                cnt[k+U]=cnt[k]+1;
                q.push(k+U);
            }
        }
        if(k-D>=1 && k-D != S) {
            if(cnt[k-D]==0) {
                cnt[k-D]=cnt[k]+1;
                q.push(k-D);
            }
        }
        if(k+U==G || k-D==G) {
            break;
        }
    }
    if(S == G){
        cout << "0";
        return 0;
    }
    if(cnt[G]!=0) {
        cout<<cnt[G];
    }
    else {
        cout<<"use the stairs";
    }
}