#include <iostream>
#include <map>
#include <deque>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
map<pair<int,int>,int> apple;
map<int, pair<int,int> > dir;
map<int,char> m;
int N;
int cd = 0;
int cx = 1; int cy = 1;
deque<pair<int,int> > body;
map<pair<int,int>,int> bodym;
int ans = 0;
void start(int sec)
{
    if(m.find(sec)!=m.end())
    {
        if(m[sec]=='D') cd++;
        else if(m[sec]=='L') cd+=3;
        cd%=4;
    }
    cx += dir[cd].first;
    cy += dir[cd].second;
    sec++;
    if(bodym[make_pair(cx,cy)]==1){
        ans = sec;
        return;
    }else if(cx<1||cy<1||cx>N||cy>N){
        ans = sec;
        return;
    }else{
        body.push_front(make_pair(cx,cy));
        bodym[make_pair(cx,cy)]=1;
        if(apple[make_pair(cx,cy)]==1)
        {
            apple[make_pair(cx,cy)] = 0;
        }else{
            bodym[body.back()]=0;
            body.pop_back();
        }
        start(sec);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int K; cin >> K;
    FOR(i,K)
    {
        int x,y; cin >> x >> y;
        apple[make_pair(x,y)]=1;
    }
    dir[0]=make_pair(0,1); dir[1]=make_pair(1,0); dir[2]=make_pair(0,-1); dir[3]=make_pair(-1,0);
    int L; cin >> L;
    FOR(i,L)
    {
        int s; char d; cin >> s >> d;
        m[s] = d;
    }
    body.push_back(make_pair(1,1));
    bodym[make_pair(1,1)]=1;
    start(0);
    cout << ans;
    return 0;
}