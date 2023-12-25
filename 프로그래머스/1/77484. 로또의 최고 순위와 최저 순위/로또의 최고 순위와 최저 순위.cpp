#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    unordered_map<int,int> dangchum;
    for(auto&a:win_nums)dangchum[a] = 1;
    int zerocnt=0;
    int already=0;
    for(auto&a:lottos)
    {
        if(a==0) zerocnt++;
        else if(dangchum[a]==1)already++;
    }
    int a = abs(already+zerocnt-7);
    if(a>6) a=6;
    int b = abs(already-7);
    if(b>6) b=6;
    return {a,b};
}