#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int L,C;
vector<char> vowel;
vector<char> consonant;
vector<vector<char>> vowelCombinations[6];
vector<vector<char>> consonantCombinations[16];
vector<string> passwords;
void makeVowelComb(int n,vector<char> comb) {
    if(comb.size() > 0) {
        // cout << comb.size() << endl;
        // for(auto&a: comb) cout << a << " ";
        // cout << endl;
        vowelCombinations[comb.size()].push_back(comb);
    }
    for(int i=n; i<vowel.size(); i++) {
        vector<char> nextComb = comb;
        nextComb.push_back(vowel[i]);
        makeVowelComb(i+1, nextComb);
    }
}
void makeConsonantComb(int n, vector<char> comb) {
    if(comb.size() > 0) {
        // cout << comb.size() << endl;
        // for(auto&a: comb) cout << a << " ";
        // cout << endl;
        consonantCombinations[comb.size()].push_back(comb);
    }
    for(int i=n; i<consonant.size(); i++) {
        vector<char> nextComb = comb;
        nextComb.push_back(consonant[i]);
        makeConsonantComb(i+1, nextComb);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> C;
    FOR(i,C) {
        char c; cin >> c;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            vowel.push_back(c);
        }
        else consonant.push_back(c);
    }
    vector<char> tmpVowelComb;
    vector<char> tmpConsonantComb;
    makeVowelComb(0,tmpVowelComb);
    makeConsonantComb(0,tmpConsonantComb);
    for(int i=1; i<=vowel.size(); i++) {
        if(L-i>=2) {
            for(auto&v1: vowelCombinations[i]) {
                for(auto&v2: consonantCombinations[L-i]) {
                    vector<char> password;
                    for(auto&c: v1) password.push_back(c);
                    for(auto&c: v2) password.push_back(c);
                    sort(password.begin(), password.end());
                    string s = "";
                    for(auto&p: password) s += p;
                    passwords.push_back(s);
                }
            }
        }
    }
    sort(passwords.begin(), passwords.end());
    for(auto&password: passwords) cout << password << '\n';
    return 0;
}