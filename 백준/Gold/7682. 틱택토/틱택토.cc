#include <iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) {
        string s; cin >> s;
        if(s=="end") break;
        else {
            int xcnt = 0;
            int ocnt = 0;
            int checkrulecnt=0;
            bool b = true;
            bool endcheck = false;
            for(int i=0; i<s.length(); i++) {
                if(s[i]=='O') ocnt++;
                else if(s[i]=='X') xcnt++;
            }
            if(xcnt<ocnt || abs(xcnt-ocnt)>1) {
                checkrulecnt++;
                b=false;
            }
            //가로 한줄씩 확인
            for(int i=0; i<=6; i+=3) {
                if(s[i]!='.' && s[i]==s[i+1] && s[i+1]==s[i+2]) {
                    if(s[i]=='X' && xcnt==ocnt) {
                        checkrulecnt++;
                        b=false;
                    }
                    else if(s[i]=='O' && xcnt!=ocnt) {
                        checkrulecnt++;
                        b=false;
                    }
                    else endcheck=true;
                }
            }
            //세로 한줄씩 확인
            for(int i=0; i<3; i++) {
                if(s[i]!='.' && s[i]==s[i+3] && s[i+3]==s[i+6]) {
                    if(s[i]=='X' && xcnt==ocnt) {
                        checkrulecnt++;
                        b=false;
                    }
                    else if(s[i]=='O' && xcnt!=ocnt) {
                        checkrulecnt++;
                        b=false;
                    }
                    else endcheck=true;
                }
            }
            //대각선 확인
            if(s[0]!='.' && s[0]!='.' && s[0]==s[4] && s[4]==s[8]) {
                if(s[0]=='X' && xcnt==ocnt) {
                    checkrulecnt++;
                    b=false;
                }
                else if(s[0]=='O' && xcnt!=ocnt) {
                    checkrulecnt++;
                    b=false;
                }
                else endcheck=true;
            }
            if(s[2]!='.' && s[2]==s[4] && s[4]==s[6]) {
                if(s[2]=='X' && xcnt==ocnt) {
                    checkrulecnt++;
                    b=false;
                }
                else if(s[2]=='O' && xcnt!=ocnt) {
                    checkrulecnt++;
                    b=false;
                }
                else endcheck=true;
            }
            if(xcnt+ocnt==9) endcheck=true;

            if(checkrulecnt==0 && b && endcheck) {
                cout << "valid\n";
            }
            else {
                cout << "invalid\n";
            }
        }
    }
    return 0;
}