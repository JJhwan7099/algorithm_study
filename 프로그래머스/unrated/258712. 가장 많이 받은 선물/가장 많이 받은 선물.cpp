#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,unordered_map<string,int>> gift;
    unordered_map<string,int> jisu;
    unordered_map<string,int> ans;
    for(auto&a: gifts)
    {
        bool b = true;
        string a1 = "";
        string b1 = "";
        int i = 0;
        while(i!=a.length())
        {
            if(b)
            {
                if(a[i]==' ')
                {
                    b = false;
                    i++;
                    continue;
                }
                a1+=a[i];
            }else{
                b1+=a[i];
            }
            i++;
        }
        jisu[a1]++;
        jisu[b1]--;
        gift[a1][b1]++;
    }
    for(auto&a: friends)for(auto&b: friends)
    {
        if(a==b) continue;
        else{
            if(gift[a][b]>gift[b][a]) ans[a]++;
            else if(gift[a][b]<gift[b][a]) ans[b]++;
            else{
                if(jisu[a]>jisu[b]) ans[a]++;
                else if(jisu[a]<jisu[b]) ans[b]++;
            }
        }
    }
    for(auto&a: ans) answer=max(answer,a.second);
    return answer/2;
}