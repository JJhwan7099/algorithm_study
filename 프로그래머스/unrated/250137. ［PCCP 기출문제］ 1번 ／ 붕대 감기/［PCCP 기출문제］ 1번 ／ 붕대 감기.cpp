#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int ht = bandage[0];
    int hpup = bandage[1];
    int bonushp = bandage[2];
    int hp = health;
    unordered_map<int,int> m;
    int cnt = attacks.size();
    for(auto&a : attacks)
    {
        m[a[0]] = a[1];
    }
    int s = 0;
    int htime = 0;
    while(true)
    {
        s++;
        if(m.find(s)!=m.end())
        {
            cnt--;
            htime=0;
            hp-=m[s];
            if(hp<=0)
            {
                answer = -1;
                break;
            }else if(cnt==0) 
            {
                answer = hp;
                break;
            }
        }
        else
        {
            htime++;
            if(hp<health)
            {
                hp+=hpup;
            }
            if(htime==ht)
            {
                hp+=bonushp;
                htime=0;
            }
            if(hp>health) hp = health;
        }
        cout << s << " : " << hp << " " << htime << " " << ht << endl;
    }
    return answer;
}