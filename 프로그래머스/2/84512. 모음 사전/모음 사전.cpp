#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(string word) {
    map<int,vector<string>> m1;
    m1[1].push_back("A"); m1[1].push_back("E"); m1[1].push_back("I"); m1[1].push_back("O"); m1[1].push_back("U");
    for(int i=2; i<=5; i++)for(auto&a:m1[i-1]) {m1[i].push_back(a+"A"); m1[i].push_back(a+"E"); m1[i].push_back(a+"I"); m1[i].push_back(a+"O"); m1[i].push_back(a+"U");}
    map<string,int> m2;
    for(auto&a:m1)for(auto&b:a.second)m2[b]=0;
    int c = 1;
    for(auto&a:m2) {a.second = c; c++;}
    return m2[word];
}