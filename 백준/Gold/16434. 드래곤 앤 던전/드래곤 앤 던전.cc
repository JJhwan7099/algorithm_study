#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
long long N, Atk;
struct Room {
    long long t,a,h;
};
Room room[123457];
long long start(long long Maxhp) {
    long long hp = Maxhp;
    long long atk = Atk;
    FOR(i,N) {
        Room rm = room[i];
        if(rm.t==1) {
            long long atk_cnt;
            if(rm.h%atk==0) atk_cnt=rm.h/atk;
            else atk_cnt=(rm.h/atk)+1;
            
            if(rm.a*(atk_cnt-1)<hp) hp -= rm.a*(atk_cnt-1);
            else return false;
        }
        else if(rm.t==2) {
            if(hp>Maxhp-rm.h) hp = Maxhp;
            else hp += rm.h;
            atk += rm.a;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Atk;
    FOR(i,N) {
        cin >> room[i].t >> room[i].a >> room[i].h;
    }
    //binary_search
    long long s = 1;
    long long e = 1.23456e17+1;
    long long mid;
    long long result = 1.23456e17+1;
    while(s<=e) {
        mid = (s+e)/2;
        if(start(mid)) {
            result = min(result,mid);
            e = mid-1;
        }
        else s = mid+1;
    }
    cout << result;
    return 0;
}