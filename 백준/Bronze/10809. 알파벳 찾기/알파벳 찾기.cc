#include <iostream>
using namespace std;

int answer[26];

int main() {
	string s;
	cin >> s;
	for(int i=0; i<26; i++) answer[i] = -1;
	for(int i=0; i<s.length(); i++) {
		int idx = s[i]-'a';
		if(answer[idx]==-1) answer[idx] = i;
	}
	
	for(int i=0; i<26; i++) cout << answer[i] << " ";
}