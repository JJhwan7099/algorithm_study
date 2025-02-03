#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
string s,t,reverseT="";
int result = 0;
int countA=0, countB=0;
string addA(string str) {
    str+='A';
    return str;
}
string addBAndReverse(string str) {
    str+='B';
    string ss = "";
    for(int i=str.length()-1; i>=0; i--) {
        ss+=str[i];
    }
    return ss;
}
void btk(string ss, int tempCountA, int tempCountB) {
    if(ss==t) {
        result = 1;
        return;
    }
    else if(result!=1 && ss.length()<t.length()) {
        if(tempCountA<countA) {
            string s1 = addA(ss);
            int finds1 = t.find(s1);
            int finds1_reverse = reverseT.find(s1);
            if(finds1!=string::npos || finds1_reverse!=string::npos) btk(s1, tempCountA+1, tempCountB);
        }
        if(tempCountB<countB) {
            string s2 = addBAndReverse(ss);
            int finds2 = t.find(s2);
            int finds2_reverse = reverseT.find(s2);
            if(finds2!=string::npos || finds2_reverse!=string::npos) btk(s2, tempCountA, tempCountB+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    for(int i=0; i<t.length(); i++) {
        if(t[i]=='A') countA++;
        else countB++;
    }
    int tempCountA=0, tempCountB=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='A') tempCountA++;
        else tempCountB++;
    }
    for(int i=t.length()-1; i>=0; i--) {
        reverseT+=t[i];
    }

    btk(s,tempCountA,tempCountB);
    cout << result;
    return 0;
}