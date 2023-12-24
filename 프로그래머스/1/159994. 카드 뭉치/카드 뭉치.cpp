#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    queue<string> crd1;
    queue<string> crd2;
    for(auto&a:cards1) crd1.push(a);
    for(auto&a:cards2) crd2.push(a);
    for(auto&b:goal){
        string first = crd1.front();
        string second = crd2.front();
        if(b==first){
            crd1.pop();
        }
        else if(b==second)
        {
            crd2.pop();
        }else{
            answer="No";
            break;
        }
    }
    return answer;
}