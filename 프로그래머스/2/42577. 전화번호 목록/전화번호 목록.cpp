#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> m;
    for(auto&a:phone_book) m[a] = 1;
    for(auto&a:phone_book)
    {
        string s="";
        for(int i=0;i<a.length()-1;i++)
        {
            s+=a[i];
            if(m[s]==1) return false;
        }
    }
    return answer;
}