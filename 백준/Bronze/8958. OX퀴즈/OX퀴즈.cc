#include <iostream>
using namespace std;

int testcase;
int answer = 0;

int main() {
    cin >> testcase;
    for(int i=0; i<testcase; i++) {
        string str;
        cin >> str;
        
        int seq = 0;
        answer = 0;
        
        for(int index=0; index<str.length(); index++) {
            if(str[index]=='O') {
                seq++;
                answer += seq;
            }
            else seq = 0;
        }
        
        cout << answer << '\n';
    }
}