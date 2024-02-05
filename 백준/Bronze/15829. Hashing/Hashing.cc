#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int L;
int main() {
    cin >> L;
    unsigned long r = 1;
    unsigned long val = 0;
    string s;
    cin >> s;
    FOR(i,s.length())
    {
        int h = (s[i-1]-'a')+1;
        int hh = (h*r)%1234567891;
        val+=hh;
        r = (r*31)%1234567891;
    }
    val%=1234567891;
    cout << val;
    return 0;
}