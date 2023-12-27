#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
struct Hw{
    string name;
    int h,t;
};
bool cmp(vector<string>a, vector<string>b)
{
    string ah = ""; ah += a[1][0]; ah+=a[1][1];
    string bh = ""; bh += b[1][0]; bh+=b[1][1];
    string am = ""; am += a[1][3]; am+=a[1][4];
    string bm = ""; bm += b[1][3]; bm+=b[1][4];
    if(stoi(ah)!=stoi(bh)) return stoi(ah) < stoi(bh);
    else return stoi(am) < stoi(bm);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), cmp);
    stack<Hw> donot;
    stack<Hw> doing;
    for(int i=plans.size()-1;i>=0;i--)
    {
        vector<string> a = plans[i];
        Hw hw; hw.name = a[0]; hw.h = ((a[1][0]-'0')*10 + (a[1][1]-'0')) * 60 + (a[1][3]-'0')*10 + (a[1][4]-'0');
        hw.t = stoi(a[2]);
        donot.push(hw);
    }
    int time = donot.top().h;
    while(true)
    {
        cout << time << endl;
        cout << time/60 << ":" << time%60 << endl;
        //test
        // vector<Hw> v;
        // int s1 = donot.size();
        // for(int i=0; i<s1;i++)
        // {
        //     Hw h1 = donot.top();
        //     cout << h1.name << ":" << h1.t << "(" << h1.h/60 <<":"<<h1.h%60 << ")" << " ";
        //     donot.pop();
        //     v.push_back(h1);
        // }
        // for(int i=v.size()-1;i>=0;i--) donot.push(v[i]);
        // cout << endl;
        // v.clear();
        // int s2 = doing.size();
        // for(int i=0; i<s2;i++)
        // {
        //     Hw h1 = doing.top();
        //     cout << h1.name << ":" << h1.t << "(" << h1.h/60 <<":"<<h1.h%60 << ")" << " ";
        //     doing.pop();
        //     v.push_back(h1);
        // }
        // for(int i=v.size()-1;i>=0;i--) doing.push(v[i]);
        // cout << endl;
        //test end
        if(donot.empty()&&doing.empty())break;
        if((!donot.empty()&&doing.empty())||(!donot.empty()&&time==donot.top().h))
        {
            time = donot.top().h;
            string n = donot.top().name;
            int h = time;
            int t = donot.top().t;
            h += t;
            donot.pop();
            if(!donot.empty()&&h>donot.top().h)
            {
                t = h-donot.top().h;
                time = donot.top().h;
                Hw hh; hh.name = n; hh.h = time; hh.t = t;
                doing.push(hh);
            }else{
                time = time + t;
                answer.push_back(n);
            }
        }
        else if(!doing.empty()){
            string n = doing.top().name;
            int h = time;
            int t = doing.top().t;
            h += t;//끝나는 시간
            doing.pop();
            if(!donot.empty()&&h>donot.top().h)
            {
                t = h-donot.top().h;
                time = donot.top().h;
                Hw hh; hh.name = n; hh.h = time; hh.t = t;
                doing.push(hh);
            }else{
                time = time+t;
                answer.push_back(n);
            }
        }
    }
    return answer;
}